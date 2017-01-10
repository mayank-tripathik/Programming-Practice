#include <bits/stdc++.h>
using namespace std;

int char_to_int(char c){
    int x;
    x=c-'0';
    return x;
}

int digit_sum(char a, char b, int carry, vector<int> &sum, int size ){
    int x=char_to_int(a);
    int y=char_to_int(b);
    int addition=x+y+carry;
    if(addition>9){
        carry=addition/10;
        addition=addition%10;
    }
    else
        carry=0;
    sum[size]=addition;
    return carry;
}
void add(string num1, string num2){
    int size=num2.size();
    int addition;
    vector<int> sum(size+1);
    int carry=0;
    int i=num1.size()-1;
    int j=size-1;
    while(i>=0){
        carry=digit_sum(num1[i],num2[j],carry,sum,size);
        i--;
        j--;
        size--;
        
    }
    for(int k=j;k>=0;k--)
    {
        int a=char_to_int(num2[k]);
        int b=0;
        carry=digit_sum(num2[k],'0',carry,sum,size);
        size--;
    }
    if(carry!=0){
        sum[size]=carry;
    }
    int k=0;
    while(sum[k]==0)
        k++;
    while(k<sum.size()){
        cout<<sum[k];
        k++;
    }
        
    cout<<endl;
}

int main()
{
    int test;
    cin>>test;
    while(test--){
        string num1,num2;
        cin>>num1>>num2;
        if(num1.size()<num2.size())
            add(num1,num2);
        else
            add(num2,num1);
    }
    return 0;
}
