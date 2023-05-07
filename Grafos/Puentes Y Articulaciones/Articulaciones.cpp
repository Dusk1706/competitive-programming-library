#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'
#define FOR(x, b) for(int x = 0; x <b; x++)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
ll n, m, q, k, l, r, x, y, z, ans=0;
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                cout<<"Es articulacion nodo "<<v+1<<ENDL;
            ++children;
        }
    }
    if(p == -1 && children > 1)
        cout<<"Es articulacion nodo "<<v+1<<ENDL;
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}

int main(){ _
    cin>>n>>m;
    adj.resize(n);
    FOR(i,m){
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    find_cutpoints();

  return 0;
}