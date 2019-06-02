#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,k;
 cin>>n>>k;
 int dp[n+1];
 memset(dp,0,sizeof dp);
 dp[1]=k;
 int same=0,diff=k;
 for(int i=2;i<=n;i++)
 {
  same=diff;
  
  diff=dp[i-1]*(k-1);
  
  dp[i]=same+diff;
 }
 cout<<dp[n]<<endl;
 return 0;
}
