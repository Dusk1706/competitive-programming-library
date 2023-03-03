#include <iostream>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;
//Arbol ordenado menor o igual con elementos repetibles
template <class T>
using treeSet1 = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//Arbol ordenado de menor
template <class T>
using treeSet2 = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//Arbol ordenado de mayor
template <class T>
using treeSet3 = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

//Arbol ordenado de mayor o igual con elementos repetibles
template <class T>
using treeSet4 = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){

    treeSet4<int>os;
    os.insert(10);
    os.insert(1);
    os.insert(20);
    os.insert(15);
    os.insert(20);
    for(auto i: os){
        cout<<i<<" ";
    }
    cout<<endl;
    os.erase(20); //Solo borra cuando no hay elementos repetibles

    cout<<os.order_of_key(20)<<endl;//Retorna N numeros menores que K

    cout<<*os.find_by_order(0)<<endl;//Retorna un iterador del elemento en la posicion K

     for(auto i: os){
        cout<<i<<" ";
    }

    return 0;
}

