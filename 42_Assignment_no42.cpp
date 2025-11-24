#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];

    int start;
    cin >> start;

    vector<int> vis(n,0);
    queue<int> q;
    q.push(start);
    vis[start]=1;
    cout << "BFS: ";
    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<" ";
        for(int v=0;v<n;v++){
            if(a[u][v] && !vis[v]){
                vis[v]=1;
                q.push(v);
            }
        }
    }
    cout<<endl;

    fill(vis.begin(),vis.end(),0);
    stack<int> st;
    st.push(start);
    cout << "DFS: ";
    while(!st.empty()){
        int u=st.top(); st.pop();
        if(vis[u]) continue;
        vis[u]=1;
        cout<<u<<" ";
        for(int v=n-1;v>=0;v--){
            if(a[u][v] && !vis[v]) st.push(v);
        }
    }
    cout<<endl;
}
