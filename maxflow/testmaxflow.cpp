#include<bits/stdc++.h>
#define V 6
using namespace std;
bool BFS(int s,int t,int rGraph[V][V],int parent[])
{
 bool visited[V];
 memset(visited,0,sizeof visited);
 queue<int>q;
 q.push(s);
 visited[s]=true;
 parent[s]=-1;
 while(!q.empty())
 {
  int u=q.front();
  q.pop();
  for(int v=0;v<V;v++)
  {
   if(visited[v]==false && rGraph[u][v]>0)
   {
    q.push(v);
    visited[v]=true;
    parent[v]=u;
   }
  }
 }
 return (visited[t]==true);
}
int FordFulkerson(int graph[V][V],int s,int t)
{
 int parent[V];
 int max_flow=0;
 int path_flow=0;
 int rGraph[V][V];
 for(int u=0;u<V;u++)
 {
  for(int v=0;v<V;v++)
  {
   rGraph[u][v]=graph[u][v];
  }
 }
 while(BFS(s,t,rGraph,parent))
 {
  int ans=INT_MAX;
  for(int u=t;u!=s;u=parent[u])
  {
   ans=min(ans,rGraph[parent[u]][u]);
  }
  path_flow=ans;
  for(int u=t;u!=s;u=parent[u])
  {
   rGraph[parent[u]][u]-=ans;
   rGraph[u][parent[u]]+=ans;
  }
  max_flow+=path_flow;
 }
 return max_flow;
}
int main()
{
  int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
 
    cout << "The maximum possible flow is " << FordFulkerson(graph, 0, 5)<<endl;
 
 return 0;
}
