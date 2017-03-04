#include<bits/stdc++.h>
#define PI 3.141592
using namespace std;


struct point{
    int x,y,index;
    point(){
        
    }
    point(int _x, int _y){
        x=_x;
        y=_y;
    }
};

point start;
void set_p0_as_min_point(vector<point> &poles){
    point min_point=poles[0];
    int min_point_index;
    for(int i=1;i<poles.size();i++){
        if((poles[i].y<min_point.y) || ((poles[i].y==min_point.y) && (poles[i].x<min_point.x))){
            min_point=poles[i];
            min_point_index=i;
        }
    }
    swap(poles[0],poles[min_point_index]);
    start=poles[0];
}


float polar_angle(point p0, point p1){
    int y=p1.y-p0.y;
    int x=p1.x-p0.x;
    float ang=atan2(y,x)*180/PI;
    return ang;
}

int dist(point p1, point p2){
    int distt;
    distt=pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2);
    return distt;
}

bool compare(const point &point1, const point &point2){
    float angle1=polar_angle(start,point1);
    float angle2=polar_angle(start,point2);
    if(angle1<angle2)
       return true;
    else if(angle1==angle2){
        if(dist(start,point1)<dist(start,point2))
            return true;
        else
            return false;
    }
    else
       return false;
}

       
bool non_left_turn(point p0, point p1, point p2){
    int m,n;
    m=p1.x-p0.x;
    n=p1.y-p0.y;
    point a(m,n);
    m=p2.x-p0.x;
    n=p2.y-p0.y;
    point b(m,n);
    if(((b.x*a.y)-(b.y*a.x))>0)
        return true;
    else
        return false;
}

point next_to_top(stack<point> &mystack){
    point point_top=mystack.top();
    mystack.pop();
    point next_top=mystack.top();
    mystack.push(point_top);
    return next_top;
}

void print(vector<point> &poles){
    cout<<"sorted point\n"<<endl;
    for(int i=0;i<poles.size();i++)
        cout<<poles[i].x<<","<<poles[i].y<<endl;
}
stack<point> convex_hull(vector<point> &poles){
    set_p0_as_min_point(poles);
    //cout<<"p0:"<<start.x<<","<<start.y<<endl;
    sort(poles.begin()+1,poles.end(),compare);
    //print(poles);
    stack<point> mystack;
    mystack.push(poles[0]);
    mystack.push(poles[1]);
    mystack.push(poles[2]);
    for(int i=3;i<poles.size();i++){
        while(non_left_turn(next_to_top(mystack),mystack.top(),poles[i])){
            //cout<<i<<" this i makes non left turn\n";
            mystack.pop();
        }
        //cout<<i<<" this i does not makes non left turn\n";
        mystack.push(poles[i]);
    }
    /*cout<<"point in convex hull\n";
    while(!mystack.empty()){
        point topp=mystack.top();
        cout<<topp.x<<","<<topp.y<<endl;
        mystack.pop();
    }*/
    return mystack;
}
       
int main() {
    int n;
    cin>>n;
    vector<point> poles(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        poles[i].x=x;
        poles[i].y=y; 
        poles[i].index=i;
    }
    stack<point> S=convex_hull(poles);
    while(!S.empty())
    {
        point p=S.top();
        S.pop();
        cout<<p.x<<","<<p.y<<endl;
	  }
    return 0;
}
