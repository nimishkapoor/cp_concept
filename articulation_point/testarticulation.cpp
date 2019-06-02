#include<bits/stdc++.h>
using namespace std;
class Graph
{
 int V;
 list<int> *adj;
 void APUtil(int u,int low[],int visitedcount[],int parent[],bool visited[],bool ap[]);
public:
 Graph(int V);
 void addEdge(int u,int v);
 void AP();
};
Graph::Graph(int V)
{
 this->V=V;
 adj=new list<int>[V];
}
void Graph::addEdge(int u,int v)
{
 adj[u].push_back(v);
 adj[v].push_back(u);
}
void Graph::APUtil(int  u,int low[],int visitedcount[],int parent[],bool visited[],bool ap[])
{
 static int time=0;
 int children=0;
 visited[u]=true;
 low[u]=visitedcount[u]=++time;
 list<int>::iterator it;
 for(it=adj[u].begin();it!=adj[u].end();++it) 
 {
  int v=*it;
  if(!visited[v])
  {
   parent[v]=u;
   children++;
   APUtil(v,low,visitedcount,parent,visited,ap);
   low[u]=min(low[u],low[v]);
   if(parent[u]==-1  && children>1)
   {
    ap[u]=true;
   }
   if(parent[u]!=-1 && low[v]>=visitedcount[u])
   {
    ap[u]=true;
   }
  }
  else if(v!=parent[u])
  {
   low[u]=min(low[u],visitedcount[v]);
  }
 }
}

void Graph::AP() 
{
 bool visited[V];
 bool ap[V];
 int parent[V];
 int low[V];
 int visitedcount[V];
 for(int i=0;i<V;i++)
 {
  parent[i]=-1;
  visited[i]=false;
  ap[i]=false;
 }
 for(int i=0;i<V;i++)
 {
  if(!visited[i])
  {
   APUtil(i,low,visitedcount,parent,visited,ap);
  }
 }
 for(int i=0;i<V;i++)
 {
  if(ap[i])
  {
   cout<<i<<" ";
  }
 }
 cout<<endl;
}
int main()
{
 Graph g(5);
 g.addEdge(1,0);
 g.addEdge(0,2);
 g.addEdge(2,1);
 g.addEdge(0,3);
 g.addEdge(3,4);
 g.AP();
 cout << "\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.AP();
 
    cout << "\nArticulation points in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.AP();
 return 0;
}
 



