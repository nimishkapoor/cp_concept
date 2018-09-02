#include<bits/stdc++.h>
using namespace std;
int bicof(int p,int t)
{
 int c[t+1];
 memset(c,0,sizeof c);
 c[0]=1;
 for(int i=0;i<=p;i++)
 {
  for(int j=min(i,t);j>0;j--)
  { 
   c[j]=c[j-1]+c[j];
  }
 }
 return c[t];
}
int main()
{
 int p,t;
 cin>>p>>t;
 cout<<bicof(p,t)<<endl;
 return 0;
}
