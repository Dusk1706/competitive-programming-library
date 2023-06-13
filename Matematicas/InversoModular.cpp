#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'
typedef long long ll;
ll MOD = 1e9+7;

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

int main(){

    ll a, b;
    cin>>a>>b;
    cout<<inv_mod(a, b)<<ENDL;


  return 0;
}