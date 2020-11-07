#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<climits>
#include<cfloat>
#include<cstdio>

using namespace std;

typedef double Real;

Real EPS = 1e-8;
const Real PI = acos(-1);

int sgn(Real a, Real b=0){return a<b-EPS?-1:a>b+EPS?1:0;}
Real sqr(Real a){return sqrt(max(a,(Real)0));}

struct Point{
  Real add(Real a, Real b){
    if(abs(a+b) < EPS*(abs(a)+abs(b)))return 0;
    return a+b;
  }

  Real x, y;
  Point(){}
  Point(Real x,Real y) : x(x) , y(y){}

  Point operator + (Point p){return Point(add(x,p.x), add(y,p.y));}
  Point operator - (Point p){return Point(add(x,-p.x), add(y,-p.y));}
  Point operator * (Real d){return Point(x*d,y*d);}
  Point operator / (Real d){return Point(x/d,y/d);}
  bool operator == (Point p){return !sgn(dist(p));}
  //昇順
  bool operator < (Point p)const{return (p.x!=x)?x<p.x:y<p.y;}
  Real norm(){return sqr(x*x+y*y);}
  Real dist(Point a){return (*this-a).norm();}
  Real dot(Point a){return x*a.x+y*a.y;}
  Real cross(Point a){return x*a.y-y*a.x;}
};

struct Circle{
  Point p;
  Real r;
  Circle(){}
  Circle(Point p, Real r) : p(p) , r(r){}

  bool contain(Point a){
    return sgn((a-p).norm(),r)<=0;
  }

  Circle circumCircle(Point a,Point b){
    Point q=(a+b)/2;
    return Circle(q,(a-q).norm());
  }

  Circle circumscribedCircle(Point p, Point q, Point r){
    Point a=(q-p)*2,b=(r-p)*2;
    Point c(p.dot(p)-q.dot(q),p.dot(p)-r.dot(r));
    Circle res;
    res.p.x=a.y*c.y-b.y*c.x;
    res.p.y=b.x*c.x-a.x*c.y;
    res.p=res.p/a.cross(b);
    return Circle(res.p, p.dist(res.p));
  }

  Circle minEnclosingCircle(vector<Point>ps){
    if(ps.size()==0)return Circle(Point(0,0),0);
    if(ps.size()==1)return Circle(ps[0],0);

    Circle circle=circumCircle(ps[0],ps[1]);
    for(int i=2;i<ps.size();i++){
      if(!circle.contain(ps[i])){
	circle=circumCircle(ps[0],ps[i]);
	for(int j=1;j<i;j++){
	  if(!circle.contain(ps[j])){
	    circle=circumCircle(ps[j],ps[i]);
	    for(int k=0;k<j;k++){
	      if(!circle.contain(ps[k])){
		circle=circumscribedCircle(ps[i],ps[j],ps[k]);
	      }
	    }
	  }
	}
      }
    }
    return circle;
  }

};

int main(void){

  int n;
  cin >> n;
  vector<Point>ps(n);

  for(int i=0;i<n;i++)cin >> ps[i].x >> ps[i].y;
  Circle c;
  printf("%.20f",c.minEnclosingCircle(ps).r);
  cout << endl;

  return 0;
}
