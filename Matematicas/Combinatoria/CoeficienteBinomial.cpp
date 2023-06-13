#include <iostream>
using namespace std;
using ll = long long;

const int MAXN = 1e6;
const int MOD = 1e9 + 7;

ll mcdExt(ll a, ll b){
	ll r,y=0,x1=0,y1=1,tx,ty;
	ll x=1;
	while(b>0){
		r=a%b;
		tx=x1, ty=y1;
		x1=x-(a/b)*x1;
		x=tx;
		y1=y-(a/b)*y1;
		y=ty;
		a=b;
		b=r;
	}
	return x;
}

ll inv_mod(ll a, ll b){//Se usa cuando hay division y modulos
	ll x = mcdExt(b, MOD);
	x=(x + MOD) % MOD;
	return (a * x) % MOD;
}

ll nck(ll num,ll den){
	ll a=num,b=den;
	while(num--){
		a=((a%MOD) * (num%MOD))%MOD;
		b=
	}


}


int main() {
	int n;
	cin >> n;
	ll izq=nck(2*n,n);
	ll der=nck(2*n,n-1);
	ll res=izq-der;
	
}