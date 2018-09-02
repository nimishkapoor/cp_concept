#include<bits/stdc++.h>
using namespace std;
int main()
{
 string s;
 cin>>s;
 int n=s.size();
 int dp[n][n]={0};
 for(int i=0;i<n;i++)
 {
  dp[i][i]=1;
 }
 for(int l=1;l<n;l++)
 {
  for(int i=0;i<n-l;i++)
  {
   int j=i+l;
   if(s[i]==s[j])
   {
    dp[i][j]=2+dp[i+1][j-1];
   }
   else
   {
    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
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
