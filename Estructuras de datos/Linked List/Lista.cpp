#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

//Prototipo de funciones
void insertar(Nodo *&, int);
void mostrarLista(Nodo *);
void buscar(Nodo *, int);
void eliminar(Nodo *&,int);

int main(){

    Nodo *lista=NULL;
    insertar(lista,10);
    insertar(lista,5);   
    mostrarLista(lista);
    buscar(lista,10);
    eliminar(lista,10);
    mostrarLista(lista);
    return 0;
}

//Inserta elementos de forma ordenada
void insertar(Nodo *&lista, int n){
    Nodo *nuevoNodo= new Nodo();
    nuevoNodo->dato=n;

    Nodo *aux1=lista;
    Nodo *aux2;

    while((aux1!=NULL) && (aux1->dato<n)){
        aux2=aux1;
        aux1=aux1->siguiente;
    }

    if(lista == aux1){
        lista= nuevoNodo;
    }else{
        aux2->siguiente= nuevoNodo;
    }
    nuevoNodo->siguiente= aux1;
    cout<<"Elemento "<<n<< " insertado\n";
}

//Mostrar la lista entera
void mostrarLista(Nodo *lista){
    Nodo *actual=new Nodo();
    actual=lista;

    while(actual!=NULL){
        cout<<actual->dato<<" -> ";
        actual=actual->siguiente;
    }
    cout<<"NULL\n";
}

//Buscar un elemento en la lista
void buscar(Nodo *lista, int n){
    bool flag=false;

    Nodo *actual=new Nodo();
    actual=lista;

    while((actual !=NULL) && (actual->dato<=n)){
        if(actual->dato==n){
            flag=true;
            break;
        }
        actual=actual->siguiente;
    }
    if(flag){
        cout<<"Elemento encontrado\n";
    }else{
        cout<<"Elemento no encontrado\n";
    }
}

//Elimina un elemento en la lista
void eliminar(Nodo *&lista, int n){
    if(lista!=NULL){
        Nodo *auxBorrar;
        Nodo *anterior;

        auxBorrar=lista;

        while((auxBorrar!=NULL) && (auxBorrar->dato!=n)){
            anterior=auxBorrar;
            auxBorrar=auxBorrar->siguiente;
        }
        //El elemento no ha sido encontrado
        if(auxBorrar==NULL){
            cout<<"El elemento no ha sido encontrado\n";
        }else if(anterior==NULL){ //Primer elemento sera eliminado
            lista =lista->siguiente;
            delete auxBorrar;
        }else{//El elemento esta en la lista pero no el primer nodo
            anterior->siguiente=auxBorrar->siguiente;
            delete auxBorrar;
        }
    }
}
