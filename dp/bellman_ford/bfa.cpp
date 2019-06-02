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
int t[9]={0,inf,inf,inf,inf,inf,inf,inf,inf};
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
 for(int i=0;i<9-1;i++)
 {
  for(int j=0;j<9;j++)
  {
   for(int k=0;k<9;k++)
   {
    if(w[j][k]!=0)
    relax(j,k);
   }
  }
 
 }
 for(int i=0;i<9;i++)
 {
  cout<<t[i]<<" ";
 }
 cout<<endl;
 
 for(int j=0;j<9;j++)
  {
   for(int k=0;k<9;k++)
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
 
  
   
  


 
