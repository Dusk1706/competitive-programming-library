#include <bits/stdc++.h>

using namespace std;
#define P_ii pair<int,int>
#define INF 1<<28

vector<int> dijkstra(vector<ii> adj[], int begin, int n){
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    vector<int> dist(n+1,INF);
    dist[begin]=0;
    pq.push({0,begin});
    while(!pq.empty()){
        int a=pq.top().second; pq.pop();
        for(auto u:adj[a]){
            int b=u.first, w=u.second;
            if(dist[a]+w<dist[b]){
                dist[b]=dist[a]+w;
                pq.push({dist[b],b});
            }
        }
    }
    return dist;
}

int main(){
    return 0;
}