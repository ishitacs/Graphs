#include <bits/stdc++.h>

using namespace std;
vector<int> bellman(int v,int src,vector<vector<int>>edges)
{
    vector<int> dis(v+1,INT_MAX);//store distance
dis[src]=0;
for(int i=0;i<v-1;i++){ //relaxation
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];
        if(dis[u]!=INT_MAX /*avoid overflow*/ && dis[u]+wt < dis[v]){
            dis[v]=dis[u] + wt;
        }
    }
    //negative wt cycle
     for(auto edge:edges){
            int u=edge[0];
        int v=edge[1];
        int wt=edge[2];
             if(dis[u]!=INT_MAX /*avoid overflow*/ && dis[u]+wt < dis[v])
             {cout<<"negative wt cycle"<<endl; exit(0);}

     }
} return dis;
}


int main()
{int n,m; //edges and vertices
cin>>n>>m;

vector<vector<int>> edges;
for(int i=0;i<m;i++)
{
    int u,v,wt;
    cin>>u>>v>>wt;
    edges.push_back({u,v,wt});
}
vector<int> d= bellman(n,1,edges);
for(int i=1;i<=n;i++)
{
    cout<<"node "<<i<<" is at a distance "<<d[i]<<endl;
}
/* i/p:3 3
1 2 3
2 3 4
1 3 -10
o/p: node 1 is at a distance 0
node 2 is at a distance 3
node 3 is at a distance -10*/

    return 0;
}
