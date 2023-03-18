#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'
#define f first
#define s second
#define all(s) begin(s), end(s)
#define rall(n) n.rbegin(), n.rend()
#define FOR(x, b) for(int x = 0; x <b; x++)
#define FORE(x, a, b) for(int x = a; x <= b; x++)
#define FORR(x, a, b) for(int x = a; x >= b; x--)
#define deb(x)      cerr << #x << " = " << x << '\n';
#define deb2(x, y)  cerr << #x << " = " << x << ", " << #y << " = " << y << '\n';
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll n, m, q, k, l, r, x, y, z, ans=0;
const double INF = 1e9;
const double EPS = 1e-9;
const double PI=acos(-1.0);
struct pt {// for 3D add z coordinate
  double x, y;                                   
  pt() { x = y = 0.0; }                       
  pt(double _x, double _y) : x(_x), y(_y) {}  

  bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
  pt operator+(pt p){return pt(x+p.x,y+p.y);}
  pt operator-(pt p){return pt(x-p.x,y-p.y);}
  pt operator*(double t){return pt(x*t,y*t);}
	pt operator/(double t){return pt(x/t,y/t);}
  double operator*(pt p){return x*p.x+y*p.y;}
  // pt operator^(pt p){ //only for 3D
  //		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
  double operator%(pt p){return x*p.y-y*p.x;}
  
  // bool operator<(pt p)const{ // for convex hull
	// 	return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
  bool operator < (pt other) const {          
    if (fabs(x-other.x) > EPS)                   // Util para ordenar
      return x < other.x;                        // Por coordenada X
    return y < other.y;                          // Si empatan por coordenada Y
  }

};

double cross(pt a, pt b) { return a.x*b.y - a.y*b.x; }

int main(){ _

    cin>>n;
    while(n--){
        int x1,y1,x2,y2,x3,y3;
    }
    


  return 0;
}