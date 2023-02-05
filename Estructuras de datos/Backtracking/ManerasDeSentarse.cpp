#include <bits/stdc++.h>

using namespace std;

//Problema dado N personas de color cuantas formas puedes sentarlos en las sillas
//Nodo indica en que nivel estamos
//N= personas a asignar en las sillas
//De la cola pasa personas a la pila hasta encontrar una solucion

void mostrarPila(stack<char> pila){
    stack<char> aux;
    while(!pila.empty()){
        cout<<pila.top()<<" ";
        aux.push(pila.top());
        pila.pop();
    }
    while(!aux.empty()){
        pila.push(aux.top());
        aux.pop();
    }
    cout<<"\n";
}

void backtrack(int nodo, int n, stack<char>pila, queue<char>cola){
    if(nodo==n){ //Si estamos en el nivel del arbol == N hay una solucion
        mostrarPila(pila);
    }else{
		//Verificamos que se cumpla las restriciones Nivel 1 no puede haber amarillos 
        //y nivel 0 no puede haber rojo
		if(!((nodo==1 && cola.front()=='a') || (nodo==0 && cola.front()=='r'))){
			//Metemos un objeto a la pila 
			pila.push(cola.front());
			cola.pop();				
			//Con cada llamada recursiva nos movemos hacia
			//abajo del arbol osea en profundidad
			backtrack(nodo+1,n,pila,cola);
			//sacamos un objeto de la pila
			cola.push(pila.top());
			pila.pop();
			}else{
				cola.push(cola.front());
				cola.pop();
			}
    }
}

int main(){
    queue<char>cola;
    stack<char>pila;
    //A=Amarillo, R=Rojo, N=Negro
    cola.push('A');
    cola.push('N');
    cola.push('R');
    int nodo=0;
    backtrack(nodo,cola.size(),pila,cola);
    return 0;
}