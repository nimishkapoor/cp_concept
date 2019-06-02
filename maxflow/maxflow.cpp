#include<bits/stdc++.h>
using namespace std;
#define n 6
bool bfs(int rGraph[n][n],int s,int t,int parent[])
{
 bool visited[n];
 memset(visited,0,sizeof visited);
 queue<int> q;
 q.push(s);
 visited[s]=true;
 parent[s]=-1;
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  for(int v=0;v<n;v++)
  {
   if(rGraph[u][v]>0 && visited[v]==false)
   {
    parent[v]=u;
    visited[v]=true;
    q.push(v);
   }
  }
 }
 return(visited[t]==true);
}
int fordFulkerson(int graph[n][n],int s,int t)
{
 int u,v;
 int rGraph[n][n];
 for(int u=0;u<n;u++)
 {
  for(int v=0;v<n;v++)
  {
   rGraph[u][v]=graph[u][v];
  }
 }
 int parent[n];
 int max_flow=0;
 while(bfs(rGraph,s,t,parent))
 {
  int path_flow=INT_MAX;
  for(int v=t;v!=s;v=parent[v])
  {
   u=parent[v];
   path_flow=min(path_flow,rGraph[u][v]);
  }
  for(int v=t;v!=s;v=parent[v])
  {
   u=parent[v];
   rGraph[u][v]-=path_flow;
   rGraph[v][u]+=path_flow;
  }
  max_flow+=path_flow;
 }
 return max_flow;
}
int main()
{
int graph[n][n] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
 
    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5); 
 return 0;
}

 
