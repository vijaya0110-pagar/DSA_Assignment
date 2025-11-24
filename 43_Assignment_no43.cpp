#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> key(n,INT_MAX), parent(n,-1);
    vector<bool> inMST(n,false);
    key[0]=0;

    for(int i=0;i<n;i++){
        int u=-1,minKey=INT_MAX;
        for(int j=0;j<n;j++){
            if(!inMST[j] && key[j]<minKey){
                minKey=key[j]; u=j;
            }
        }
        if(u==-1) break;
        inMST[u]=true;
        for(auto [v,w]:adj[u]){
            if(!inMST[v] && w<key[v]){
                key[v]=w;
                parent[v]=u;
            }
        }
    }

    for(int i=1;i<n;i++)
        cout<<parent[i]<<" - "<<i<<" "<<key[i]<<endl;
}
