#include<bits/stdc++.h>
using namespace std;
int  main()
{
 string s;
 cin>>s;
 int n=s.size();
 int dp[n][n];
 memset(dp,0,sizeof dp);
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
  {
   cout<<dp[i][j]<<" ";
  }
  cout<<endl;
 }
 for(int i=0;i<n;i++)
 {
  dp[i][i]=1;
 }
 for(int i=1;i<n;i++)
 {
  for(int j=0;j<n-i;j++)
  {
   int k=i+j;
   if(s[j]==s[k])
   {
    dp[j][k]=2+dp[j+1][k-1];
   }
   else
   {
    dp[j][k]=max(dp[j][k-1],dp[j+1][k]);
   }
  }
 }
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
  {
   cout<<dp[i][j]<<" ";
  }
  cout<<endl;
 }
 cout<<dp[0][n-1]<<endl;
 return 0;
}
