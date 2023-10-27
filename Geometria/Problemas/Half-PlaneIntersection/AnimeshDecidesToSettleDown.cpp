/*
    https://www.codechef.com/problems/CHN02?tab=statement
    Problema: Te dan N poligonos y debes encontrar
    el area de la interseccion de todos los poligonos.
*/
#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9, INF = 1e9;

struct Point {
    long double x, y;
    explicit Point(long double x = 0, long double y = 0) : x(x), y(y) {}

    friend Point operator + (const Point& p, const Point& q) {
        return Point(p.x + q.x, p.y + q.y);
    }
    friend Point operator - (const Point& p, const Point& q) {
        return Point(p.x - q.x, p.y - q.y);
    }
    friend Point operator * (const Point& p, const long double& k) {
        return Point(p.x * k, p.y * k);
    }
    friend long double dot(const Point& p, const Point& q) {
        return p.x * q.x + p.y * q.y;
    }
    friend long double cross(const Point& p, const Point& q) {
        return p.x * q.y - p.y * q.x;
    }
};

struct Halfplane {
    //  'p' Es un punto que pasa por la linea del semiplano
    //   y 'pq' es el vector de direccion de la linea
    Point p, pq;
    long double angle;

    Halfplane() {}
    Halfplane(const Point& a, const Point& b) : p(a), pq(b - a) {
        angle = atan2l(pq.y, pq.x);
    }

    // Checa si el punto 'r' esta fuera del semiplano
    // Cada semiplano permite la region de la Izquierda de la linea.
    bool out(const Point& r) {
        return cross(pq, r - p) < -EPS;
    }

    // Comparador para ordenar por el angulo.
    bool operator < (const Halfplane& e) const { return angle < e.angle; }

    // Punto de interseccion de las lineas de dos semiplanos.
    // Se asume que nunca son paralelas las lineas.
    friend Point inter(const Halfplane& s, const Halfplane& t) {
        long double alpha = cross((t.p - s.p), t.pq) / cross(s.pq, t.pq);
        return s.p + (s.pq * alpha);
    }
};

vector<Point> hp_intersect(vector<Halfplane>& H) {

    Point box[4] = {  // Caja limitadora en orden CCW
        Point(INF, INF),
        Point(-INF, INF),
        Point(-INF, -INF),
        Point(INF, -INF)
    };

    for(int i = 0; i<4; i++) { // Añade la caja limitadora a los semiplanos.
        Halfplane aux(box[i], box[(i+1) % 4]);
        H.push_back(aux);
    }

    // Ordenar por angulo y inicio de algoritmo
    sort(H.begin(), H.end());
    deque<Halfplane> dq;
    int len = 0;
    for(int i = 0; i < int(H.size()); i++) {
        // Remover del final de la deque mientras el ultimo semiplano es redundante
        while (len > 1 && H[i].out(inter(dq[len-1], dq[len-2]))) {
            dq.pop_back();
            --len;
        }
        // Remover del inicio de la deque mientras el primer semiplano es redundante
        while (len > 1 && H[i].out(inter(dq[0], dq[1]))) {
            dq.pop_front();
            --len;
        }
        // Caso especial: Semiplanos Paralelos
        if (len > 0 && fabsl(cross(H[i].pq, dq[len-1].pq)) < EPS) {
            // Semiplanos opuestos paralelos que terminaron siendo comparados entre si.
            if (dot(H[i].pq, dq[len-1].pq) < 0.0)
                return vector<Point>();

            // Misma direccion de semiplano: Mantener solo el semiplano mas a la izquierda.
            if (H[i].out(dq[len-1].p)) {
                dq.pop_back();
                --len;
            }
            else continue;
        }

        // Añadir nuevo semiplano
        dq.push_back(H[i]);
        ++len;
    }

    //Limpieza final: Verifica los semiplanos del inicio contra los de la parte final y viceversa.
    while (len > 2 && dq[0].out(inter(dq[len-1], dq[len-2]))) {
        dq.pop_back();
        --len;
    }

    while (len > 2 && dq[len-1].out(inter(dq[0], dq[1]))) {
        dq.pop_front();
        --len;
    }

    // Aqui se puede retornar un vector vacio si no hay interseccion.
    if (len < 3) return vector<Point>();

    // Reconstruir el poligono convexo de los semiplanos restantes.
    vector<Point> ret(len);
    for(int i = 0; i+1 < len; i++) {
        ret[i] = inter(dq[i], dq[i+1]);
    }
    ret.back() = inter(dq[len-1], dq[0]);
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,c;
    cin>>n;
    vector<Halfplane>hps;

    for(int i=0;i<n;i++){
        cin>>c;
        vector<Point>polygon(c);
        for(int j=0;j<c;j++){
            cin>>polygon[j].x>>polygon[j].y;
        }
        polygon.push_back(polygon[0]); //cerrar el poligono
        for(int j=0; j<c; j++){
            hps.push_back({polygon[j],polygon[j+1]});
        }
    }

    //Puntos donde intersectan los poligonos
    vector<Point>inter = hp_intersect(hps);
    n=inter.size();
    if(n>0){//Hubo interseccion cerramos poligono
        inter.push_back(inter[0]);
    }

    //Sacar el area formula Shoelace
    long double ans = 0.0;
    for(int i = 0; i < n; i++) {
        ans += (inter[i].x * inter[i+1].y - inter[i+1].x * inter[i].y);
    }
    ans = fabsl(ans) / 2.0;
    cout<< fixed << setprecision(3) <<ans<<'\n';

  return 0;
}