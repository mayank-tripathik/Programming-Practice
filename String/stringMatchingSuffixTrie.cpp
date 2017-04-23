/*
 * Idea : Every pattern that is present in text(i.e substring) must be a prefix of one of all possible suffixes. 
 * So if we build a Trie of all suffixes, we can find the pattern in O(m) time where m is pattern length.
 * All suffixes of text is inserted in SuffixTrie. This allows us to do efficient pattern search later.
 * Complexity: O(m+k) where m is length of the pattern and k is the number of occurrences of pattern in text.
 * Good when text doesn't change often and queries are large
 */

#include<bits/stdc++.h>
using namespace std;

#define SHIFT 97
#define ALPHABET_SIZE 26
class node{
public:
	bool isWord;
	node *child[ALPHABET_SIZE];
	int wordCount;
	int startIndex;
public:
	node()
	{
		isWord=false;
		wordCount=0;
		startIndex=-1;
		for(int i=0;i<ALPHABET_SIZE;i++)
			child[i]=NULL;
	}

};

class suffixTrie{
private:
	node *root;
public:
	suffixTrie(){
		root=new node();
	}
	void insertWord(string word, int startIndex){
		node *treeRoot=root;
		for(int i=0;i<word.size();i++){
			int index=word[i]-SHIFT;
			if(treeRoot->child[index]==NULL)
				treeRoot->child[index]=new node();
			treeRoot=treeRoot->child[index];
		}
		if(treeRoot->isWord)
			treeRoot->wordCount++;
		else
		{
			treeRoot->isWord=true;
			treeRoot->wordCount=1;
			treeRoot->startIndex=startIndex;
		}
	}
	node* searchWord(string word){
		node *treeRoot=root;
		int i;
		for(i=0;i<word.size();i++){
			int index=word[i]-SHIFT;
			if(treeRoot->child[index]!=NULL)
				treeRoot=treeRoot->child[index];
			else
			{
				return NULL;
			}				
		}
		if(i==word.size())
			return treeRoot;
		else
			return NULL;
	}
	void findOccurences(node *startRoot){
		if(startRoot->isWord)
			cout<<startRoot->startIndex<<" ";
		for(int i=0;i<ALPHABET_SIZE;i++){
			if(startRoot->child[i]!=NULL)
				findOccurences(startRoot->child[i]);
		}
	}
};

int main(){
	suffixTrie Tree;
	string text;
	cin>>text;
	for(int i=0;i<text.size();i++){
		string suffix=text.substr(i);
		Tree.insertWord(suffix,i);	
	}
	int query;
	cin>>query;
	while(query--){
		string pattern;
		cin>>pattern;
		node *startRoot=Tree.searchWord(pattern);
		if(startRoot!=NULL){
			cout<<"Pattern : "<<pattern<<" , Pattern found at Index : ";
			Tree.findOccurences(startRoot);
			cout<<endl;
		}
		else
			cout<<"Pattern: "<<pattern<<" , Pattern not exists!\n";
	}
}
