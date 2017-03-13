/*
 * Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=44
 * Extra infomration is maintained in the form of row and coloumns sum to get sub matrix sum in O(1)
 * complexity: O(n^4)
 */

#include<bits/stdc++.h>
using namespace std;

int matrix[100][100];
int temp[100][100];

void set_temp_as_cumulative_sum(int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            temp[i][j]=temp[i][j-1]+matrix[i][j];
        }
    }
    for(int j=0;j<n;j++){
        for(int i=1;i<n;i++){
            temp[i][j]=temp[i-1][j]+temp[i][j];
        }
    }
}

void intialise_temp(int n){
    for(int i=0;i<n;i++){
        temp[i][0]=matrix[i][0];
    }
    for(int j=1;j<n;j++){
        temp[0][j]=matrix[0][j];
    }
}

int sub_matrix_sum(int a, int b, int i, int j){
    int sum=temp[a][b];
    if(i>0)
        sum-=temp[i-1][b];
    if(j>0)
        sum-=temp[a][j-1];
    if(i>0 && j>0)
        sum+=temp[i-1][j-1];
    return sum;
}

void max_sub_rectangle(int n){
    intialise_temp(n);
    set_temp_as_cumulative_sum(n);
    int max_sum=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int a=i;a<n;a++){
                for(int b=j;b<n;b++){
                    int curr_sum=sub_matrix_sum(a,b,i,j);
                    if(curr_sum>max_sum)
                        max_sum=curr_sum;
                }
            }
        }
    }
    cout<<max_sum<<endl;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];
    max_sub_rectangle(n);
}
