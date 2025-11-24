#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int u, vector<vector<int>>& g, vector<int>& vis){
    cout<<u<<" ";
    vis[u]=1;
    for(int v:g[u]) if(!vis[v]) dfs(v,g,vis);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int start; cin>>start;

    vector<int> vis(n,0);
    cout<<"BFS: ";
    queue<int> q;
    q.push(start); vis[start]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<" ";
        for(int v:g[u]){
            if(!vis[v]){ vis[v]=1; q.push(v);}
        }
    }
    cout<<endl;

    fill(vis.begin(),vis.end(),0);
    cout<<"DFS: ";
    dfs(start,g,vis);
    cout<<endl;
}
