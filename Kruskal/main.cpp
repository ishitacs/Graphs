#include <bits/stdc++.h>

using namespace std;
class Dsu{
    int *parent;
    int *Rank;
public:
    Dsu(int n)
    {parent=new int[n];
    Rank=new int[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=-1;
        Rank[i]=1;
    }
    }


    int Find(int i)
    {
        if(parent[i]==-1) return i;
         return parent[i]=Find(parent[i]);
    }
    void unite(int x,int y)
    {
        int s1= Find(x);
        int s2= Find(y);
        if(s1!=s2)
        {
            if(Rank[s1]<Rank[s2]){parent[s1]=s2; Rank[s1]+=Rank[s2];}
            else {parent[s2]=s1; Rank[s1]+=Rank[s2];}
        }
    }

};

class Graph{
vector<vector<int>> edgelist;
int v;
public:
    Graph(int v){this->v=v;}
    void addEdge(int x,int y,int w)
    {
        edgelist.push_back({w,x,y}); //will sorted acc to weight
    }
    int kruskalmst(){
        sort(edgelist.begin(),edgelist.end());
        Dsu d(v);
    int ans=0;
    for(auto edge: edgelist)
    {
        int w=edge[0];
        int x= edge[1];
        int y=edge[2];
        if(d.Find(x)!=d.Find(y)){
            d.unite(x,y);
            ans+=w;
        }
    }
return ans;}

};

int main()
{
     Graph g(4);
     g.addEdge(0,1,1);
     g.addEdge(1,3,3);
     g.addEdge(3,2,4);
     g.addEdge(2,0,2);
     g.addEdge(0,3,2);
     g.addEdge(1,2,2);
     cout<<g.kruskalmst()<<endl;
    return 0;
}
