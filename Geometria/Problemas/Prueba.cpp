#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'

const double INF = 1e9;
const double EPS = 1e-9; // 1e-9 es suficiente para problemas de precision doble
const double PI=acos(-1.0);

double DEG_to_RAD(double d) { return d*M_PI/180.0; }
double RAD_to_DEG(double r) { return r*180.0/M_PI; }

struct P {
  double x, y;                                      
  P(double x=0.0, double y=0.0) : x(x), y(y) {}//P p(x,y) 
  void read() { cin >> x >> y; } //P p; p.read()
  double length() {return sqrt(x*x+y*y);} //hypot(x, y) mas lento pero tiene mas precision
  long long operator*(P p)const{return x*p.x + y*p.y;} // Producto punto
  long long operator%(P p)const{return x*p.y - y*p.x;} // Producto Cruz
  friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
  int norm_sq() { return x*x + y*y; } 
  bool operator==(const P &p){return x==p.x && y==p.y;}    
  P operator+(const P &p)const{return P(x+p.x,y+p.y);}
  P operator-(const P &p)const{return P(x-p.x,y-p.y);}
};

//Distancia entre 2 puntos
double dist(const P &p1, const P &p2) {                
  return hypot(p1.x-p2.x, p1.y-p2.y);            
}

// Rota el punto theta grados en contra de las manecillas alrededor del origen (0, 0)
P rotate(P p, double theta) {
  double rad = DEG_to_RAD(theta);// Convertir a radian
  return P(p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
}
// Distancia de p a la Linea ab (Punto mas cercano --> c)
// c es la proyeccion de p en AB
double distToLine(P p, P a, P b, P &c) {
    P ap = p - a, ab = b - a;
    double u = (ap * ab) / ab.norm_sq();
    c = a + (ab * u);
    return (p-c).length();
}

// Distance from p to segment ab (closest Point --> c)
double distToLineSegment(P p, P a, P b, P &c) {
    P ap = p - a, ab = b - a;
    double u = (ap * ab) / ab.norm_sq();
    if (u < 0.0) {
        c = P(a.x, a.y);
        return (p - a).length();
    }
    if (u > 1.0) {
        c = P(b.x, b.y);
        return (p - b).length();
    }
    return distToLine(p, a, b, c);
}

int main(){ 
    cout << (fixed) << setprecision(10);
    P p1,p2,p3,p4;
    p2.read();
    p3.read();
    int q;
    cin>>q;
    while(q--){
      p1.read();
      distToLine(p1,p2,p3,p4);
      cout<<p4<<ENDL;
    }
    
    // cout<<"Distancia entre los puntos (2,10) y (3,2): "<<dist({2,10},{3,2})<<ENDL;
    // cout<<"Distancia del punto (2,10) a la linea (3,2) a (3,6): "<<distToLine(p1,p2,p3,p4)<<ENDL;
    // cout<<"Proyeccion: "<<p4<<ENDL;
    // cout<<"Distancia del punto (2,10) al segmento (3,2) a (3,6): "<<distToLineSegment(p1,p2,p3,p4)<<ENDL;
    // cout<<"Punto mas cercano: "<<p4;


  return 0;
}