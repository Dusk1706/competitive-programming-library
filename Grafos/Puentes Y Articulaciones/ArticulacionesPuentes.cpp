#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

vector <vii> AdjList;
int V, E;
int dfsNumberCounter = 0, dfsRoot = 0, rootChildren = 0;
vi dfs_num, dfs_low, dfs_parent, articulation_vertex;

void articulationPointAndBridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == -1) {                          // a tree edge
      dfs_parent[v.first] = u;
      if (u == dfsRoot) rootChildren++;  // special case, count children of root

      articulationPointAndBridge(v.first);

      if (dfs_low[v.first] >= dfs_num[u])              // for articulation point
        articulation_vertex[u] = true;           // store this information first
      if (dfs_low[v.first] > dfs_num[u])                           // for bridge
        cout<<"Edge "<<u<<" - "<<v.first<<" is a bridge\n";
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);       // update dfs_low[u]
    }
    else if (v.first != dfs_parent[u])       // a back edge and not direct cycle
      dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);       // update dfs_low[u]
} }

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;

    AdjList.assign(V, vii());

    for(int i = 0; i < E; i++){
        int a, b;
        cin >> a >> b;
        AdjList[a].push_back(ii(b, 0));
        AdjList[b].push_back(ii(a, 0));
    }

    dfsNumberCounter = 0;
    dfs_num.assign(V, -1); dfs_low.assign(V, 0);
    dfs_parent.assign(V, 0); articulation_vertex.assign(V, 0);

    cout<<"Bridges: ";

    for(int i = 0; i < V; i++){
        if(dfs_num[i] == -1){
            dfsRoot = i;
            rootChildren = 0;
            articulationPointAndBridge(i);
            articulation_vertex[dfsRoot] = (rootChildren > 1); //Caso especial
        }
    }

    printf("Articulation Points:\n");

    for(int i = 0; i < V; i++){
        if(articulation_vertex[i]){
            printf("Vertex %d\n", i);
        }
    }

    printf("dfs :\n");

    for(int i = 0; i < V; i++){
        printf("dfs_num : %d, dfs_low : %d\n", dfs_num[i], dfs_low[i]);
    }

    return 0;
}
