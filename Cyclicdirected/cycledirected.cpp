#include<bits/stdc++.h>
using namespace std;
class Graph
{
 int V;
 list<int> *adj;
 bool DFS(int u,bool white[],bool gray[],bool black[]);
 
public:
 Graph(int V);
 void addEdge(int u,int v);
 bool Cycle();
};
Graph::Graph(int V)
{
 this->V=V;
 adj=new list<int>[V];
}
void Graph::addEdge(int u,int v)
{
 adj[v].push_back(u);
}
bool Graph::DFS(int u,bool white[],bool gray[],bool black[])
{
 white[u]=false;
 gray[u]=true;
 list<int>::iterator it;
 for(it=adj[u].begin();it!=adj[u].end();it++)
 {
  if(black[*it])
  {
   continue;
  }
  if(gray[*it])
  {
   return true;
  }
  if(DFS(*it,white,gray,black))
  {
   return true;
  }
 }
 gray[u]=false;
 black[u]=true;
 return false;
}
bool Graph::Cycle()
{
 int ans=0;
 bool white[V];
 bool gray[V];
 bool black[V];
 memset(white,1,sizeof white);
 memset(gray,0,sizeof gray);
 memset(black,0,sizeof black);
 

 for(int i=0;i<V;i++)
 {
  if(white[i])
  {
   if(DFS(i,white,gray,black))
    return true;
  }
 }
 return false;
}
int main()
{
 Graph graph(6);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 2);
        graph.addEdge(3, 0);
        graph.addEdge(3, 4);
        graph.addEdge(4, 5);
        graph.addEdge(5, 3);
 cout<<graph.Cycle()<<endl;
 return 0;
}

