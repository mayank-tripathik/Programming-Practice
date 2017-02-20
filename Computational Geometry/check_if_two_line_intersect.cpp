#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * Returns true if intersect otherwise false
 */

typedef struct point{
    int x;
    int y;
    point(){
        
    }
    point(int _x, int _y)
    {
        x=_x;
        y=_y;        
    }
    
}point;

int cross_product_2D(point a, point b, point c){
    point vec_ab,vec_ac;
    vec_ab.x=b.x-a.x;
    vec_ab.y=b.y-a.y;
    vec_ac.x=c.x-a.x;
    vec_ac.y=c.y-a.y;
    int cross=((vec_ab.x*vec_ac.y)-(vec_ab.y*vec_ac.x));
    return cross;
}

bool on_segment(point a, point b, point c){
    int max_x=max(a.x,b.x);
    int min_x=min(a.x,b.x);
    int max_y=max(a.y,b.y);
    int min_y=min(a.y,b.y);
    if((c.x>=min_x & c.x<=max_x)&&(c.y>=min_y && c.y<=max_y))
        return true;
    else
        return false;
}


bool line_intersect(point p0, point p1, point p2, point p3)
{
    int d0,d1,d2,d3;
    d0=cross_product_2D(p2,p3,p0);
    d1=cross_product_2D(p2,p3,p1);
    d2=cross_product_2D(p0,p1,p2);
    d3=cross_product_2D(p0,p1,p3);     
    if(((d0>0 && d1<0) || (d0<0 && d1>0)) && ((d2>0 && d3<0) || (d2<0 && d3>0)))
        return true;
    else if((d0==0) && on_segment(p2,p3,p0))
        return true;
    else if((d1==0) && on_segment(p2,p3,p1))
        return true;
    else if((d2==0) && on_segment(p0,p1,p2))
        return true;
    else if((d3==0) && on_segment(p0,p1,p3))
        return true;
    else
        return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. P9999int output to STDOUT */
    int test;
    cin>>test;
    while(test--){
        //point p0,p1,p2,p3;
        int x0,y0,x1,y1,x2,y2,x3,y3;
        cin>>x0>>y0>>x1>>y1>>x2>>y2>>x3>>y3;
        point p0(x0,y0);
        point p1(x1,y1);
        point p2(x2,y2);
        point p3(x3,y3);
        line_intersect(p0,p1,p2,p3);    
    }
    return 0;
}
