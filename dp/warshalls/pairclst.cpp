#include<bits/stdc++.h>
#define inf 1000000
using namespace std;
int main()
{
 int n,m,k1;
 cin>>n>>m>>k1;
 int spl[k1];
 for(int i=0;i<k1;i++)
 {
  cin>>spl[i];
 }
 int g[n+1][n+1];
 for(int i=1;i<=m;i++)
 {
  for(int j=1;j<=n;j++)
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

 
 int path[n+1][n+1]={0};
 
 
 for(int i=1;i<=n;i++)
 {
  for(int j=1;j<=n;j++)
  {
   if(g[i][j]!=inf && i!=j)
   {
    path[i][j]=i;
   }
   else
   {
    path[i][j]=-1;
   }
  }
 }



 for(int k=1;k<=n;k++)
 {
  for(int i=1;i<=n;i++)
  {
   for(int j=1;j<=n;j++)
   {
    if(g[i][k]==inf || g[k][j]==inf)
    {
     continue;
    }
    if(g[i][j]>g[i][k]+g[k][j])
    {
     g[i][j]=g[i][k]+g[k][j];
     path[i][j]=path[k][j];
    }
   }
  }
 }
 
 

		
 int min=1000000;
 for(int i=0;i<k1;i++)
 {
  for(int j=0;j<k1;j++)
  {
   if(i!=j && min>g[spl[i]][spl[j]])
   {
    min=g[spl[i]][spl[j]];
   }
  }
 }
 cout<<min<<endl;
 

 return 0;
}
