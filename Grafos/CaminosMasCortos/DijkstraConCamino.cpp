#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> P_ii;

int INF=1<<28;

void printPath(int parent[],int j){
    if(parent[j]==-1)
        return;
    printPath(parent,parent[j]);
    cout<<j<<" ";
}

int dijkstra(vector<P_ii> adj[], int begin, int end, int n){
    priority_queue<P_ii, vector<P_ii>, greater<P_ii> > pq;
    vector<int> dist(n+1,INF);
    int parent[n+1];
    parent[begin]=-1;
    dist[begin]=0;
    pq.push({0,begin});
    while(!pq.empty()){
        int a=pq.top().second; pq.pop();
        for(auto u:adj[a]){
            int b=u.first, w=u.second;
            if(dist[a]+w<dist[b]){
                dist[b]=dist[a]+w;
                pq.push({dist[b],b});
                parent[b]=a;
            }
        }
    }
    cout<<begin<<" ";
    printPath(parent,end);
    cout<<endl;
    return dist[end];
}

int main(){
    return 0;
}