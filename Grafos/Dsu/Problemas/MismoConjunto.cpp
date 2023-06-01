#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'
typedef vector<int> vi;

struct DSU {//Indice base 0
 vi e; void init(int N) { e = vi(N,-1); }
 int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
 bool sameSet(int a, int b) { return get(a) == get(b); }
 int size(int x) { return -e[get(x)]; }
 bool unite(int x, int y) { // union by size
    x = get(x), y = get(y); if (x == y) return 0;
    if (e[x] > e[y]) swap(x,y);
    e[x] += e[y]; e[y] = x; return 1;
 }
};

int main() {
    int n,q;
	cin >> n >> q;
	DSU dsu;
    dsu.init(n);
	for (int i = 0; i < q; i++) {
		int type, u, v;
		cin >> type >> u >> v;
		if (type == 0) {
			dsu.unite(u, v);
		} else {//Imprimir 1 si estan en el mismo conjunto, 0 si no
			cout << dsu.sameSet(u, v) << endl;
		}
	}
}