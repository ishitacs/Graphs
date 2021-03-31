#include <bits/stdc++.h>

using namespace std;
class Graph{
int v;
list<int> *l;
public:
    Graph(int v){this->v=v;
        l=new list<int> [v];}
    void addedge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
void print(){
for(int i=0;i<v;i++)
{ cout<<"Vertex "<<i<<" -> ";
 for(int x:l[i]){cout<<x<<" , ";}
cout<<endl;}
}
};
int main()
{
    Graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(2,3);
    g.addedge(1,2);
    g.print();

    return 0;
}
