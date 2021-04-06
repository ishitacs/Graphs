#include <iostream>

using namespace std;
#define INT_MAX 99999

int n=4;
//adj matrix
int dp[16][4];
int dis[10][10]={
{0,20,42,25},
{20,0,30,34},
{42,30,0,10},
{25,34,10,0}
};
//if all cities have been visited
int visited_all=(1<<n)-1;
int tsp(int mask,int pos)
{ //base case
    if(mask==visited_all){return dis[pos][0];}
    if(dp[mask][pos]!=-1) return dp[mask][pos];
    int ans=INT_MAX;
    //try to go to unvisited
    for(int city=0;city<n;city++)
    {
        if((mask&(1<<city))==0){
            int newAns= dis[pos][city]+tsp(mask|(1<<city),city);
        ans=min(ans,newAns);
        }
    }
    return dp[mask][pos]=ans;
}
int main()
{ for(int i=0;i<(1<<n);i++ )
{
    for(int j=0;j<n;j++){
        dp[i][j]=-1;
    }
}
     cout<<tsp(1,0)<<endl;
    return 0;
}
