/*
 * Check if two rectangles whose sides are parallel to coordinate axes intersect or not
 * If intersect then intersection is point, line or rectangle
 */
 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int x1,y1,x2,y2;
        int m1,n1,m2,n2;
        cin>>x1>>y1>>x2>>y2;
        cin>>m1>>n1>>m2>>n2;
        int max_x,min_x,max_y,min_y;
        max_x=max(x2,m2);
        min_x=min(x1,m1);
        max_y=max(y2,n2);
        min_y=min(y1,n1);
        int dist_x=(x2-x1)+(m2-m1);
        int dist_y=(y2-y1)+(n2-n1);
        int s_x=max_x-min_x;
        int s_y=max_y-min_y;
        if(dist_x==s_x && dist_y==s_y)
            cout<<"Point\n";
        else if((dist_x>s_x && dist_y==s_y) || (dist_y>s_y && dist_x==s_x))
            cout<<"Line\n";
        else if(dist_x>s_x && dist_y>s_y)
            cout<<"Rectangle\n";
        else
            cout<<"Apart\n";
        
    }
}
