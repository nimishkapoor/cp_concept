#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll dc(ll i,ll j)
{
 ll r=i+j;
 ll ec=0,oc=0;
 while(r!=0)
 {
  ll temp=r%10;
  if(temp%2==0)
  {
   ec+=temp;
  }
  else
  {
   oc+=temp;
  }
  r=r/10;  
 }
 return abs(ec-oc);
}
int main()
{
 ll t;
 cin>>t;
 while(t--)
 {
  ll n,count=0;
  cin>>n;
  for(ll i=1;i<=n;i++)
  {
   for(ll j=1;j<=n;j++)
   {
    count+=dc(i,j);
   }
  }
  cout<<count<<endl;
 }
 return 0;
} 
