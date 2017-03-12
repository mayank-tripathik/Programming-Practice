#include<bits/stdc++.h>
using namespace std;

void set_matrix(int sum,vector<vector<int64_t> > &matrix, int first_number){
    int n=matrix.size();
    for(int i=0;i<n;i++)
        matrix[i][0]=1;
    for(int j=1;j<=sum;j++){
        if(j==first_number)
            matrix[0][j]=1;
        else
            matrix[0][j]=0;
    }
}   


void print(vector<vector<int64_t> > &matrix, int sum){
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<=sum;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;        
    }
}

int64_t subset_sum(int sum,vector<vector<int64_t> > &matrix,vector<int> &numbers){
    int n=matrix.size();
    set_matrix(sum,matrix,numbers[0]);
    for(int i=1;i<n;i++){
        for(int j=1;j<=sum;j++){
            if(j<numbers[i])
                matrix[i][j]=matrix[i-1][j];
            else
                matrix[i][j]=matrix[i-1][j-numbers[i]]+matrix[i-1][j];
        }     
    }
    return matrix[n-1][sum];
}

int main(){
    int n,sum;
    cin>>n;
    vector<int> numbers(n);
    for(int i=0;i<n;i++)
        cin>>numbers[i];
    cin>>sum;
    vector<vector<int64_t> > matrix(n, vector<int64_t>(sum+1));
    cout<<subset_sum(sum,matrix,numbers)<<endl;
    print(matrix, sum);
}
