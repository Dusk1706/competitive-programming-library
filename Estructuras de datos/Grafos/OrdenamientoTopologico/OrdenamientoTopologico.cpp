#include <bits/stdc++.h>
using namespace std;

#define P_ii pair<int,int>
#define INF 1<<28

stack<int> st;

void dfs(vector<int> a[],int node, int v[]){
    if(v[node]==2){
        return;
    }
    if(v[node]==1){
        cout<<-1;
        exit(0);
    }
    v[node]=1;
    //cout<<node<<" ";
    for(auto u : a[node]){
        dfs(a,u,v);
    }
    v[node]=2;
    st.push(node);
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n,m,n1,n2;
    cin>>n>>m;
    vector<int> a[n+1];
    for(int i=0;i<m;i++){
        cin>>n1>>n2;
        a[n1].push_back(n2);
    }
    int v[n];
    for(int i=0;i<n;i++){
        v[i]=0;
    }
    for(int i=0;i<n;i++){
        dfs(a,i,v);
    }
    for(int i=0;i<n;i++){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}