#include<bits/stdc++.h>
using namespace std;

typedef struct point{
    int x;
    int y;
    point(){
        
    }
    point(int a, int b){
        x=a;
        y=b;
    }
} point;

typedef struct vector{
    point a;
} vec;

vec point_to_vector(point a, point b){
    vec vector_ab;
    vector_ab.x=b.x-a.x;
    vector_ab.y=b.y-a.y;
    return vector_ab;
}

int vector_magnitude(vec v){
    int magnitude=sqrt((v.x*v.x)+(v.y*v.y));
    return magnitude;
}

vec perpendicular_vector(vec v){
    vec w;
    w.x=v.y*(-1);
    w.y=v.x;
    return w;
}
//returns dot-product of two vectors a and b
int dot_product_2D(vec a, vec b){
    return ((a.x*b.x)+(a.y*b.y));    
}


//returns cross-product of two vectors a and b
int cross_product_2D(vec a, vec b){
    return ((a.x*b.y)-(a.y*b.x));    
}

//return 1 if p1 is counterclockwise to p2
//return -1 if p1 is clockwise to p2
//return 0 if p1 is collinear to p2
bool ccw(vec p1, vec p2){
    int cross_product=cross_product_2D(p1,p2)
    if(cross_product<0)
        return 1;
    else if(cross_product>0)
        return -1;
    else
        return 0;
}


int area_of_triangle(point a, point b , point c){
    vec v=point_to_vector(a,b);
    vec w=point_to_vector(a,c);
    return (cross_product_2D(v,w)/2);
}

int area_of_parallelogram(point a, point b , point c, point d){
    vec v=point_to_vector(a,b);
    vec w=point_to_vector(a,d);
    return (cross_product_2D(v,w));
}

int area_of_quadrilateral(point a, point b , point c, point d){
    int area=(c.x-a.x)(d.y-b.y)-(d.x-b.x)(c.y-a.x);
    area=area/2;
    return area;
}

int distance_of_point_to_line_impicit_equation(point p0, point p1, point p){
    vec v=point_to_vector(p0,p1);
    vec w=point_to_vector(p0,p);
    int mod_v=vector_magnitude(v);
    int distance=cross_product_2D(v,w)/mod_v;
    return distance;
}

int distance_of_point_to_line_parametric_equation(point p0, point p1, point p){
    vec v=point_to_vector(p0,p1);
    vec w=point_to_vector(p0,p);
    int distance=dot_product_2D(w,v)/dot_product_2D(v,v);
    return distance;
}

int area_of_polygon(vector<point> vertex){
    int area=0;
    point p(0,0);
    for(int i=0;i<vertex.size()-1;i++){
        area+=area_of_triangle(p,vertex[i],vertex[i+1]);
    }
    return (area/2);
}


void line_intersection(point p0. point p1, point q0, point q1){
    vec u=point_to_vector(p0,p1);
    vec v=point_to_vector(q0,q1);
    if(dot_product_2D(perpendicular_vector(u),v)==0){
        if(dot_product_2D(perpendicular_vector(w),v)==0)
            cout<<"Lines conincident";        
    }
    else{
        point intersection;
        intersection.x=dot_product_2D(perpendicular_vector(v),w)/dot_product_2D(perpendicular_vector(v),u);
        intersection.y=dot_product_2D(perpendicular_vector(u),w)/dot_product_2D(perpendicular_vector(u),v);
        cout<<"intersection points are:"<<intersection.x<<","<<intersection.y<<endl;
    }
}

int main(){
    point p0,p1,p2;
    
    
}
