#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
// La exponenciación modular (x^n mod m) se puede hacer en complejidad O (log n).
ll modpow(ll x, ll n) {
  if (!n) return 1;
  ll u = modpow(x*x%MOD, n/2);
  if (n &1) u = (u * x) % MOD;
  return u;
}
int main(){
	ll x,y;
	cin>>x>>y;
	cout<<modpow(x,y)<<endl;
  return 0;
}