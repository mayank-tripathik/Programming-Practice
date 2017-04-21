/*
 * Based on LPS : Longest Prefix Suffix array which is precomputed in O(n) time where n is pattern size.
 * Complexity : O(m+n), where m is text size.
 */

#include <vector>
#include <iostream>
using namespace std;

vector<int> construct_LPS(string pattern){
    vector<int> LPS(pattern.size());
    int j=0,i=1;
    while(i<pattern.size())
    {
        if(pattern[i]==pattern[j]){
            LPS[i]=j+1;
            i++;
            j++;
        }
            
        else
        {
            if(j==0)
                LPS[i]=0,i++;
            else
                j=LPS[j-1];
            
        }
    }
    return LPS;
    
}
void StringMatchingKMP(string pattern, string text){
    vector<int> LPS = construct_LPS(pattern);
    int i=0,j=0;
    while(i<text.size()){
        if(pattern[j]!=text[i])
                if(j==0)
                    i++;
                else
                    j=LPS[j-1];
        else
            j++,i++;
        if(j==pattern.size()){
            cout<<"Match exists at index:"<<i-pattern.size()<<endl;
            j=LPS[j-1];
        }           
    }
}

int main() {
    string text,pattern;
    cin>>text>>pattern;
    StringMatchingKMP(pattern,text);
}
