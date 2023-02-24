#include <bits/stdc++.h>

using namespace std;

int main(){

    char numero1 ='0';
    if(isdigit(numero1)){
        cout<<"0 es digito"<<endl;
    }

    vector<int> arreglo={1,2,3};
    if(is_sorted(arreglo.begin(),arreglo.end())){//Con arreglo statico es (arreglo,arreglo+n)
        cout<<"Arreglo ordenado"<<endl;
    }







    return 0;
}