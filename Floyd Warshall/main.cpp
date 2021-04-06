#include <bits/stdc++.h>

using namespace std;
#define INF 1000
  vector<vector<int>> floyd(  vector<vector<int>> graph)
  {  int v=graph.size();
       vector<vector<int>> dis(graph);
  for(int k=0;k<v;k++ )//kth phases to be included as intermediate vertices
  {
       for(int i=0;i<v;i++)//iterate over 2d matric
        {
             for(int j=0;j<v;j++)
                { //if k makes the path short, update path(dis)
                if(dis[i][j] > dis[i][k]+dis[k][j]){
                    dis[i][j] = dis[i][k]+dis[k][j];
                }
                }

        }
  }
  return dis;
  }
int main()
{
    vector<vector<int>> graph= {{0,INF,-2,INF},
    {4,0,3,INF},
    {INF,INF,0,2},
    {INF,-1,INF,0}
    };
    auto ans= floyd(graph);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans.size();j++)
        {
            cout<<ans[i][j]<<" ";
        } cout<<endl;
    }
    return 0;
}
