#include <iostream>
#include <map>

using namespace std;

int main(){

    //Creacion de un mapa
    map<string,int>ciudades;
    
    //Asignacion de un elemento
    ciudades["Mexico"]=4513546;

    /*
        Comprobar si un elemento existe con la funcion find() retorna un iterador y compara si
        la clave es igual al iterador, si es asi entonces no existe
    */
    if(ciudades.find("Clave")==ciudades.end()){
        cout<<"Este elemento no existe"<<endl;
    }

    //Para recorrer un map se utiliza un iterador dentro de un ciclo   
    map<string, int>::iterator iterador;
    for (iterador = ciudades.begin(); iterador != ciudades.end(); iterador++){
        // "first" tiene la clave. "second" el valor
        string clave = iterador->first;
        int valor = iterador->second;
        cout << "La clave " << clave << " tiene el valor " << valor << endl;
    }

    //Tambien se puede usar un for each
    for(const auto&kv : ciudades){
        cout<<"Clave "<<kv.first<<" tiene el valor "<<kv.second<<endl;
    }

    


}