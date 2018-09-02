#include<bits/stdc++.h>
using namespace std;
int main()
{
 string s;
 cin>>s;
 int n=s.size();
 int dp[n][n];
 memset(dp,0,sizeof dp);
 
 for(int i=0;i<n;i++)
 {
  dp[i][i]=1;
 }
 for(int i=0;i<n-1;i++)
 {
  if(s[i]==s[i+1])
  {
   dp[i][i+1]=1;
  }
 }
 int maxl=0,start;
 for(int i=3;i<=n;i++)
 {
  for(int j=0;j<=n-i;j++)
  {
   int k=j+i-1;
   if(s[j]==s[k] && dp[j+1][k-1]==1)
   {
    dp[j][k]=1;
    if(i>maxl)
    {
     maxl=i;
     start=j;
    }
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
 cout<<maxl<<endl;
 for(int i=start;i<maxl+start;i++)
 {
  cout<<s[i]<<" ";
 }
 cout<<endl;
 return 0;
}

    
