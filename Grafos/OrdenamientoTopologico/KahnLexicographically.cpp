#include <bits/stdc++.h>
using namespace std;

#define P_ii pair<int,int>
#define INF 1<<28

void topologicalSort(vector<int> adj[], int n){
    vector<int> indeg(n,0);
    for(int i=0;i<n;i++){
        for(auto u:adj[i])
            indeg[u]++;
    }
    multiset<int> ms;
    for(int i=0;i<n;i++){
        if(indeg[i]==0)
            ms.insert(i);
    }
    int c=0;
    vector<int> topOrder;
    while(!ms.empty()){
        int u=*ms.begin();
        ms.erase(ms.begin());
        topOrder.push_back(u);
        for(auto k:adj[u]){
            if(--indeg[k]==0)
                ms.insert(k);
        }
        c++;
    }
    if(c!=n){
        cout<<-1;
        return;
    }
    for(int i=0;i<n;i++)
        cout<<topOrder[i]<<" ";
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
    topologicalSort(a,n);
    return 0;
}