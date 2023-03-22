// Codigo para contar el número de maneras de poder llegar desde la esquina
// superior izquierda de un tablero m*n hasta la esquina inferior derecha

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
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
ull dp[100][100];

ull gridTraveller(long long n,long long m){
    if(dp[n][m]!= 0) return dp[n][m];
    if(n==1 || m==1) return 1;
    if(n==0 || m==0) return 0;
    dp[n][m]=gridTraveller(n-1,m)+gridTraveller(n,m-1);
    dp[m][n]=dp[n][m];
    return dp[n][m];
}
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cout<<gridTraveller(1,2)<<endl;
    cout<<gridTraveller(1,10)<<endl;
    cout<<gridTraveller(8,1)<<endl;
    cout<<gridTraveller(30,20)<<endl;
    return 0;
}