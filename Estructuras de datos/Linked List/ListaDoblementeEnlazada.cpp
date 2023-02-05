#include <iostream>

using namespace std;

struct Node{
    int dato;
    Node *prev;
    Node *next;
};

void insertar(Node*&,int);

int main(){

    Node* lista=NULL;


    return 0;
}

void insertar(Node *&lista, int n){
    Node *nuevoNodo= new Node();
    nuevoNodo->dato=n;

    Node *aux1=lista;
    Node *aux2;

    if(lista==NULL){
        
    }
}