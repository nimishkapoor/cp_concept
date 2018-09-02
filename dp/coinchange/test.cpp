#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,v;
 cin>>n>>v;
 int a[n],dp[v+1];
 int inf=99999;
 dp[0]=0;
 for(int i=1;i<=v;i++)
 {
  dp[i]=inf;
 }
 for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }
 for(int i=1;i<=v;i++)
 {
  for(int j=0;j<n;j++)
  {
   if(a[j]<=i)
   {
    dp[i]=min(dp[i],1+dp[i-a[j]]);
   }
  }
 }
 cout<<dp[v]<<endl;
 return 0;
}
 
