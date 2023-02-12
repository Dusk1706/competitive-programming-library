#include <bits/stdc++.h>

using namespace std;
#define ENDL '\n'
#define f first
#define s second
#define all(s) begin(s), end(s)
#define rall(n) n.rbegin(), n.rend()
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define deb(x)      cerr << #x << " = " << x << '\n';
#define deb2(x, y)  cerr << #x << " = " << x << ", " << #y << " = " << y << '\n';
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

const ll MOD = 1e9+7, INF=1e18;
ll gcd(ll a, ll b){return (b?gcd(b,a%b):a);}
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
const ll template_array_size = 1e6;
ll a[template_array_size];
ll b[template_array_size];
string s, t;
ll n, m, q, k, l, r, x, y, z;
 
ll ans = 0;

void solve(int tc=0){
    ans=0;


    
    cout<<ans<<ENDL;
}

int main(){_
    int tc=1;
    // cin>>tc;
    for(int t=0;t<tc;t++){
        solve(t);
    }
    return 0;
}