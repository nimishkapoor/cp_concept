#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll pre[2000001];
ll dp[1000001];

ll nod(ll x)
{
 ll oc=0,ec=0,rem;
 while(x>0)
 {
  rem=x%10;
  if(rem%2==0)
  {
   ec+=rem;
  }
  else
  {
   oc+=rem;
  }
  x=x/10;
 }
 return abs(oc-ec);
}
int main()
{
 ll t,n,ans;
 cin>>t;
 dp[0]=0;
 pre[0]=0;
 for(ll i=1;i<2000001;i++)
 {
  pre[i]=pre[i-1]+nod(i);
 }
 for(ll i=1;i<1000001;i++)
 {
  dp[i]=dp[i-1]+2*(pre[2*i]-pre[i])-nod(2*i);
 }
 while(t--)
 {
  cin>>n;
  cout<<dp[n]<<endl;
 }
 return 0;
} 
