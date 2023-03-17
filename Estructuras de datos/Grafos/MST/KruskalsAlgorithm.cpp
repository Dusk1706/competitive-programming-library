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
typedef tuple<int,int,int> T_iii;
typedef tuple<int,int,int,int> T_iiii;


class UnionFind {
private:
    vi p, rank, setSize;
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int V, E;
    cin>>V>>E;
    vector<T_iii> EL(E);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin>>u>>v>>w;
        EL[i] = {w, u, v};
    }
    sort(EL.begin(), EL.end());
    ull mst_cost = 0, num_taken = 0;
    UnionFind UF(V+1);
    for (int i = 0; i < E; ++i) {
        auto [w, u, v] = EL[i];
        if (UF.isSameSet(u, v)) continue;
        mst_cost += w;
        UF.unionSet(u, v);
        ++num_taken;
        if (num_taken == V-1) break;
    }
    cout<<mst_cost<<" "<<num_taken;
  return 0;
}