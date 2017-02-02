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
