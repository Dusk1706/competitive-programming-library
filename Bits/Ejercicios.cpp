#include<bits/stdc++.h>

using namespace std;

//Devuelve verdadero si es impar
bool esImpar(int n){
    return n&1;
}

//Devuelve verdadero si N es potencia de 2
bool esPotencia2(int n){
    return (n&(n-1))==0;
}
/*Devuelve verdadero si N es potencia de 4
    Este numero 1431655765 se debe a que en binario es
    1010101010101010101010 1 0 1 0 1 0 1 0 1
                    <----- 8 7 6 5 4 3 2 1 0  
    y la potencia de 4 existe si hay un entero N == 4^x
*/
bool esPotencia4(int n){
    return (n&(n-1))==0  && (1431655765&n)==n && n>3;
}

int main(){
    int n=16;
    cout<<esPotencia2(n)<<endl;
    cout<<esPotencia4(n)<<endl;

    return 0;
}