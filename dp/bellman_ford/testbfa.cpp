#include<bits/stdc++.h>
#define inf 999999
using namespace std;
int w[6][6]={          {0, 10, 0, 0, 0, 8},
                       {0, 0, 0, 2, 0, 0},
                       {0, 1, 0, 0, 0, 0},
                       {0, 0, -2, 0, 0, 0},
                       {0, -4, 0, -1, 0, 0},
                       {0, 0, 0, 0, 1,  0},
                       
                      };
int t[6]={0,inf,inf,inf,inf,inf};
int parent[6];
void print(int dest)
{
 if(parent[dest]==-1)
 {
  return;
 }
 print(parent[dest]);
 cout<<dest<<" ";
}
void relax(int u,int v)
{  
 if(t[v]>t[u]+w[u][v])
 {
  t[v]=t[u]+w[u][v];
  parent[v]=u;
 }              
}                         
int main()            
{memset(parent,-1,sizeof parent);
 for(int i=0;i<6-1;i++)
 {
  for(int j=0;j<6;j++)
  {
   for(int k=0;k<6;k++)
   {
    if(w[j][k]!=0)
    relax(j,k);
   }
  }
  for(int i=0;i<6;i++)
 {
  cout<<t[i]<<" ";
 }
 cout<<endl;
 }
 for(int i=0;i<6;i++)
 {
  cout<<t[i]<<" ";
 }
 cout<<endl;
 
 for(int j=0;j<6;j++)
  {
   for(int k=0;k<6;k++)
   {
    if(t[k]>t[j]+w[j][k] && w[j][k]!=0)
    {
     cout<<"Negative Cycle"<<endl;
     break;
    }
   }
  }
 cout<<0<<" ";
 print(4);
 cout<<endl;	  	
 return 0;
}
 
  
   
  


 
