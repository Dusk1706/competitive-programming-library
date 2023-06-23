/**
 * Algoritmo de Tarjan
 * 1 - Generar el grafo con init(Numero de nodos)
 * 2 - Añadir las aristas con indice 0 con el metodo addEdge(x,y)
 * 3 - Llamar el metodo gen
 * 
 * - El arreglo disc se utiliza para llevar un seguimiento del orden en que se descubren 
 *   los nodos durante el recorrido DFS
 * 
 * - El arreglo comp almacena a que SCC pertenece por ejemplo comp[3]=1 quiere decir
 *   que el nodo 3 pertenece al SCC el cual es lider el nodo 1 es util para saber a que
 * 	 SCC pertenece o saber si dos nodos pertenecen al mismo SCC
 * 
 * - El arreglo comps almacena el representante de cada SCC esta ordenada de manera que
 * 	 que los componentes fuertemente conectados se encuentran en el orden inverso en el 
 *   que fueron descubiertos durante el proceso de búsqueda. El primer nodo en comps 
 *   representa el líder del último componente fuertemente conectado descubierto.
 * 
 * - El arreglo st es una pila auxiliar se utiliza para almacenar temporalmente los nodos 
 *   visitados mientras se realiza la DFS en el grafo. 
 *   En el algoritmo, cuando un nodo X se visita por primera vez, se agrega a la pila st 
 *   A medida que se exploran los nodos adyacentes a A, se realizan llamadas recursivas a 
 *   la función dfs(y) para esos nodos.
 *   Cuando se identifica un líder de un SCC (cuando low == disc[x]), se extraen los nodos 
 *   de la pila st hasta que se encuentra el líder X. Durante este proceso, se asigna el 
 *   componente x a cada nodo extraído de la pila.
 * 
 * - Usa menos memoria que Kosaraju porque no almacena el grafo al revez
 * - Complejidad: O(N+M)
 */
struct SCC {
	int N, ti = 0;
	vector<vector<int>> adj;
	vector<int> disc, comp, st, comps;
	void init(int _N) {
		N = _N;
		adj.resize(N), disc.resize(N), comp = vector<int>(N, -1);
	}
	void addEdge(int x, int y) { adj[x].push_back(y); }
	int dfs(int x) {
		int low = disc[x] = ++ti;
		st.push_back(x);  // disc[y] != 0 -> in stack
		for (int y : adj[x])
			if (comp[y] == -1) low = min(low, disc[y] ?: dfs(y));
		if (low == disc[x]) {  // make new SCC, pop off stack until you find x
			comps.push_back(x);
			for (int y = -1; y != x;){
				comp[y = st.back()] = x;
				st.pop_back();
			}
		}
		return low;
	}
	void gen() {
		for (int i = 0; i < N; i++)
			if (!disc[i]) dfs(i);
		reverse(comps.begin(), comps.end());
	}
};