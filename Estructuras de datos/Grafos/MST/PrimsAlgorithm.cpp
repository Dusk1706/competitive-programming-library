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

vector<vii> AL;
vi taken;
priority_queue<ii, vector<ii>, greater<ii>> pq;
int mst_cost = 0, num_taken = 0;

void process(int u){
    taken[u] = 1;
    for (auto &[v, w] : AL[u])
        if (!taken[v])
            pq.push({w, v});
}

void prim(vector<vii> AL,int src,int V){
    taken.assign(V+1, 0);
    process(src);
    while (!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();
        if (taken[u])
            continue;
        mst_cost += w;
        process(u);
        ++num_taken;
        if (num_taken == V - 1)
            break;
    }
}

int main(){_

    int V, E;
    cin>>V>>E;
    AL.assign(V+1, vii());
    for (int i = 0; i < E; ++i){
        int u, v, w;
        cin>>u>>v>>w;
        AL[u].push_back({v,w});
        AL[v].push_back({u,w});
    }
    prim(AL,1,V);
    cout<<"MST cost= "<<mst_cost;

    return 0;
}