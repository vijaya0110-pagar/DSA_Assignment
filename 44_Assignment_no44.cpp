#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{int u,v,w;};

int findParent(vector<int>& p,int x){ return p[x]==x?x:p[x]=findParent(p,p[x]); }

int main(){
    int n,m;
    cin>>n>>m;
    vector<Edge> edges(m);
    for(int i=0;i<m;i++)
        cin>>edges[i].u>>edges[i].v>>edges[i].w;

    sort(edges.begin(),edges.end(),[](Edge a, Edge b){ return a.w < b.w; });

    vector<int> p(n);
    for(int i=0;i<n;i++) p[i]=i;

    for(auto e:edges){
        int u=findParent(p,e.u);
        int v=findParent(p,e.v);
        if(u!=v){
            cout<<e.u<<" - "<<e.v<<" "<<e.w<<endl;
            p[u]=v;
        }
    }
}
