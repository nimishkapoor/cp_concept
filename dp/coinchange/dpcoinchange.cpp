#include<bits/stdc++.h>
#define inf 999999
using namespace std;
int main()
{
 int n,v,s;
 cin>>n>>v;
 int a[n];
 int dp[v+1];
 for(int i=1;i<=v;i++)
 {
  dp[i]=inf;
 }
 dp[0]=0;

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
 for(int i=0;i<=v;i++)
 {
  cout<<dp[i]<<" ";
 }
 cout<<endl;
 cout<<dp[v]<<endl;
 return 0;
}
