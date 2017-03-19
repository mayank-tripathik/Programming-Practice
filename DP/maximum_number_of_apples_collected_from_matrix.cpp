/*
 * Problem : A table composed of NxM cells, each having a certain quantity of apples, is given. 
 * You start from the upper-left corner. At each step you can go down or right one cell. 
 * Find the maximum number of apples you can collect.
 * Solution : O(N*M) using recurrence relation T[i][j] = max(T[i-1][j],T[i][j-1])+A[i][j] if i>0 && j>0
 */
 
#include<iostream>
using namespace std;
int main(){
    const int N = 10;
    const int M = 10;
    int A[N+1][M+1] = {     {1,2,3,4,5,6,7,8,9,0},
                            {2,4,6,8,0,1,3,5,7,9},
                            {1,1,1,1,1,1,1,1,1,1},
                            {3,5,7,9,2,4,6,7,4,3},
                            {3,3,3,6,4,6,2,3,4,6},
                            {4,9,1,3,1,8,8,1,5,2},
                            {2,1,0,3,9,2,4,3,6,7},
                            {0,0,6,9,8,9,6,1,0,9},
                            {9,4,4,5,1,5,6,6,6,5},
                            {9,8,4,1,0,1,0,1,4,1}};
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    int dp[N+1][M+1];
    dp[0][0]=A[0][0];
    for(int i=1;i<N;i++)
        dp[i][0]=dp[i-1][0]+A[i][0];
    for(int j=1;j<N;j++)
        dp[0][j]=dp[0][j-1]+A[0][j];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+A[i][j];
        }
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
