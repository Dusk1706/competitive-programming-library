// Codigo para saber si sumando elementos de un arreglo es posible conseguir
// como resultado un numero n. Se pueden repetir elementos del arreglo

#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'
#define f first
#define s second
#define all(s) begin(s), end(s)
#define rall(n) n.rbegin(), n.rend()
#define FOR(x, b) for(int x = 0; x <b; x++)
#define FORE(x, a, b) for(int x = a; x <= b; x++)
#define FORR(x, a, b) for(int x = a; x >= b; x--)
#define deb(x)      cerr << #x << " = " << x << '\n';
#define deb2(x, y)  cerr << #x << " = " << x << ", " << #y << " = " << y << '\n';
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll MOD = 1e9+7, INF=1e18;
ll gcd(ll a, ll b){return (b?gcd(b,a%b):a);}
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }

unordered_map<ll,bool> memo;

bool canSum(ll sum, vll arr){
    if(memo[sum])   return memo[sum];
    if(sum<0)       return false;
    if(sum==0)      return true;
    
    for(auto k:arr)
        if(canSum(sum-k,arr))
            return memo[sum]=true;

    return false;
}

void solve(int tc=0){
    cout<<canSum(300,{5,6,3})<<ENDL;    //Output: True
    memo.clear();
    cout<<canSum(17,{6,8,2})<<ENDL;     //Output: False
}

int main(){_
    int tc=1;
    // cin>>tc;
    for(int t=0;t<tc;t++){
        solve(t);
    }
    return 0;
}