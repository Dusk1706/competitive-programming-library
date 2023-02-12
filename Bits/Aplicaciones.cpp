#include<bits/stdc++.h>

using namespace std;

//Obtiene el bit en cierto indice base 0 para base 1 poner i-1
int getBit(int n, int i){
    return (n & (1 << i))>0?1:0;
}

//Apagar el bit en cierto indice base 0 para base 1 poner i-1
void clearBit(int &n,int i){
    n &= ~(1 << i);
}

//Prender el bit en cierto indice base 0 para base 1 poner i-1
void setBit(int &n, int i){ 
    n |= (1 << i);
}

//Invierte el bit en cierto indice base 0 para base 1 poner i-1
int toggleBit(int n, int i){
    return (n ^ (1 << i));
}

//Borra los primeros bits pasado una longitud de bits a borrar
void clearFirstBits(int &n,int length){
    n&=(-1<<length);
}

//Borra los bits en el rango i a j con base 0 para base 1 poner i-1 y j-1
void clearBitRange(int &n,int i,int j){
    int mask= ((~0)<<(j+1)) | ((1<<i)-1);
    n&=mask;
}

int main(){
    int n=5;
    cout<<getBit(n,2)<<endl;
    clearBit(n,2);
    cout<<getBit(n,2)<<endl;
    cout<<toggleBit(n,2);
    clearFirstBits(n,1);
    cout<<n<<endl;

    return 0;
}