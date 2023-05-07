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

int main(){ _
    //Numero de caminos para llegar de la esquina 
    // superior izquierda a la esquina inferior derecha
    cin>>n;
    char grid[n][n];
    FOR(i,n){
        FOR(j,n){
            cin>>grid[i][j];
        }
    }
    ll dp[n][n];
    
    memset(dp,0,sizeof(dp));
    dp[0][0]=grid[0][0]=='.';
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i+1<n && grid[i+1][j]=='.'){
                dp[i+1][j]+=dp[i][j];
                dp[i+1][j]%=MOD;
            }
            if(j+1<n && grid[i][j+1]=='.'){
                dp[i][j+1]+=dp[i][j];
                dp[i][j+1]%=MOD;
            }
                
        }
    }
    cout<<dp[n-1][n-1]<<ENDL;

  return 0;
}