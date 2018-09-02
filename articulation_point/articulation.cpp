#include<bits/stdc++.h>
using namespace std;
class Graph
{
 int V;
 list<int> *adj;
 void APUtil(int u,bool visited[],bool ap[],int parent[],int low[],int visitedtime[]);
 
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
 adj[v].push_back(u);
 adj[u].push_back(v);
}
void Graph::APUtil(int u,bool visited[],bool ap[],int parent[],int low[] ,int visitedtime[])
{
 static int time=0;
 int children=0;
 visited[u]=true;
 visitedtime[u]=low[u]=++time;
 list<int>::iterator it;
 for(it=adj[u].begin();it!=adj[u].end();++it)
 {
  int v=*it;
  if(visited[v]==false)
  {
   children++;
   parent[v]=u;
   APUtil(v,visited,ap,parent,low,visitedtime);
   low[u]=min(low[u],low[v]);
   if(parent[u]==-1 && children>1)
   {
    ap[u]=true;
   }
   if(parent[u]!=-1 && low[v]>=visitedtime[u])
   {
    ap[u]=true;
   }
  }
  else if(v!=parent[u])
  {
   low[u]=min(low[u],visitedtime[v]);
  }
 }
}
void Graph::AP()
{
 bool visited[V];
 bool ap[V];
 int parent[V];
 int low[V];
 int visitedtime[V];
 for(int i=0;i<V;i++)
 {
  visited[i]=false;
  ap[i]=false;
  parent[i]=-1;
 }
 for(int i=0;i<V;i++)
 {
  if(visited[i]==false)
  {
   APUtil(i,visited,ap,parent,low,visitedtime);
  }  
 }
 for(int i=0;i<V;i++)
 {
  if(ap[i]==true)
  {
   cout<<i<<endl;
  }

 }
} 

int main()
{
 Graph g1(5);
 g1.addEdge(1,0);
 g1.addEdge(0,2);
 g1.addEdge(2,1);g1.addEdge(0,3);
 g1.addEdge(3,4);
 g1.AP();
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
