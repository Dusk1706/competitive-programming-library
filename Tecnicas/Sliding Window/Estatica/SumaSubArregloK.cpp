#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'
#define FOR(x, b) for(int x = 0; x <b; x++)
typedef long long ll;
typedef vector<int> vi;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
ll n, m, q, k, l, r, x, y, z, ans=0;

/*
    https://omegaup.com/arena/problem/Sumando-todos-los-subarreglos/#problems
    Dado un arreglo de N enteros y un entero K escribe un programa que 
    calcule la suma de cada subarreglo de tamaño K
    Input:
    5 2
    1 2 3 4 5
    Output:
    3 5 7 9
*/

int main(){ _
    
  cin>>n>>k;
  vi a(n);
  FOR(i,n) cin>>a[i];

  int sum=0;
  int i=0;
  int cta=0;
  for(int i=0;i<n;i++){
    sum+=a[i];
    cta++;
    if(cta==k){
      cout<<sum<<" ";
      sum-=a[i-k+1];
      cta--;
    }
  }

  return 0;
}