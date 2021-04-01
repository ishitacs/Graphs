#include <bits/stdc++.h>

using namespace std;

class Graph {
int v;
list<pair<int,int>>l;
public:
    Graph(int v){this->v=v;}
    int addEdge(int u,int y)
    {
        l.push_back(make_pair(u,v));
    }
int findd(int i,int parent[])
{
    if(parent[i]==-1) return i;
    else findd(parent[i],parent);
}
void unionn(int a,int b,int parent[])
{
    int s1=findd(a,parent);
    int s2=findd(b,parent);
    if(s1!=s2) parent[s1]=s2;
}
};


int main()
{ Graph g(4);
g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(3,4);
g.addEdge(4,1);
    return 0;
}
