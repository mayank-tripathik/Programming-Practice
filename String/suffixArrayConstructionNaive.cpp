/*
 * Suffix Array : A suffix array is a sorted array of all suffixes of a given string. 
 * A suffix array can be constructed from Suffix tree by doing a DFS traversal of the suffix tree. 
 * Naive Approach: All suffixes are generated and sorted with their original index stored
 * Complexity : O(nlogn) for sorting but since here string is sorted, O((n^2)logn)
 * Much optimal algorithms exist for suffix array construction
 */

#include<bits/stdc++.h>
using namespace std;
#define P pair<int,string>

void print(vector<int> &vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

bool compare(const P &l, const P &r){
	string str1=l.second;
	string str2=r.second;
	if(str1.compare(str2)<0)
		return true;
	else
		return false;
}

vector<int> constructSuffixArray(string text){
	vector<P> suffixes;
	vector<int> suffixArray;
	int n=text.size();
	for(int i=0;i<n;i++){
		string suffix=text.substr(i);
		suffixes.push_back(make_pair(i,suffix));
	}
	sort(suffixes.begin(),suffixes.end(),compare);
	for(int i=0;i<n;i++){
		suffixArray.push_back(suffixes[i].first);
	}
	return suffixArray;
}

int main(){
	string text;
	cin>>text;
	vector<int> suffixArray= constructSuffixArray(text);
	print(suffixArray);
}
