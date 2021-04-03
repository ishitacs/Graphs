#include <bits/stdc++.h>

using namespace std;
class Graph{ int v;
list<int>*l;
public: Graph(int v){this->v=v; l= new list<int>[v];}
void addEdge(int x,int y){
l[x].push_back(y);
}
void topsort()
{
    int *indegree=new int[v];
    for(int i=0;i<v;i++)
    {indegree[i]=0;
        for(auto y:l[i]){indegree[y]++;}

} queue<int>q;
for(int i=0;i<v;i++){if(indegree[i]==0) q.push(i);}
while(!q.empty())
{
    int node=q.front();
    cout<<node<<" ";
    q.pop();
    for(auto nbr:l[node]){indegree[nbr]--;
    if(indegree[nbr]==0) q.push(nbr);
       }
}
}

};
int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topsort();
    return 0;
}
