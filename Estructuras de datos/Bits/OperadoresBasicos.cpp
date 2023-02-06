#include <bits/stdc++.h>

using namespace std;

int main(){

    /*  Binario AND & prende los bits que tengan en comun
        0 & 0 = 0
        1 & 0 = 0
        0 & 1 = 0
        1 & 1 = 1

        5 = 00000101
        7 = 00000111
       &  -------------
            00000101 = 5
    */

   /*  Binario OR | prende los bits encendidos
        0 & 0 = 0
        1 & 0 = 1
        0 & 1 = 1
        1 & 1 = 1

        5 = 00000101
        7 = 00000111
       |  -------------
            00000111 = 7
    */

   /*  Binario XOR ^ prende los bits que sean diferentes
        0 & 0 = 0
        1 & 0 = 1
        0 & 1 = 1
        1 & 1 = 0

        5 = 00000101
        7 = 00000111
       ^  -------------
            00000010 = 2
    */

   /*  Binario NOT ~ Operador unitario invierte cada bit
       (incluyendo el bit del signo positivo o negativo) 
        ~0 = 1
        ~1 = 0
        
        Formula  ~N  = -(N + 1)
        ~ 5  = -(5 + 1)  = -6
        ~ -6 = -(-6 + 1) = 5
    */

    return 0;
}