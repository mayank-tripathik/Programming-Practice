/*
 * Complexity: O(m*n) where m and n are the length of text and pattern respectively.
 */

#include <vector>
#include <iostream>
using namespace std;

void string_matching_brute_force(string pattern, string text){
    vector<int> matches;
    for(int i=0;i<text.size();i++){
        bool flag=true;
        int k=i;
        for(int j=0;j<pattern.size();j++){
            if(pattern[j]!=text[k]){
               flag=false;
               break; 
            }
            else
                k++;
        }
        if(flag)
            matches.push_back(i);
    }
    if(matches.size()>0){
        cout<<"Match Occurs at index : ";
        for(int i=0;i<matches.size();i++){
            cout<<matches[i]<<" ";
        }
    }
    else
        cout<<"No Match Occurs!";
   
}

int main() {
    string text,pattern;
    cin>>text>>pattern;
    string_matching_brute_force(pattern,text);
}
