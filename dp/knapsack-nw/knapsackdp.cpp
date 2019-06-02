#include<bits/stdc++.h>
using namespace std;
int knapsack(int n,int w,int wt[],int val[])
{
 int dp[n+1][w+1];
 for(int i=0;i<=n;i++)
 {
  for(int j=0;j<=w;j++)
  {
   if(i==0||j==0)
   {
    dp[i][j]=0;
   }
   else if(wt[i-1]>j)
   {
    dp[i][j]=dp[i-1][j];
   }
   else
   {
    dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
   }
  }
 }
 for(int i=0;i<=n;i++)
 {
  for(int j=0;j<=w;j++)
  {
   cout<<dp[i][j]<<" ";
  }
  cout<<endl;
 }
 return dp[n][w];
}
int main()
{
 int n;
 cin>>n;
 int w;
 cin>>w;
 int val[n];
 int wt[n];
 for(int i=0;i<n;i++)
 {
  cin>>wt[i];
 }
 for(int i=0;i<n;i++)
 {
  cin>>val[i];
 }
 cout<<knapsack(n,w,wt,val)<<endl;
 return 0;
}
