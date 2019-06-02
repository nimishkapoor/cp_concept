#include<bits/stdc++.h>
#define inf 1000000
using namespace std;
int main()
{
 int n,m,start,end;
 cin>>n>>m>>start>>end;
 int g[n][n];
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
  {
   g[i][j]=inf;
  }
 }
 for(int i=0;i<m;i++)
 {
  int i1,j1,w;
  cin>>i1>>j1>>w;
  g[i1][j1]=w;
 }
 int path[n][n];
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
  {
   if(g[i][j]!= inf && i!=j)
   {
    path[i][j]=i;
   }
   else
   {
    path[i][j]=-1;
   }  
  }
 }
 for(int k=0;k<n;k++)
 {
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<n;j++)
   {
    if(g[i][j]>g[i][k]+g[k][j])
    {
     g[i][j]=g[i][k]+g[k][j];
     path[i][j]=path[k][j];
    }
   }
  }
 }
 stack <int> q;
 q.push(end);
 while(true)
 {
  end=path[start][end];
  q.push(end);
  if(start==end)
  {
   break;
  }
 }
 while(!q.empty())
 {
  cout<<q.top()<<" ";
  q.pop();
 }
 cout<<endl;
 return 0;
}
