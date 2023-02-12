#include <bits/stdc++.h>

using namespace std;

int n,k;
int numeros[110];
unsigned long long memo[110][1050];

unsigned long long subconjuntos(int posicion, int suma) {
  
  if(suma>1000) return 0;
  if (posicion == n) return suma == k && n!=0;
  if (memo[posicion][suma] != -1) return memo[posicion][suma];

  unsigned long long res = 0;
  res += subconjuntos(posicion + 1, suma);
  res += subconjuntos(posicion + 1, suma + numeros[posicion]);

  return memo[posicion][suma] = res;
}

int main() {
    memset(memo, -1, sizeof memo);
    cin >> n >> k;
  
    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    cout << subconjuntos(0, 0) << endl;

    return 0;
}