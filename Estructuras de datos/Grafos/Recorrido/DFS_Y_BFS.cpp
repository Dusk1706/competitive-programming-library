#include<bits/stdc++.h> 
using namespace std;

void dfs(vector<int> a[],int node, bool v[]){
    if(v[node]){
        return;
    }
    v[node]=true;
    //process node
    //cout<<node<<" ";
    for(auto u : a[node]){
        dfs(a,u,v);
    }
}

void bfs(vector<int> a[],int n){
    queue<int> q;
    bool v[n];
    //int dist[n];
    for(int i=0;i<n;i++)
        v[i]=false;
    //start=0
    v[0]=true;
    q.push(0);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        //proccess node
        cout<<node<<" ";
        for(auto u:a[node]){
            if(v[u])
                continue;
            v[u]=true;
            //dist[u]=dist[node]+1;
            q.push(u);
        }
    }
}

int main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int n,v,h,val;
    cin>>n;
    vector<int> a[n];
    for(int i=0;i<n;i++){
        cin>>v>>h;
        for(int j=0;j<h;j++){
            cin>>val;
            a[v].push_back(val);
        }
    }
    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    bfs(a,n);
    cout<<endl;
    dfs(a,0,visited);
    return 0;
}