#include<bits/stdc++.h>
#define inf 999999
using namespace std;

int w[9][9]={          {0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 0, 10, 0, 2, 0, 0},
                       {0, 0, 0, 14, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}
                      };
int sett[9]={0};
int dist[9]={0,inf,inf,inf,inf,inf,inf,inf,inf};
int parent[9];
void print(int dest)
{
 if(parent[dest]==-1)
 {
  return;
 }
 print(parent[dest]);
 cout<<dest<<" ";
}

int minn()
{
 int m=inf,mi;
 for(int i=0;i<9;i++)
 {
  if(dist[i]<=m && sett[i]==0)
  {m=dist[i];mi=i;}
 }
 return mi;
}
void relax(int u,int v)
{  
 if(dist[v]>dist[u]+w[u][v])
 {
  dist[v]=dist[u]+w[u][v];
  parent[v]=u;
 }              
}                         
int main()            
{
 memset(parent,-1,sizeof parent);
 for(int j=0;j<9-1;j++)
 {
 int u=minn();
 sett[u]=1;
 for(int i=0;i<9;i++)
 {
  if(w[u][i]!=0&& sett[i]==0)
     relax(u,i);  
 }
 }
 for(int i=0;i<9;i++)
 {
  cout<<dist[i]<<" ";
 }
 cout<<endl;
 cout<<0<<" ";
 print(4);
 cout<<endl;	  	
 return 0;
}
 
  
   
  


 
