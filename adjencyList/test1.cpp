#include<bits/stdc++.h>
#define inf 1000000
using namespace std;
int main()
{
 int n,count=0;
 cin>>n;
 int g[n][n];
 char s[2001];
 
 
 for(int i=0;i<n;i++)
 {
  cin>>s; 
  for(int j=0;j<n;j++)
  {
   if(s[j]-48==1)
   {
    g[i][j]=s[j]-48;
   }
   else if(i==j)
   {
    g[i][j]=0;
   }
   else
   {
    g[i][j]=inf;
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
     if(g[i][j]==2)
     {
      count++;
     }
    }
   }
  }
 }
 

 cout<<count<<endl;
 return 0;
}
 
