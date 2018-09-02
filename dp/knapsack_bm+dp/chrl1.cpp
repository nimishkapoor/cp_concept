#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll kp(ll mask,ll n,ll dp[],ll val[])
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
 v+=(kp(pow(2,floor(log2(mask))),n,dp,val)+kp(pow(2,floor(log2(mask)))-(pow(2,ceil(log2(mask)))-mask),n,dp,val));//draw bitmask for 4 and find/deduce pattern 
 return dp[mask]=v; 
}
ll kpx(ll mask,ll n,ll dpx[],ll wt[])
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
 w+=(kpx(pow(2,floor(log2(mask))),n,dpx,wt)+kpx(pow(2,floor(log2(mask)))-(pow(2,ceil(log2(mask)))-mask),n,dpx,wt));//draw bitmask for 4 and find/deduce pattern 
 return dpx[mask]=w; 
}
int main()
{
 ll t;
 cin>>t;
 while(t--)
 { 
  ll n,k;
  cin>>n>>k;
  ll wt[n];
  ll val[n];
  for(ll i=0;i<n;i++)
  {
  	cin>>wt[i]>>val[i];
  }

 	
  ll allmask=pow(2,n)-1;
  ll dp[allmask+1];
  ll dpx[allmask+1];
  ll ans=0,sol;
  memset(dp,-1,sizeof dp);
  memset(dpx,-1,sizeof dpx);
  for(ll i=0;i<=allmask;i++)
  {
   if(ans<kp(i,n,dp,val) && k>=kpx(i,n,dpx,wt))
   {
    ans=kp(i,n,dp,val);
    sol=i;
   }
  }
 
  cout<<ans<<endl;
/*for(int i=0;i<n;i++)
 {
  if((1<<i & sol)==(1<<i))
  {
   cout<<wt[i]<<" ";
  }
 }
 cout<<endl;*/
 }
 return 0;
}
 
 
 
