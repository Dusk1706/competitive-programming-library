// https://codeforces.com/gym/104252/problem/E
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
#define deb3(x, y,z)  cerr << #x << " = " << x << ", " << #y << " = " << y <<" , "<< #z << " = " << z << '\n';
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;

const ll MOD = 1e9+7, INF=1e18;
ll n,e, k, l, r, x, y, z;
 
ll ans = 0;
bool tiles[1001];
//Espacios Izquierda Ficha K Espacios derecha
//6 2 2
//Izquierda 2 espacios Derecha 2 Espacios
//Ficha =1
//
ll backtracking(int espaciosI,int espaciosD, int ficha,ll restante){
    for(int i=ficha;i>=1;i--){
        if(tiles[i] || (i>espaciosI && i>espaciosD)){
            continue;
        }
        tiles[i]=true;
        ll izq=INF,der=INF,sin=INF;
        int resta=i-1;
        if(i<=espaciosI){
            izq=backtracking(espaciosI-i, espaciosD,resta,restante-i);
        }
        if(i<=espaciosD){
            der=backtracking(espaciosI, espaciosD-i,resta,restante-i);
        }
        sin=backtracking(espaciosI, espaciosD,i--,restante);
        return min(min(izq,der),sin);
    }
    return restante;
}

void solve(int tc=0){
    cin >> n >> k >> e;  
    
    int izq=e, der=n-k-e;
    tiles[k] = true;
    cout << backtracking(izq,der,max(izq,der),izq+der)<<ENDL;
}

int main(){_
    int tc=1;
    // cin>>tc;
    for(int t=0;t<tc;t++){
        solve(t);
    }
    return 0;
}