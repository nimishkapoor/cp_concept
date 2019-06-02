#include<bits/stdc++.h>
using namespace std;
int bicof(int p,int t)
{
 int c[p+1][t+1];
 for(int i=0;i<=p;i++)
 {
  for(int j=0;j<=min(i,t);j++)
  {
   if(j==0 || i==j)
   {
    c[i][j]=1;
   }
   else
   {
    c[i][j]=c[i-1][j-1]+c[i-1][j];
   }
  }
 }
 return c[p][t];
}
int main()
{
 int p,t;
 cin>>p>>t;
 cout<<bicof(p,t)<<endl;
 return 0;
}
