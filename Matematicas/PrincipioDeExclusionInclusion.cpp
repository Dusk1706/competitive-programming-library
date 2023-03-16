/*
    Cuando un evento A se puede realizar de m maneras diferentes, y otro evento B se
    puede realizar de n maneras diferentes, pero es posible ambos eventos ocurran de 
    la misma manera. |A ⋃ B| = |A| + |B| - |A ∩ B|
    El como programar esto obviamente varía del problema, y la formula indicada es 
    solo la versión mas simple de esta, ya que existen más posibilidades aún.
    
    El problema da contexto de que debes ayudar a un payaso de los números divertidos
    un número es divertido cuando es divisible entre uno de ciertos números, por lo 
    que dado una n cantidad de números, un limite x, debes de decir cuántos números 
    divisibles entre los n números hay el rango d 1 a x.

    Para saber cuántos números divisibles hay en el rango primero que nada hay que 
    mantener en el arreglo solo números coprimos, de tal manera que, si hay dos 
    números que sean coprimos entre sí, tomaremos el menor, y desecharemos el otro. 
    Esto lo hacemos ordenando los números de un principio, y luego con un bucle 
    recorrerlos e ir descartando todos los otros que se puedan dividir por el número 
    actual. Ya con este nuevo arreglo se hace recursivamente el proceso de inclusión 
    exclusión, siguiendo la lógica de que para saber cuantos números múltiplos de x 
    hay en al rango de 1 a n, solo se tiene que hacer la división de n / x. 
    Ahora si tenemos que hacerlo con tres números a, b y c, la formula seria la siguiente.
    Res = n / a + n / b + n / c – (n / ab + n / ac + n / bc) + (n / abc)
    Como podemos ver n se va dividiendo por todas las combinaciones de multiplicaciones 
    posibles y se va alternando la suma y la resta, por lo que podemos aplicar esta 
    lógica de manera recursiva.
*/

#include<bits/stdc++.h>
#define MAX 25

using namespace std;

typedef long long ll;

ll num[MAX];
int s = 0;
ll cop[MAX];

ll comb(ll x, int k, ll sig){
    if(k == s){
        return 0;
    }

    ll res = 0;
    for(int i = k; i < s; i++){
        res += (sig * (x / cop[i]));
        res += comb(x / cop[i], i + 1, -sig);
    }

    return res;
}
int main(){
    int n;
    ll x;

    scanf("%d %lld", &n, &x);

    for(int k = 0; k < n; k++){
        scanf("%lld", &num[k]);
    }

    sort(num, num + n);

    for(int k = 0; k < n; k++){
        if(num[k] != -1){
            cop[s] = num[k];
            s++;
            for(int j = k + 1; j < n; j++){
                if(num[j] % num[k] == 0){
                    num[j] = -1;
                }
            }
        }
    }

    ll res = comb(x, 0, 1);
    printf("%lld\n", res);

    return 0;
}
