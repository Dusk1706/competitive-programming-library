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
typedef vector<vi> vvi;
const ll MOD = 1e9+7, INF=1e18, template_array_size = 1e6;

// Let A be an n*n order matrix and k the exponent, we can calculate A^k in O(log k * n^3)
// A * B = C, O(n^3)
vvi matrixMultiplication(vvi &A, vvi &B) {
    int n = A.size(), m = A[0].size(), k = B[0].size();
    vvi C(n, vi(k, 0));

    FOR(i, n)
    FOR(j, k)
    FOR(l, m)
    C[i][j] += (A[i][l] * B[l][j]) % MOD;
    return C;
}
// A^k, O(log k * n^3)
vvi matrixExponentiation(vvi &A, ll k) {
    int n = A.size();
    // ret -> identity matrix
    vvi ret(n, vi(n)), B = A;
    FOR(i, n)
    ret[i][i] = 1;

    while (k) {
        if (k & 1)
            ret = matrixMultiplication(ret, B);
        k >>= 1;
        B = matrixMultiplication(B, B);
    }
    return ret;
}
// Another faster approach could be use structs with fixed matrices overloading the * operator

int main(){ _
    


  return 0;
}