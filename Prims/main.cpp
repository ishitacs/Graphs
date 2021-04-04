#include <bits/stdc++.h>

using namespace std;
class Graph{
 vector<pair<int,int>>*l;
 int v;
 public:
     Graph(int v){
     this->v=v;
     l=new vector<pair<int,int>>[v]; //node, wt
     }
void addEdge(int x,int y,int w)
{
    l[x].push_back({y,w});
     l[y].push_back({x,w});
}
int primmst(){
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>Q;
bool *vis=new bool[v]{0};
int ans=0;

Q.push({0,0});// wt, node of src
while(!Q.empty())
{
    auto miniwt=Q.top();
    Q.pop();
    int to= miniwt.second;
    int wt=miniwt.first;
    if(vis[to]) continue; //discard the edge if already visited
    ans+=wt; //add wt
    vis[to]=1; //mark visited
    for(auto x:l[to]){ //add new edges in queue
        if(vis[x.first]==0)//if not visited
            {Q.push({x.second,x.first}); //push new active edge: wt of element, node
                                   }
    }
}
return ans; }


};
int main()
{ int n,m;
cin>>n>>m;
Graph g(n);
for(int i=0;i<m;i++){
    int x,y,w;
    cin>>x>>y>>w;
    g.addEdge(x-1,y-1,w);
}
cout<<g.primmst()<<endl;

    return 0;
}
