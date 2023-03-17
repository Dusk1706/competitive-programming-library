/*
    Problema https://matcomgrader.com/problem/9553/looking-for-the-risk-factor/



*/
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

ll n, m, q, k, l, r, x, y, z;
ll ans = 0;

bitset<100005>bs;
vector<int>primes;
void sieve() {
	int n = 100005;
	bs.set(); 
	bs[0] = bs[1] = 0; 
	for(ll i = 2; i <= n; i++) 
		if(bs[i]){
			for(ll j = i * i; j <= n; j += i)
				bs[j] = 0;
			primes.push_back(i);//Opcional para almacenar los primos 
		}
}

struct segmenttree {
	int n;
	vector<int> st;

	void init(int _n) {
		this->n = _n;
		st.resize(4 * n, 0);
	}

	void build(int start, int ending, int node, vector<int> &v) {
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

		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
	}

	int query(int start, int ending, int l, int r, int node) {
		if (start > r || ending < l) {  // No se ocupa este rango
			return 0;
		}
		if (start >= l && ending <= r) {// Se ocupa todo el rango
			return st[node];
		}
		// Se ocupa parte del rango
		int mid = (start + ending) / 2;
		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, ending, l, r, 2 * node + 2);
		return q1 + q2;
	}

	void update(int start, int ending, int node, int index, int value) {
		// base case
		if (start == ending) {
			st[node] = value;
			return;
		}
		int mid = (start + ending) / 2;
		if (index <= mid) {
			// left subtree
			update(start, mid, 2 * node + 1, index, value);
		}else {
			// right
			update(mid + 1, ending, 2 * node + 2, index, value);
		}
		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
		return;
	}

	void build(vector<int> &v) {
		build(0, n - 1, 0, v);
	}

	int query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}

	void update(int x, int y) {
		update(0, n - 1, 0, x, y);
	}
};
segmenttree st;

int main(){_
	sieve();
	st.init(100005);
	vector<int>v(100005,1);
	v[0]=0;
	v[1]=0;
	st.build(v);

	cin>>q;
	vector<pair<ii,int>>queries;
	vector<int>ans(q);
	FOR(i,q){
		cin>>n>>k;
		queries.push_back({{k,n},i});
	}
	sort(queries.rbegin(),queries.rend());
	int primeIndex=primes.size()-1;
	FOR(i,q){
		int R,K;
		R=queries[i].first.second;
		K=queries[i].first.first;
		while(primeIndex>=0 && primes[primeIndex]>K){
			for(int j=primes[primeIndex];j<100005;j+=primes[primeIndex]){
				if(st.query(j,j)!=0){
					st.update(j,0);
				}
			}
			primeIndex--;
		}
		int ansT=st.query(2,R);
		ans[queries[i].second]=ansT;
	}
	for(auto x:ans){
		cout<<x<<ENDL;
	}


	return 0;
}