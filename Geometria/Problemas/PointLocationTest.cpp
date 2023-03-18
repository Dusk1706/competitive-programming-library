// Problema https://cses.fi/problemset/task/2189/
#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;

struct P {
  ll x, y;                                      
  P() { x = y = 0; }                        
  P(ll _x, ll _y) : x(_x), y(_y) {}
  void read(){
    cin>>x>>y;
  }
  bool operator==(const P &p){return x==p.x && y==p.y;}  
  P operator+(const P &p){return P(x+p.x,y+p.y);}
  P operator-(const P &p){return P(x-p.x,y-p.y);}
  long long operator*(P p)const{return x*p.y-y*p.x;}
};

void solve(){
    P p1,p2,p3;
    p1.read();
    p2.read();
    p3.read();
    p2=p2-p1;
    p3=p3-p1;
    ll cross=p3*p2;
    if(cross<0){
        cout<<"LEFT"<<ENDL;
    }else if(cross>0){
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