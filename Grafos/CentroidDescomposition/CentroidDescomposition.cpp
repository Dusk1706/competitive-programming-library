/*
 * Descripcion: cuando se trabaja con caminos en un arbol, es util descomponer a este
 * recursivamente en sub-arboles formados al eliminar su centroide, el centroide de un arbol
 * es un nodo u tal que si lo eliminas, este se divide en sub-arboles con un numero de nodos
 * no mayor a la mitad del original, todos los arboles tienen un centroide, y a lo mas 2.
 * Esto provoca que el arbol sea dividido en sub-arboles de distintos niveles de descomposicion,
 * por comodidad, un nodo v es un centroide ancestro de otro nodo u, si v, en algun nivel, fue el
 * centroide que separo al componente de u en sub-arboles.
 * Todo camino del arbol original se puede expresar como la concatenacion de dos caminos del tipo:
 * (u, A(u)), (u, A(A(u))), (u, A(A(A(u))))..., etc.
 * Ya que en cada nivel k el numero de nodos de algun componente es a lo mas |V| / 2^k, un nodo puede
 * estar en log |V| componentes, es decir, puede tener como maximo log |V| ancestros.
 * Tiempo: O(|V| log |V|)
 */

#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;

const int N = 1e5+20;
int n;
vector<int> adj[N];

int sz[N]; //tamaño del subarbol i
bool dead[N];

// dfs para encontrar el tamaño de los subarboles
int dfs(int u, int p=-1) {
    sz[u] = 1;
    for (int v : adj[u])
        if (v != p && !dead[v])
            sz[u] += dfs(v, u);
    return sz[u];
}

// dfs para encontrar el centroide
int getCentroid(int v, int tam, int p=-1){
    for(int u: adj[v])
        if(u != p && !dead[u] && 2 * sz[u] > tam)
            return getCentroid(u, tam, v);
    return v;
}

// construir el arbol de centroides
void build(int u) {
    int centroid = getCentroid(u, dfs(u, u) );

    //Hacer algo con el centroide

    dead[centroid] = true;

    for (int v : adj[centroid])
        if (!dead[v])
            build(v);
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n;
    for(int i=1;i<n;i++){
        int a, b;
        cin>>a>>b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    build(0);

  return 0;
}