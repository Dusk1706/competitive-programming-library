// El problema es simple, te dan una cadena y tienes que imprimir todas sus permutaciones posibles.

#include <bits/stdc++.h>
 
using namespace std;

string pal = "", gen = "";
int N;
int c = 0;
void comb(int n){
    if(n == N){
        c++;
        cout << gen << "\n";
        return;
    }
    for(int i = 0; i < N; i++){
        if(pal[i] != '\0'){
            gen[n] = pal[i];
            char ax = pal[i];
            pal[i] = '\0';
            comb(n + 1); 
            pal[i] = ax;
        }
    }
}
 
int main() {
    cin >> pal;
    gen = pal;
    N = pal.length();
    comb(0);

    cout << c << "\n";

    return 0;
}
