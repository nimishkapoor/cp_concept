#include<bits/stdc++.h>
using namespace std;
#define n 4
int wt[n]={1,3,4,5};
int val[n]={1,4,5,7};
int allmask=pow(2,n)-1;
int dp[16];
int dpx[16];
int kp(int mask)
{
 int v=0;
 if(dp[mask]!=-1)
 {
  return dp[mask];
 }
 if(mask==0)
 {
  return dp[0]=0;
 }
 if((mask & (mask-1))==0)//single element in set
 {
  for(int i=0;i<n;i++)
  {
   if((1<<i & mask)==(1<<i))
   {
    dp[mask]=val[i];
    return dp[mask];
   }
  }
 }   
 v+=(kp(pow(2,floor(log2(mask))))+kp(pow(2,floor(log2(mask)))-(pow(2,ceil(log2(mask)))-mask)));//draw bitmask for 4 and find/deduce pattern 
 return dp[mask]=v; 
}
int kpx(int mask)
{
 int w=0;
 if(dpx[mask]!=-1)
 {
  return dpx[mask];
 }
 if(mask==0)
 {
  return dpx[0]=0;
 }
 if((mask & (mask-1))==0)//single element in set
 {
  for(int i=0;i<n;i++)
  {
   if((1<<i & mask)==(1<<i))
   {
    dpx[mask]=wt[i];
    return dpx[mask];
   }
  }
 }   
 w+=(kpx(pow(2,floor(log2(mask))))+kpx(pow(2,floor(log2(mask)))-(pow(2,ceil(log2(mask)))-mask)));//draw bitmask for 4 and find/deduce pattern 
 return dpx[mask]=w; 
}

using namespace std;
int main()
{
 int ans=0;
 int sol;
 memset(dp,-1,sizeof dp);
 memset(dpx,-1,sizeof dpx);
 for(int i=0;i<=allmask;i++)
 {
  if(ans<kp(i) && 7>=kpx(i))
  {
   ans=kp(i);
   sol=i;
  }
 }
 
 cout<<ans<<endl;
 
 for(int i=0;i<n;i++)
 {
  if((1<<i & sol)==(1<<i))
  {
   cout<<wt[i]<<" ";
  }
 }
 cout<<endl;
 
 return 0;
}
 
 
 
