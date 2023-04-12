// https://cses.fi/problemset/task/1192/
#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'
#define FOR(x, b) for(int x = 0; x <b; x++)
typedef long long ll;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
const ll MOD = 1e9+7, INF=1e18, template_array_size = 1e6;
ll n, m, q, k, l, r, x, y, z, ans=0;

int arr[1001][1001];
bool visited[1001][1001];
const int ax[]{0, 1, 0, -1};
const int ay[]{1, 0, -1, 0};
void floodfill(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m) return;
    if(visited[i][j] || arr[i][j]) return;

    visited[i][j]=true;
    for(int x=0;x<4;x++){
        floodfill(i+ax[x],j+ay[x]);
    }
}


int main(){ _
    cin>>n>>m;
    FOR(i,n){
        FOR(j,m){
            char c;
            cin>>c;
            if(c=='#'){
                arr[i][j]=1;
            }else{
                arr[i][j]=0;
            }
        }
    }

     FOR(i,n){
        FOR(j,m){
            if(!visited[i][j] && arr[i][j]==0){
                ans++;
                floodfill(i,j);
            }
        }
    }
    cout<<ans<<ENDL;

  return 0;
}