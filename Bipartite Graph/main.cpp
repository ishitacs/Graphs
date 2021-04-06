#include <bits/stdc++.h>

using namespace std;
bool dfshelp(vector<int> graph[],int node, int *visited,int parent,int color){
visited[node]= color; //1 or 2

for(auto nbr: graph[node])
    { if(visited[nbr]==0){
    int subprob=dfshelp(graph,nbr,visited,node,3-color);//flip color 3-1=2
    if(subprob==false) return false;
    } else if(nbr!=parent && color==visited[nbr]){return false;}

    }
    return true;
}
bool dfs(vector<int> graph[],int n)
{
    int visited[n]={0};
    int color=1;
   int ans= dfshelp(graph,0,visited,-1,color);
for(int i=0;i<n;i++){cout<<i<<" color "<<visited[i]<<endl;}
return ans;}
int main()
{  int N,M;
cin>>N>>M;
vector<int> graph[N];
while(M--){int x,y;
cin>>x>>y;
graph[x].push_back(y);
graph[y].push_back(x);
}
if(dfs(graph,N)){cout<<"yes, it is bipartite"<<endl;}
else cout<<"not bipartite"<<endl;
    return 0;
}
