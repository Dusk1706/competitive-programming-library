// https://atcoder.jp/contests/dp/tasks/dp_a

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
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
const ll MOD = 1e9+7, INF=1e6, template_array_size = 1e6;
ll n, m, q, k, l, r, x, y, z, ans=0;

ll dp[100001];

int main(){ _

    cin>>n;
    ll h[n+1];
    FORE(i,1,n){
        cin>>h[i];
    }
    memset(dp,INF,sizeof dp);
    dp[1]=0;
    FORE(i,1,n){
        if(i+1<=n){
            dp[i+1]= min(dp[i+1], dp[i] + abs(h[i]-h[i+1]));
        }
        if(i+2<=n){
            dp[i+2]= min(dp[i+2], dp[i] + abs(h[i]-h[i+2]));
        }
    }
    cout<<dp[n]<<ENDL;


  return 0;
}