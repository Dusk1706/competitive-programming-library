#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

vector <vi> AdjList, NGra; //AdjList es el grafo original y NGra son los puentes
int V, E;

int dfsNumberCounter = 0, dfsRoot = 0, rootChildren = 0;

vi dfs_num, dfs_low, dfs_parent, articulation_vertex;

void articulationPointAndBridge(int u) {//Te da todos los puentes y articulaciones
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    int v = AdjList[u][j];
    if (dfs_num[v] == -1) {                          // a tree edge
      dfs_parent[v] = u;
      if (u == dfsRoot) rootChildren++;  // special case, count children of root

      articulationPointAndBridge(v);

      if (dfs_low[v] >= dfs_num[u])              // for articulation point
        articulation_vertex[u] = true;           // store this information first
      if (dfs_low[v] > dfs_num[u]){                          // for bridge
            NGra[v].push_back(u); //Sa añade las aristas al nuevo grafo
            NGra[u].push_back(v);
      }
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);       // update dfs_low[u]
    }
    else if (v != dfs_parent[u])       // a back edge and not direct cycle
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);       // update dfs_low[u]
} 
}

//Grupo de nodos que se pueden llegar entre si con un solo camino
void conexos(int u, int color){
  if(dfs_parent[u]) return; //Que ya se haya visitado

  //  Si un nodo pertenece a un ciclo no considerarlo descomentar lo de abajo
  //  if(AdjList[u].size()!=NGra[u].size()) return;
  dfs_parent[u] = color;

  for(int i = 0; i < NGra[u].size(); i++){
    conexos(NGra[u][i], color);
  }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin>>n>>m>>q;
    AdjList.assign(n + 1, vi());
    NGra.assign(n + 1, vi()); //Se guardan los puentes

    dfsNumberCounter = 0;
    dfs_num.assign(n+1, -1); 
    dfs_low.assign(n+1, 0);
    dfs_parent.assign(n+1, 0); 
    articulation_vertex.assign(n+1, 0);

    for(int i = 0; i < m; i++){//Solo para grafos no dirigidos
      int a, b;
      cin >> a >> b;
      AdjList[a].push_back(b);
      AdjList[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){ //Obtener puentes y articulaciones
      if(dfs_num[i] == -1){
          dfsRoot = i;
          rootChildren = 0;
          articulationPointAndBridge(i);
          articulation_vertex[dfsRoot] = (rootChildren > 1); //Caso especial
      }
    }
    //Hacer conjuntos de Componenetes conexos
    dfs_parent.assign(n+1, 0);
    for(int i = 1; i < n; i++){
        if(articulation_vertex[i] && dfs_parent[i] == 0){
          conexos(i, i);
        }
    }

    //dfs_parten[i]=0 - No pertenece a ningun conjunto
    //dfs_parent[i]=j - (i) Pertenece al conjunto (j)
    for(int i = 0; i < q; i++){
      int a, b;
      cin >> a >> b;
      if(dfs_parent[a]!=0 && dfs_parent[b]!=0 && dfs_parent[a] == dfs_parent[b]){
        cout << "YES\n";
      }else{
        cout<<"NO\n";
      }
    }
    return 0;
}
