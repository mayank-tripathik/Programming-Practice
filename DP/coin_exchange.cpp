/*
 * Problem: Given coin denominations,find how many ways we can make a certain amount/change?
 * Solution: O(change*numberOfDenomination)
 */


#include<bits/stdc++.h>
using namespace std;

void set_matrix(int change,vector<vector<int64_t> > &matrix, int lowest_denomination){
    int n=matrix.size();
    for(int i=0;i<n;i++)
        matrix[i][0]=1;
    for(int j=1;j<=change;j++){
        if(j%lowest_denomination==0)
            matrix[0][j]=1;
    }   
}

int64_t number_of_ways_of_getting_change(int change,vector<vector<int64_t> > &matrix,vector<int> &denomination){
    int n=matrix.size();
    set_matrix(change,matrix,denomination[0]);
    for(int i=1;i<n;i++){
        for(int j=1;j<=change;j++){
            if(j<denomination[i])
                matrix[i][j]=matrix[i-1][j];
            else
                matrix[i][j]=matrix[i][j-denomination[i]]+matrix[i-1][j];
        }     
    }
    return matrix[n-1][change];
}

int main(){
    int number_of_denominations,change;
    cin>>change;
    cin>>number_of_denominations;
    vector<int> denomination(number_of_denominations);
    for(int i=0;i<number_of_denominations;i++)
        cin>>denomination[i];
    vector<vector<int64_t> > matrix(number_of_denominations, vector<int64_t>(change+1));
    cout<<number_of_ways_of_getting_change(change,matrix,denomination)<<endl;
}
