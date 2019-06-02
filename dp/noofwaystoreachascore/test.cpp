#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,v;
 int inf=999999;
 cin>>n>>v;
 int a[n];
 for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }
 int dp[v+1];
 int count[v+1]={0};
 dp[0]=0;
 for(int i=1;i<=v;i++)
 {
  dp[i]=inf;
 }
 for(int i=0;i<n;i++)
 {
  for(int j=1;j<=v;j++)
  {
   if(a[i]<=j)
   {count[j]++;
    if(dp[j]>(1+dp[j-a[i]]))
    {
     dp[j]=1+dp[j-a[i]];
    } 
   }
  }
 }
 for(int i=1;i<=v;i++)
 {
  cout<<count[i]<<" ";
 }
 cout<<endl;
 cout<<count[v]<<endl;
 return 0;
}
