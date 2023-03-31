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
typedef vector<int> vi;
typedef vector<ii> vii;
const ll MOD = 1e9+7, INF=1e18, template_array_size = 1e6;
ll n, m, q, k, l, r, x, y, z, ans=0;
string s,t;

int dp[1001];
int main(){ _
    freopen("lepus.in","r",stdin);
    freopen("lepus.out","w",stdout);
    memset(dp,-1,sizeof dp);

    string s;
    cin >> n >> s;

    const char pantano = 'w';
    const char vacio = '.';
    const char grass = '"';
    dp[0]=0;
    for (int i = 1; i < n; ++i) {
      if (s[i] != pantano) {
        const int punto = s[i] == grass;
        if (dp[i - 1] != -1) {
            dp[i] = max(dp[i], dp[i - 1] + punto);
        }
        if (3 <= i && dp[i - 3] != -1) {
            dp[i] = max(dp[i], dp[i - 3] + punto);
        }
        if (5 <= i && dp[i - 5] != -1) {
          dp[i] = max(dp[i], dp[i - 5] + punto);
        }

      }
    }

    cout << dp[n - 1];

    return 0;
}