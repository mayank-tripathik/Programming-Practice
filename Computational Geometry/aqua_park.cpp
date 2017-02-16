#include <bits/stdc++.h>
using namespace std;

struct point{
    int x;
    int y;
};

struct line{
    point a;
    point b;
};

bool comp(const line &line1, const line &line2){
    int max_y_one=max(line1.a.y,line1.b.y);
    int max_y_two=max(line2.a.y,line2.b.y);
    if(max_y_one>max_y_two)
        return true;
    else
        return false;
}

int find_next(line li){
    if(li.a.y<li.b.y)
        return li.a.x;
    else
        return li.b.x;
}
int main()
{
    int x,n,x_new;
    cin>>x>>n;
    vector<line> slides(n);
    line l;
    for(int i=0;i<n;i++){
        int x0,y0,x1,y1;
        cin>>x0>>y0>>x1>>y1;
        l.a.x=x0;
        l.a.y=y0;
        l.b.x=x1;
        l.b.y=y1;
        slides[i]=l;
    }
    sort(slides.begin(),slides.end(),comp);
    x_new=x;
    for(auto itr=slides.begin();itr!=slides.end();itr++){
        line next_slide=(*itr);
        cout<<next_slide.a.x<<" "<<next_slide.a.y<<" "<<next_slide.b.x<<" "<<next_slide.b.y<<endl;
        if(x_new>=next_slide.a.x && x_new<=next_slide.b.x)
            x_new=find_next(next_slide);
    }
    cout<<x_new<<endl;
    return 0;
}
