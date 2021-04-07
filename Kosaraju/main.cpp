#include <bits/stdc++.h>

using namespace std;
void dfs(vector<int> graph[],int i,bool *visited,vector<int>&st)
{
visited[i]=true;
for(auto nbr: graph[i]){
    if(!visited[nbr])
        {
        dfs(graph,nbr,visited,st);} //function call is complete
} st.push_back(i);
}

void dfs2(vector<int> graph[],int i,bool *visited)
{
visited[i]=true;
cout<<i<<" ";
for(auto nbr: graph[i]){
    if(!visited[nbr])
        {
        dfs2(graph,nbr,visited);} //function call is complete
}
}
void solve(vector<int> graph[],vector<int> rev_graph[],int n){
bool visited[n];
memset(visited,0,n);
vector<int>st;
//need to store the vertices acc to dfs finish time
for(int i=0;i<n;i++){
    if(!visited[i]){dfs(graph,i,visited,st);
    }
}
//ordering= stack

//do dfc acc to ordering given in the stack
 memset(visited,0,n);
 char comp='A';
    for(int x=st.size()-1; x>=0;x--){
        int node=st[x];
        if(!visited[node]){
            //component starting from this node
           cout<<"component "<<comp<<"->";
            dfs2(rev_graph,node,visited);
            cout<<endl;
            comp++;
        }
    }
}

int main()
{  int n;//vertices
cin>>n;
vector<int> graph[n];
vector<int> rev_graph[n];
int m;//edges
cin>>m;
while(m--){
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
    rev_graph[y].push_back(x);
}
solve(graph,rev_graph,n);
    return 0;
}
