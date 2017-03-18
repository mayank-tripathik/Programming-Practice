#include<bits/stdc++.h>
using namespace std;

int longest_decreasing_subsequence(vector<int> &arr){
    int n=arr.size();
    vector<int> T(n,1);
    int max_val=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[i]){
                T[i]=max(T[i],(T[j]+1));
                if(T[i]>max_val)
                    max_val=T[i];
            }            
        }
    }
    return max_val;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<longest_decreasing_subsequence(arr);
}
