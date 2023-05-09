#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

double DEG_to_RAD(double d) { return d*M_PI / 180.0; }

double RAD_to_DEG(double r) { return r*180.0 / M_PI; }

struct P { double x, y;   // only used if more precision is needed
    P() { x = y = 0.0; }                      // default constructor
    P(double _x, double _y) : x(_x), y(_y) {}        // user-defined
    bool operator == (P other) const {
        return (fabs(x-other.x) < EPS && (fabs(y-other.y) < EPS)); 
    } 
    bool operator <(const P &p) const {
        return x < p.x || (abs(x-p.x) < EPS && y < p.y); 
    } 
};

struct vec { double x, y;  // name: `vec' is different from STL vector
  vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(P a, P b) {       // convert 2 points to vector a->b
  return vec(b.x-a.x, b.y-a.y); }

double dist(P p1, P p2) {                // Euclidean distance
  return hypot(p1.x-p2.x, p1.y-p2.y); }               // return double

// returns the perimeter of polygon P, which is the sum of
// Euclidian distances of consecutive line segments (polygon edges)
double perimeter(const vector<P> &pts) {       // by ref for efficiency
  double ans = 0.0;
  for (int i = 0; i < (int)pts.size()-1; ++i)      // note: P[n-1] = P[0]
    ans += dist(pts[i], pts[i+1]);                   // as we duplicate P[0]
  return ans;
}

// returns the area of polygon P
double area(const vector<P> &pts) {
  double ans = 0.0;
  for (int i = 0; i < (int)pts.size()-1; ++i)      // Shoelace formula
    ans += (pts[i].x*pts[i+1].y - pts[i+1].x*pts[i].y);
  return fabs(ans)/2.0;                          // only do / 2.0 here
}

double dot(vec a, vec b) { return (a.x*b.x + a.y*b.y); }

double norm_sq(vec v) { return v.x*v.x + v.y*v.y; }

double angle(P a, P o, P b) {  // returns angle aob in rad
  vec oa = toVec(o, a), ob = toVec(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

double cross(vec a, vec b) { return a.x*b.y - a.y*b.x; }

// returns the area of polygon P, which is half the cross products
// of vectors defined by edge endpoints
double area_alternative(const vector<P> &pts) {
  double ans = 0.0; P O(0.0, 0.0);           // O = the Origin
  for (int i = 0; i < (int)pts.size()-1; ++i)      // sum of signed areas
    ans += cross(toVec(O, pts[i]), toVec(O, pts[i+1]));
  return fabs(ans)/2.0;
}

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(P p, P q, P r) {
  return cross(toVec(p, q), toVec(p, r)) > 0;
}

// returns true if point r is on the same line as the line pq
bool collinear(P p, P q, P r) {
  return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

// returns true if we always make the same turn
// while examining all the edges of the polygon one by one
bool isConvex(const vector<P> &pts) {
  int n = (int)pts.size();
  // a point/sz=2 or a line/sz=3 is not convex  
  if (n <= 3) return false;
  bool firstTurn = ccw(pts[0], pts[1], pts[2]);        // remember one result,
  for (int i = 1; i < n-1; ++i)                 // compare with the others
    if (ccw(pts[i], pts[i+1], pts[(i+2) == n ? 1 : i+2]) != firstTurn)
      return false;                              // different -> concave
  return true;                                   // otherwise -> convex
}

// returns 1/0/-1 if point p is inside/on (vertex/edge)/outside of
// either convex/concave polygon P
int insidePolygon(P p, const vector<P> &pts) {
  int n = (int)pts.size();
  if (n <= 3) return -1;                         // avoid point or line
  bool on_polygon = false;
  for (int i = 0; i < n-1; ++i)                  // on vertex/edge?
    if (fabs(dist(pts[i], p) + dist(p, pts[i+1]) - dist(pts[i], pts[i+1])) < EPS)
      on_polygon = true;
  if (on_polygon) return 0;                      // pt is on polygon
  double sum = 0.0;                              // first = last point
  for (int i = 0; i < n-1; ++i) {
    if (ccw(p, pts[i], pts[i+1]))
      sum += angle(pts[i], p, pts[i+1]);            // left turn/ccw
    else
      sum -= angle(pts[i], p, pts[i+1]);            // right turn/cw
  }
  return fabs(sum) > M_PI ? 1 : -1;              // 360d->in, 0d->out
}

// compute the intersection point between line segment p-q and line A-B
P lineIntersectSeg(P p, P q, P A, P B) {
  double a = B.y-A.y, b = A.x-B.x, c = B.x*A.y - A.x*B.y;
  double u = fabs(a*p.x + b*p.y + c);
  double v = fabs(a*q.x + b*q.y + c);
  return P((p.x*v + q.x*u) / (u+v), (p.y*v + q.y*u) / (u+v));
}

// cuts polygon Q along the line formed by point A->point B (order matters)
// (note: the last point must be the same as the first point)
vector<P> cutPolygon(P A, P B, const vector<P> &Q) {
  vector<P> pts;
  for (int i = 0; i < (int)Q.size(); ++i) {
    double left1 = cross(toVec(A, B), toVec(A, Q[i])), left2 = 0;
    if (i != (int)Q.size()-1) left2 = cross(toVec(A, B), toVec(A, Q[i+1]));
    if (left1 > -EPS) pts.push_back(Q[i]);         // Q[i] is on the left
    if (left1*left2 < -EPS)                      // crosses line AB
      pts.push_back(lineIntersectSeg(Q[i], Q[i+1], A, B));
  }
  if (!pts.empty() && !(pts.back() == pts.front()))
    pts.push_back(pts.front());                      // wrap around
  return pts;
}

vector<P> CH_Graham(vector<P> &ptsOriginal) {    // overall O(n log n)
  vector<P> pts(ptsOriginal);                        // copy all points
  int n = (int)pts.size();
  if (n <= 3) {                                          // point/line/triangle
    if (!(pts[0] == pts[n-1])) pts.push_back(pts[0]);    // corner case
    return pts;                                          // the CH is P itself
  }

  // first, find P0 = point with lowest Y and if tie: rightmost X
  int P0 = min_element(pts.begin(), pts.end())-pts.begin();
  swap(pts[0], pts[P0]);                             // swap P[P0] with P[0]

  // second, sort points by angle around P0, O(n log n) for this sort
  sort(++pts.begin(), pts.end(), [&](P a, P b) {
    return ccw(pts[0], a, b);                      // use P[0] as the pivot
  });

  // third, the ccw tests, although complex, it is just O(n)
  vector<P> S({pts[n-1], pts[0], pts[1]});         // initial S
  int i = 2;                                     // then, we check the rest
  while (i < n) {                                // n > 3, O(n)
    int j = (int)S.size()-1;
    if (ccw(S[j-1], S[j], pts[i]))                 // CCW turn
      S.push_back(pts[i++]);                       // accept this point
    else                                         // CW turn
      S.pop_back();                              // pop until a CCW turn
  }
  return S;                                      // return the result
}

vector<P> CH_Andrew(vector<P> &pts) {    // overall O(n log n)
  int n = pts.size(), k = 0;
  vector<P> H(2*n);
  sort(pts.begin(), pts.end());                  // sort the points by x/y
  for (int i = 0; i < n; ++i) {                  // build lower hull
    while ((k >= 2) && !ccw(H[k-2], H[k-1], pts[i])) --k;
    H[k++] = pts[i];
  }
  for (int i = n-2, t = k+1; i >= 0; --i) {       // build upper hull
    while ((k >= t) && !ccw(H[k-2], H[k-1], pts[i])) --k;
    H[k++] = pts[i];
  }
  H.resize(k);
  return H;
}

int main() {
  // 6(+1) points, entered in counter clockwise order, 0-based indexing
  vector<P> pts;
  pts.emplace_back(1, 1);                          // P0
  pts.emplace_back(3, 3);                          // P1
  pts.emplace_back(9, 1);                          // P2
  pts.emplace_back(12, 4);                         // P3
  pts.emplace_back(9, 7);                          // P4
  pts.emplace_back(1, 7);                          // P5
  pts.push_back(pts[0]);                             // loop back, P6 = P0

  printf("Perimeter = %.2lf\n", perimeter(pts));   // 31.64
  printf("Area = %.2lf\n", area(pts));             // 49.00
  printf("Area = %.2lf\n", area_alternative(pts)); // also 49.00
  printf("Is convex = %d\n", isConvex(pts));       // 0 (false)

  //// the positions of P_out, P_on, P_in with respect to the polygon
  //7 P5------P_on----P4
  //6 |                  \
  //5 |                    \
  //4 |   P_in              P3
  //3 |   P1___            /
  //2 | / P_out \ ___    /
  //1 P0              P2
  //0 1 2 3 4 5 6 7 8 9 101112

  P p_out(3, 2); // outside this (concave) polygon
  printf("P_out is inside = %d\n", insidePolygon(p_out, pts)); // -1
  printf("P1 is inside = %d\n", insidePolygon(pts[1], pts)); // 0
  P p_on(5, 7); // on this (concave) polygon
  printf("P_on is inside = %d\n", insidePolygon(p_on, pts)); // 0
  P p_in(3, 4); // inside this (concave) polygon
  printf("P_in is inside = %d\n", insidePolygon(p_in, pts)); // 1

  // cutting the original polygon based on line P[2] -> P[4] (get the left side)
  //7 P5--------------P4
  //6 |               |  \
  //5 |               |    \
  //4 |               |     P3
  //3 |   P1___       |    /
  //2 | /       \ ___ |  /
  //1 P0              P2
  //0 1 2 3 4 5 6 7 8 9 101112
  // new polygon (notice the index are different now):
  //7 P4--------------P3
  //6 |               |
  //5 |               |
  //4 |               |
  //3 |   P1___       |
  //2 | /       \ ___ |
  //1 P0              P2
  //0 1 2 3 4 5 6 7 8 9

  pts = cutPolygon(pts[2], pts[4], pts);
  printf("Perimeter = %.2lf\n", perimeter(pts));   // smaller now, 29.15
  printf("Area = %.2lf\n", area(pts));             // 40.00

  // running convex hull of the resulting polygon (index changes again)
  //7 P3--------------P2
  //6 |               |
  //5 |               |
  //4 |   P_out       |
  //3 |               |
  //2 |   P_in        |
  //1 P0--------------P1
  //0 1 2 3 4 5 6 7 8 9

  pts = CH_Graham(pts);                              // now this is a rectangle
  printf("Perimeter = %.2lf\n", perimeter(pts));   // precisely 28.00
  printf("Area = %.2lf\n", area(pts));             // precisely 48.00
  printf("Is convex = %d\n", isConvex(pts));       // true
  printf("P_out is inside = %d\n", insidePolygon(p_out, pts)); // 1
  printf("P_in is inside = %d\n", insidePolygon(p_in, pts)); // 1

  return 0;
}