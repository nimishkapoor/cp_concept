#include<bits/stdc++.h>
using namespace std;
class Graph
{
 int V;
 list<int> *adj;
 void fillOrder(int v,bool visited[],stack<int> &Stack);
 void DFSUtil(int v,bool visited[]);
 
public:
 Graph(int V);
 void addEdge(int u,int v);
 Graph getTranspose();
 void printSCCs();
};
void Graph::addEdge(int u,int v)
{
 adj[u].push_back(v);
}
Graph::Graph(int V)
{
 this->V=V;
 adj=new list<int>[V];
}
Graph Graph::getTranspose()
{
 Graph g(V);
 for(int v=0;v<V;v++)
 {
  list<int>::iterator it;
  for(it=adj[v].begin();it!=adj[v].end();++it)
  {
   g.adj[*it].push_back(v);
  }
 }
 return g;
}
void Graph::fillOrder(int v,bool visited[],stack<int> &Stack)
{
 visited[v]=true;
 list<int>::iterator it;
 for(it=adj[v].begin();it!=adj[v].end();++it)
 {
  if(visited[*it]==false)
     fillOrder(*it,visited,Stack);
 }
 Stack.push(v);
}
void Graph::DFSUtil(int v,bool visited[])
{
 visited[v]=true;
 cout<<v<<" ";
 list<int>::iterator it;
 for(it=adj[v].begin();it!=adj[v].end();++it)
 {
  if(visited[*it]==false)
     DFSUtil(*it,visited);
 }
}
void Graph::printSCCs()
{
 bool visited[V];
 stack<int> Stack;
 for(int i=0;i<V;i++)
 {
  visited[i]=false;
 }
 for(int i=0;i<V;i++)
 {
  if(visited[i]==false)
  {
   fillOrder(i,visited,Stack);
  }
 }
 for(int i=0;i<V;i++)
 {
  visited[i]=false;
 }
 Graph gr=getTranspose();	
 while(Stack.empty()==false)
 {
  int u=Stack.top();
  Stack.pop();
  if(visited[u]==false)
  {
    gr.DFSUtil(u,visited);
    cout<<endl;
  }
 }
}
int main()
{
 Graph g(5);
 g.addEdge(1,0);
 g.addEdge(0,2);
 g.addEdge(2,1);
 g.addEdge(0,3);
 g.addEdge(3,4);
 g.printSCCs();
 return 0;
}
