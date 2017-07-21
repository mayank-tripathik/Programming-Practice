#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int count_partial;
typedef struct node{
    bool is_word;
    node *child[26];
    int count=0;
    int word=0;
} node;

void insert(string word, node *trie){
    node *root=trie;
    int i=0;
    while(word[i]!='\0'){
        int in=word[i]-97;
        root->word++;
        if(root->child[in]==NULL)
            root->child[in]=new node();
        root=root->child[in];
        i++;
    }
    if(root->is_word==true){
            root->count++;
            //cout<<"word already there , count:"<<root->count<<endl;
    }
    else{
        root->is_word=true;
        root->count=1;
    }
    
}

bool search_word(string word,node *trie){
    node *root=trie;
    int i=0;
    while(word[i]!='\0'){
        int in=word[i]-97;
        if(root->child[in]!=NULL){
            root=root->child[in];
            i++;
        }
        else
            break;       
    }
    if(root->is_word==true && word[i]=='\0')
        return true;
    else
        return false;
}

void print_prefix(string word, node *root){
    if(root==NULL)
        return;
    else{
       if(root->is_word==true){
           //cout<<word<<endl;
           count_partial++;
       }
           
       for(int i=0;i<26;i++){
               if(root->child[i]!=NULL){
                       char c=i+'a';
                       word=word+c;
                       print_prefix(word,root->child[i]);
               }
       }
           
    }
    //return count_partial;
    
}

void search_prefix(string prefix,node *trie){
    node *root=trie;
    int i=0;
    string word="";
    while(prefix[i]!='\0'){
        //cout<<prefix[i]<<endl;
        int in=prefix[i]-97;
        if(root->child[in]!=NULL){
            root=root->child[in];
            word=word+prefix[i];
            i++;
            //cout<<"blah"<<endl;
        }
        else
            break;       
    }
    if(prefix[i]=='\0'){
        int answer=root->word;
        if(root->is_word==true)
            answer++;
        cout<<answer<<endl;
        //print_prefix(word,root);       
    }
    else
        cout<<"0"<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin>>q;
    string word,query;
    node *trie=new node();
    while(q--)
    {
        string query;
        cin>>query;
        if(query=="add"){
            cin>>word;
            insert(word,trie);
        }
        else if(query=="find"){
            cin>>word;
            //count_partial=0;
            search_prefix(word,trie);
            //cout<<count_partial<<endl;
        }
    }
    return 0;
}

/***************** Better***************/

#include<bits/stdc++.h>
using namespace std;
#define CHARSET 256

// Declaring class trie because trie is made a friend class of TrieNode class so need to be
// declared before TrieNode class
class Trie;

// Class for the node of trie data structure. Each node has a bool variable isWord that checks
// if word ending at this node is a valid dictionary word. Each node has CHARSET number of childrens
// pointing to all the next letters possible from this node. CHARSET is set as 256, the number of 
// ASCII characters possible. They are intialized to appropriate values using characters. Note that
// Class trie is made friend of this class as we want only Trie class to access all the members of
// TrieNode class
class TrieNode{
	bool isWord;
	TrieNode* children[CHARSET];
	TrieNode(){
		isWord=false;
		for(int i=0;i<CHARSET;i++)
			children[i]=NULL;
	}
	friend Trie;
};

// Class for a Trie tree structure. Each trie is represented by a root node.
class Trie{
private:
	TrieNode *root;
public:
	Trie(){
		root = new TrieNode();
	}
	// takes a word and insert it into the trie appropriately. It takes each letter of
	// word one by one, sees if corresponding children to that letter exists or not
	// If exists, it discards the current letter and then moves onto next letter and repeats the same process. 
	// If not exists, it consumes the cuurrent letter by creating the child node corresponding to it
	// and then moves onto next letter and repeats the same process. After all letters are consumed
	// it sets isWord value of final node as true to signify that word formed at this node is a valid
	// dictionary word
	void insertWord(const string &word){
		TrieNode* traverse = root;
		for(int i=0;i<word.size();i++){
			char childIndex = word[i];
			if(traverse->children[childIndex] == NULL)
				traverse->children[childIndex] = new TrieNode();
			traverse = traverse->children[childIndex];
		}
		traverse->isWord = true;
	}

	// Search is very similar to insert, except that if child node corresponding to current letter
	// doesn't exists it means word is not present and it immediately returns false. Otherwise if all
	// letters of word are consumed and word is inedeed a valid word of dictionary(can be checked by isWord
	// value of a node) it returns true otherwise false
	bool searchWord(const string &word){
		TrieNode* traverse = root;
		int i;
		for(i=0;i<word.size();i++){
			char childIndex = word[i];
			if(traverse->children[childIndex] == NULL)
				return false;
			traverse = traverse->children[childIndex];
		}
		if(traverse->isWord && i==word.size())
			return true;
		else
			return false;
	}

	// This word recursively fills the suggestion array of words by traversing as low
	// as possible for each node, starting from the prefix. For example, if prefix is "ma", then
	// it checks for all letters possible after "ma", for each letter possible, it further goes
	// as deep as possible. For the same reason, suggestions we get are alphabetically sorted
	void fillSuggestions(string prefix , TrieNode* traverse, vector<string> &suggestedWords){
		if(traverse->isWord){
			suggestedWords.push_back(prefix);
		}
		for(int i=0;i<CHARSET;i++){
			if(traverse->children[i]!=NULL){
				char c = i;
				string temp=prefix;
				fillSuggestions(prefix+c,traverse->children[i],suggestedWords);
			}
		}
	}

	// prints suggestions
	void printSuggestion(int top, const string &word,vector<string> &suggestedWords){
		if(suggestedWords.size()==0)
			cout<<"No suggestions for "<<word<<"\n";
		else
			cout<<"Top suggestions for "<<word<<" are:\n";
		for(int i=0;i<suggestedWords.size() && top--;i++){
			cout<<suggestedWords[i]<<endl;
		}
	}
	
	// Autocomplete takes a word and suggest all words starting from the specified word
	// as prefix. Top suggestions can be shown instead of all suggestions. Here we are suggesting
	// top 10 letters alphabetically
	void autoComplete(const string &word){
		TrieNode* traverse = root;
		int i;
		for(i=0;i<word.size();i++){
			char childIndex = word[i];
			if(traverse->children[childIndex] == NULL)
				break;
			traverse = traverse->children[childIndex];
		}
		string prefix = word.substr(0,i);
		vector<string> suggestedWords;
		fillSuggestions(prefix,traverse,suggestedWords);
		printSuggestion(10,word,suggestedWords);
	}

	void phoneBookSearch(const string &contact){
		TrieNode* traverse = root;
		string prefix="";
		for(int i=0;i<contact.size();i++){
			prefix+=contact[i];
			char childIndex = contact[i];
			if(traverse->children[childIndex] == NULL){
				cout<<"No more suggestion available\n";
				break;
			}
			cout<<"Suggestions after "<<prefix<<endl;
			traverse = traverse->children[childIndex];
			vector<string> suggestedWords;
			fillSuggestions(prefix,traverse,suggestedWords);
			printSuggestion(10,prefix,suggestedWords);	
		}
	}
};

// To run this program compile it first and then run it by taking dictionary of words/contacts as input
int main(){
	Trie dict;
	string word;
	while(cin>>word){
		dict.insertWord(word);
	}
	cout<<dict.searchWord("lola")<<endl;
	dict.autoComplete("an");
	dict.phoneBookSearch("yamp");
}
