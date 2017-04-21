/*
 * Rabin Karp Algorithm for String Matching
 * Improvement over Naive algorithm by using hash function to reduce compariosn of every window
 * Uses rolling hash for efficient computation
 * Complexity: O(n+m) on average but worst is  O(n*m), occurs when pattern and each substring has same hash value
 * Example of worst case is: Text-"AAAAAAAA", Pattern-"AAA"
 */ 

#include <vector>
#include <iostream>
using namespace std;

//Because there are 256 ASCII Characters
#define base 256

//Preferably a big prime
#define mod 101

//Checks if a pattern matches with text but only if their corresponding hash matches
bool check_match(string pattern, string text, int shift){
    for(int i=0;i<pattern.size();i++){
        if(pattern[i]!=text[i+shift])
            return false;
    }
    return true;
}

void StringMatchingRabinKarp(string pattern, string text){
    int N=text.size();
    int M=pattern.size();
    int pattern_hash=0,text_hash=0;
    int power=1;
    
    //Calculate base to the power M-1, used in rolling hash
    for (int i = 0; i < M-1; i++)
        power = (power*base)%mod;
    
    //Initial calculation of pattern hash and same size of substring in text
    for(int i=0;i<pattern.size();i++){
        pattern_hash=(pattern_hash*base+pattern[i])%mod;
        text_hash=(text_hash*base+text[i])%mod;
    }
    
    // Calculating hash of each next substring of length M in text
    // and matches with pattern only if their hash number are same
    for(int i=0;i<=N-M;i++){
        if(text_hash==pattern_hash){
            bool match=check_match(pattern,text,i);
            if(match)
                cout<<"Pattern match at index:"<<i<<endl;
        }
        text_hash=((text_hash-text[i]*power)*base+text[i+M])%mod;
        if (text_hash < 0)
            text_hash = (text_hash + mod);
    }
}

int main() {
    string text,pattern;
    cin>>text>>pattern;
    StringMatchingRabinKarp(pattern,text);
}
