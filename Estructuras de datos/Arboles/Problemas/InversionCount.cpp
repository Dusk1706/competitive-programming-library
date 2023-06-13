#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree=
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//Pura gente del coach moy
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

void solve(int tc=0){
    cin>>n;
    vector<int> v(n);
    Tree<int> st;
    FOR(i, n){
        cin>>v[i];
        st.insert(v[i]);
    }
    int ans=0;
    FOR(i, n){
        ans+=
    } 
    


    
}

int main(){_
    int tc=1;
    cin>>tc;
    for(int t=0;t<tc;t++){
        solve(t);
    }
    return 0;
}
