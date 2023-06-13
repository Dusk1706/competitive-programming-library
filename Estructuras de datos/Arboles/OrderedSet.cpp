#include <bits/stdc++.h>

using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;
template <class T> using Tree=
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*
(Posiciones indexadas en 0).
Funciona igual que un set (todas las operaciones en O(log n)), con 2 operaciones extra:
obj.find_by_order(k) - Retorna un iterador apuntando al elemento k-esimo mas grande
obj.order_of_key(x) - Retorna un entero que indica la cantidad de elementos menores a x

Modificar tercer parametro, que corresponde a la funcion de comparacion de valores (less<T>, greater<T>, less_equal<T> o incluso una implementada por nosotros)

Si queremos elementos repetidos, usar less_equal<T> (sin embargo, ya no servira la
funcion de eliminacion).

Si queremos elementos repetidos y necesitamos la eliminacion, utilizar una
tecnica con pares, donde el second es un numero unico para cada valor.
*/

// Implementacion
int main(){
    int n = 9;
    int arr[] = {2, 4, 7, 10, 15, 23, 50, 65, 71}; 
    Tree<int> tree;
    for (auto x: arr) // O(n log n)
        tree.insert(x);
    // O(log n) select
    cout << *tree.find_by_order(0) << "\n";     // 1-smallest = 2
    cout << *tree.find_by_order(n - 1) << "\n"; // 9-smallest/largest = 71
    cout << *tree.find_by_order(4) << "\n";     // 5-smallest = 15
    // O(log n) rank
    cout << tree.order_of_key(2) << "\n";  // index 0 (rank 1)
    cout << tree.order_of_key(71) << "\n"; // index 8 (rank 9)
    cout << tree.order_of_key(16) << "\n"; // index 4 (rank 5)

    return 0;
}
