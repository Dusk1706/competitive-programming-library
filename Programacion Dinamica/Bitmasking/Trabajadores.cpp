#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'
#define all(s) begin(s), end(s)
#define rall(n) n.rbegin(), n.rend()
#define FOR(x, b) for(int x = 0; x <b; x++)
#define FORE(x, a, b) for(int x = a; x <= b; x++)
#define FORR(x, a, b) for(int x = a; x >= b; x--)
#define deb(x)      cerr << #x << " = " << x << '\n';
#define deb2(x, y)  cerr << #x << " = " << x << ", " << #y << " = " << y << '\n';
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ll MOD = 1e9+7, INF=1e18, template_array_size = 1e6;
ll n, m, q, k, l, r, x, y, z, ans=0;
string s,t;

int cost[21][21];
int dp[21][1<<21];

int solve(int i,int mask){
    if(i==n) return 0;
    if(dp[i][mask]!=-1) return dp[i][mask];
    int ans=INF;
    FOR(j,n){//Recorrer trabajos
        
    }
    return dp[i][mask]=ans;
}

int main(){ _
    
    // Numero de trabajadores y trabajos N
    // Costo para un trabajador i hacer un trabajo j = cost[i][j]
    // Minimizar todos los trabajos a minimo costo
    // Max N = 20
    cin>>n;
    FOR(i,n){
        FOR(j,n){
            cin>>cost[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0)<<ENDL;


  return 0;
}