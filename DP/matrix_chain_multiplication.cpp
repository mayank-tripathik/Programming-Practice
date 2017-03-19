/*
 * Problem :Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
 * The problem is not actually to perform the multiplications, but to decide in which order to perform the multiplications.
 */
 
 
 
#include<bits/stdc++.h>
using namespace std;

int multiply(int i, int k, int j, vector<int> &matrices){
    if(i==j)
        return 0;
    else
    {       
        return matrices[i]*matrices[k+1]*matrices[j+1];       
    }
}

void parenthesis(vector<vector<int> > &bracket,int i, int j)
{
    if (i == j)
    {
        cout <<i;
        return;
    }
    int k=bracket[i][j];
    cout << "(";
    parenthesis(bracket,i,k);
    parenthesis(bracket,k+1,j);
    cout << ")";
}

void matrix_chain_multiplication(vector<int> matrices){
    int n=matrices.size()-1;
    vector<vector<int> > dp(n,vector<int>(n));
    vector<vector<int> > bracket(n,vector<int>(n));
    for(int i=n-1;i>=0;i--){
        int diff=(n-1)-i;
        for(int j=0;j<=i;j++){
            int p=diff+j;
            if(j==p){
                dp[j][p]=multiply(j,0,p,matrices);
            }
            else
            {
                int min=INT_MAX;
                for(int k=j;k<p;k++)
                {
                    int sum=dp[j][k]+dp[k+1][p]+multiply(j,k,p,matrices);
                    if(sum<min){
                        bracket[j][p]=k;
                        min=sum;
                    }
                }
                dp[j][p]=min;
            }
            
        }
    }
    cout<<"Minimum Multiplication :"<<dp[0][n-1]<<endl;
    cout<<"Optimal Parenthesis structure: ";
    parenthesis(bracket,0,n-1);

}
int main(){
    int number_of_matrices;
    cin>>number_of_matrices;
    vector<int> matrices(number_of_matrices+1);
    for(int i=0;i<=number_of_matrices;i++){
        cin>>matrices[i];
    }
    matrix_chain_multiplication(matrices);
}
