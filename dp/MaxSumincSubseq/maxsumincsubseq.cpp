#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int a[n];
 for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }
 int dp[n];
 for(int i=0;i<n;i++)
 {
  dp[i]=a[i];
 }
 int maxl=0;
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<i;j++)
  {
   if(a[j]<a[i])
   {
    dp[i]=max(dp[i],dp[j]+a[i]);
    maxl=max(maxl,dp[i]);
   }
  }
 }
 for(int i=0;i<n;i++)
 {
  cout<<dp[i]<<" ";
 }
 cout<<endl;
 cout<<maxl<<endl;
 return 0;
}
