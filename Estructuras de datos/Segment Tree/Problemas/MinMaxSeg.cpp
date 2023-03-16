#include <bits/stdc++.h>

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
const ll MOD = 1e9+7, INF=1e18, array_size = 1e6;
string s, t;
ll n, m, q, k, l, r, x, y, z;

struct segmenttree {
	int n;
	vector<pair<int,int>> st;

	void init(int _n) {
		this->n = _n;
		st.resize(4 * n, {0,0});
	}

	void build(int start, int ending, int node, vector<ii> &v) {
		// leaf node base case
		if (start == ending) {
			st[node] = v[start];
			return;
		}

		int mid = (start + ending) / 2;

		// left subtree is (start,mid)
		build(start, mid, 2 * node + 1, v);

		// right subtree is (mid+1,ending)
		build(mid + 1, ending, 2 * node + 2, v);

		st[node] = {min(st[node * 2 + 1].first,st[node * 2 + 2].first),max(st[node * 2 + 1].second,st[node * 2 + 2].second)};
	}

	ii query(int start, int ending, int l, int r, int node) {
		if (start > r || ending < l) {  // No se ocupa este rango
			return {INT_MAX,-5};
		}
		if (start >= l && ending <= r) {// Se ocupa todo el rango
			return st[node];
		}
		// Se ocupa parte del rango
		int mid = (start + ending) / 2;
		pair<int,int> q1 = query(start, mid, l, r, 2 * node + 1);
		pair<int,int> q2 = query(mid + 1, ending, l, r, 2 * node + 2);
		return {min(q1.first,q2.first),max(q1.second,q2.second)};
	}

	void update(int start, int ending, int node, int index, int value) {
		// base case
		if (start == ending) {
			st[node] = {value,value};
			return;
		}
		int mid = (start + ending) / 2;
		if (index <= mid) {
			update(start, mid, 2 * node + 1, index, value);
		}else {
			update(mid + 1, ending, 2 * node + 2, index, value);
		}
		st[node] = {min(st[node * 2 + 1].first,st[node * 2 + 2].first),max(st[node * 2 + 1].second,st[node * 2 + 2].second)};
		return;
	}

	void build(vector<ii> &v) {
		build(0, n - 1, 0, v);
	}

	ii query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}

	void update(int x, int y) {
		update(0, n - 1, 0, x, y);
	}
};
int main() {_
  cin>>n>>m;
  vector<ii> A(n);
  FOR(i,n){
		cin>>x;
    A[i]={x,x};
	}
  segmenttree st;
  st.init(n);	
  st.build(A);
  FOR(i,m){
		char c;
		cin>>c;
		if(c=='C'){
			cin>>l>>r;
      ii an=st.query(l-1,r-1);
      cout<<an.first<<" "<<an.second<<ENDL;
		}else{
			cin>>l>>x;
			st.update(l-1,x);
		}
	}

  	return 0;
}