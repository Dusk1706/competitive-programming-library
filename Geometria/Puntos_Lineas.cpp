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
  void out(){cout<<x<<" "<<y<<ENDL;}
  double length() {return sqrt(x*x+y*y);} //hypot(x, y) mas lento pero tiene mas precision
  int norm_sq() { return x*x + y*y; } 
  bool operator==(const P &p){return x==p.x && y==p.y;}    
  P operator*(double a)const{return P(x*a,y*a);}
  P operator+(const P &p)const{return P(x+p.x,y+p.y);}
  P operator-(const P &p)const{return P(x-p.x,y-p.y);}
  bool operator <(P other) const {          
    if (fabs(x-other.x) > EPS)              // useful for sorting
      return x < other.x;                   // by x-coordinate
    return y < other.y;                     // if tie, by y-coordinate
  }
};

double abs(P p) {return sqrt(p.norm_sq());}

P toVec(P a, P b) {return b-a;} //Vector a->b

double dot(P a,P b){ return a.x*b.x + a.y*b.y; }

double cross(P a,P b){ return a.x*b.y-a.y*b.x; }

//Distancia entre 2 puntos
double dist(const P &p1, const P &p2) {return hypot(p1.x-p2.x, p1.y-p2.y);}

double distManhattan(const P &p1, const P &p2){return abs(p1.x-p2.x)+abs(p1.y-p2.y);}

// Rota el punto theta grados en contra de las manecillas alrededor del origen (0, 0)
P rotate(P p, double theta) {
  double rad = DEG_to_RAD(theta);// Convertir a radian
  return P(p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
}
//Orientacion del punto P en la linea ab
//Positivo = izquierda, Negativo = derecha , 0 = colineal
int orient(P a, P b, P p) {return cross(b-a,p-a);}

//Comprueba si dos vectores son perpendiculares
bool isPerp(P v, P w) {return dot(v,w) == 0;}

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(P p, P q, P r) {
  return cross(toVec(p, q), toVec(p, r)) > -EPS;
}

// returns true if point r is on the same line as the line pq
bool collinear(P p, P q, P r) {
  return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

// Sort counterclockwise 
// Si el limite es demasiado grande usar atan2l
bool cmp (const P &a, const P &b) {
	return atan2(a.y, a.x) < atan2(b.y, b.x);
}

//Angulo entre 2 vectores [0,PI]
double angle(P v, P w) {
double cosTheta = dot(v,w) / abs(v) / abs(w);
return acos(max(-1.0, min(1.0, cosTheta)));
}

//Checa si el punto P esta dentro del angulo de las lineas
//AB y AC
bool inAngle(P a, P b, P c, P p) {
assert(orient(a,b,c) != 0);//Invalido
if (orient(a,b,c) < 0) swap(b,c);
return orient(a,b,p) >= 0 && orient(a,c,p) <= 0;
}

// Distancia de p a la Linea ab (Punto mas cercano --> c)
// c es la proyeccion de p en AB
double distToLine(P p, P a, P b, P &c) {
    P ab = b - a, ap = p - a;
    double r = dot(ap,ab) / ab.norm_sq();
    c = a + (ab * r);
    return (c-p).length();
}

// Distance de p al segmento ab (Punto mas cercano --> c)
double distToLineSegment(P p, P a, P b, P &c) {
    P ap = p - a, ab = b - a;
    double u = dot(ap,ab) / ab.norm_sq();
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

//Coeficientes ax + by + c = 0
//B=0 Linea vertical B=1 Linea No vertical
struct Line { double a, b, c; };                 // most versatile

// Convierte 2 puntos en una linea pasada por referencia
void pointsToLine(P p1, P p2, Line &l) {
  if (fabs(p1.x-p2.x) < EPS)                     // vertical line is fine
    l = {1.0, 0.0, -p1.x};                       // default values
  else {
    double a = -(double)(p1.y-p2.y) / (p1.x-p2.x);
    l = {a, 1.0, -(double)(a*p1.x) - p1.y};      // NOTE: b always 1.0
  }
}

//not needed since we will use the more robust form: ax + by + c = 0
//Y= mx + c
struct line2 { double m, c; };                   // alternative way

int pointsToLine2(P p1, P p2, line2 &l) {
  if (p1.x == p2.x) {                            // vertical line
    l.m = INF;                                   // this is to denote a
    l.c = p1.x;                                  // line x = x_value
    return 0;                                    // differentiate result
  }
  else {
    l.m = (double)(p1.y-p2.y) / (p1.x-p2.x);
    l.c = p1.y - l.m*p1.x;
    return 1;                                    // standard y = mx + c
  }
}

bool areParallel(Line l1, Line l2) {             // check a & b
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(Line l1, Line l2) {                 // also check  c
  return areParallel(l1 ,l2) && (fabs(l1.c-l2.c) < EPS);
}

// returns true (+ intersection point p) if two lines are intersect
bool areIntersect(Line l1, Line l2, P &p) {
  if (areParallel(l1, l2)) return false;         // no intersection
  // solve system of 2 linear algebraic equations with 2 unknowns
  p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
  // special case: test for vertical line to avoid division by zero
  if (fabs(l1.b) > EPS) p.y = -(l1.a*p.x + l1.c);
  else                  p.y = -(l2.a*p.x + l2.c);
  return true;
}

// convert point and gradient/slope to line
void pointSlopeToLine(P p, double m, Line &l) {
  l.a = -m;                                      // always -m
  l.b = 1;                                       // always 1
  l.c = -((l.a * p.x) + (l.b * p.y));            // compute this
}

void closestPoint(Line l, P p, P &ans) {
  // this line is perpendicular to l and pass through p
  Line perpendicular;                            
  if (fabs(l.b) < EPS) {                         // vertical line
    ans.x = -(l.c);
    ans.y = p.y;
    return;
  }
  if (fabs(l.a) < EPS) {                         // horizontal line
    ans.x = p.x;
    ans.y = -(l.c);
    return;
  }
  pointSlopeToLine(p, 1/l.a, perpendicular);     // normal line
  // intersect line l with this perpendicular line
  // the intersection point is the closest point
  areIntersect(l, perpendicular, ans);
}

// returns the reflection of point on a line
void reflectionPoint(Line l, P p, P &ans) {
  P b;
  closestPoint(l, p, b);  // similar to distToLine
  P v = toVec(p, b);      // create a vector
  ans = (p+v)+v;          // translate p twice
}

int main(){ 
    cout << (fixed) << setprecision(10);
    P a,b,p,c;
    a.read();
    b.read();
    

  return 0;
}