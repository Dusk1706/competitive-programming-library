// http://www.usaco.org/index.php?page=viewproblem2&cpid=895
#include <bits/stdc++.h>
//Pura gente del coach moy
using namespace std;
#define ENDL '\n'
#define FOR(x, b) for(int x = 0; x <b; x++)
typedef long long ll;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
const ll MOD = 1e9+7, INF=1e18, template_array_size = 1e6;
ll n, m, q, k, l, r, x, y, z, ans=0;
const int ax[]{0, 1, 0, -1};
const int ay[]{1, 0, -1, 0};
int arr[1001][1001];
bool visited[1001][1001];

int maxArea=0,minPerimetro=0;
int perimetroActual=0,areaActual=0;

void floodfill(int i, int j){
    cout<<perimetroActual<<" "<<areaActual<<ENDL;
    if(i<0 || i>=n || j<0 || j>=m){
        perimetroActual++;
        cout<<"entra"<<ENDL;
        cout<<perimetroActual<<ENDL;
        return;
    }
    if(visited[i][j]) return;
    if(arr[i][j]==0){
        perimetroActual++;
        return;
    }
    visited[i][j]=true;
    if(arr[i][j]){
        areaActual++;
    }
    for(int x=0;x<4;x++){
        floodfill(i+ax[x],j+ay[x]);
    }
}


int main(){ _
    
    cin>>n;
    FOR(i,n){
        FOR(j,n){
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
        FOR(j,n){
            if(!visited[i][j] && arr[i][j]){
                floodfill(i,j);
                if(areaActual==maxArea){
                    minPerimetro=min(perimetroActual,minPerimetro);
                }else if(areaActual>maxArea){
                    maxArea=areaActual;
                    minPerimetro=perimetroActual;
                }
                areaActual=0,perimetroActual=0;
            }
        }
    }
    cout<<maxArea<<" "<<minPerimetro<<ENDL;

  return 0;
}