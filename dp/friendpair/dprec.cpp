#include<bits/stdc++.h>
using namespace std;
int f(int n,int dp[])
{
 if(n==1 || n==2)
 {
  return dp[n]=n;
 }
 if(dp[n]!=-1)
 {
  return dp[n];
 }
 return dp[n]=((n-1)*f(n-2,dp))+f(n-1,dp);
}
int main()
{
 int n;
 cin>>n;
 int dp[n+1];
 memset(dp,-1,sizeof dp);
 
 cout<<f(n,dp)<<endl;
 return 0;
}
//top-down approach
