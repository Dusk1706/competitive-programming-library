// Problema https://cses.fi/problemset/task/2189/
#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
const double INF = 1e9;
const double EPS = 1e-9; // 1e-9 es suficiente para problemas de precision doble
const double PI=acos(-1.0);

double DEG_to_RAD(double d) { return d*M_PI/180.0; }
double RAD_to_DEG(double r) { return r*180.0/M_PI; }

struct P {
  ll x, y;                                      
  P(ll x=0, ll y=0) : x(x), y(y) {}//P p(x,y) 
  void read() { cin >> x >> y; } //P p; p.read()
  void out(){cout<<x<<" "<<y<<ENDL;}
  ll length() {return sqrt(x*x+y*y);} //hypot(x, y) mas lento pero tiene mas precision
  ll norm_sq() { return x*x + y*y; } 
  bool operator==(const P &p){return x==p.x && y==p.y;}    
  P operator*(double a)const{return P(x*a,y*a);}
  P operator+(const P &p)const{return P(x+p.x,y+p.y);}
  P operator-(const P &p)const{return P(x-p.x,y-p.y);}
};

ll cross(P a,P b){
    return a.x*b.y-a.y*b.x;
}

void solve(){
    P p1,p2,p3;
    p1.read();
    p2.read();
    p3.read();
    p2=p2-p1;
    p3=p3-p1;
    ll res=cross(p3,p2);
    if(res<0){
        cout<<"LEFT"<<ENDL;
    }else if(res>0){
        cout<<"RIGHT"<<ENDL;
    }else{
        cout<<"TOUCH"<<ENDL;
    }
}

int main(){ _
    int T;
    cin>>T;
    while(T--){
        solve();
    }
   
  return 0;
}