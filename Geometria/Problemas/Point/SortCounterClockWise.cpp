#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'
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
};

// Sort counterclockwise 
// Si el limite es demasiado grande usar atan2l
bool cmp (const P &a, const P &b) {
	return atan2(a.y, a.x) < atan2(b.y, b.x);
}

int main(){ 
    int n;
    cin>>n;
    vector<P>v;
    while(n--){
        P p;
        p.read();
        v.push_back(p);
    }
    sort(v.begin(),v.end(),cmp);
    for(auto p:v){
        p.out();
    }

  return 0;
}