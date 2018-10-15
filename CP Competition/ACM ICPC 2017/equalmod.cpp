#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
 ll t;
 cin>>t;
 while(t--)
 {
  ll n;
  cin>>n;
  ll a[n];
  ll b[n];
  ll count=0;
  for(ll i=0;i<n;i++)
  {
   cin>>a[i];
  }
  for(ll i=0;i<n;i++)
  {
   cin>>b[i];
  }
  ll min=99999999;


  for(ll i=0;i<n;i++)
  {
   if(min>(a[i]%b[i]))
   {
    min=(a[i]%b[i]);
   }
  }


  for(ll i=0;i<n;i++)
  {
   if((a[i]%b[i])!=min)
   {
    while((a[i]%b[i])!=min)
    {
     a[i]++;
     count++;
    }
   }
  }
  cout<<count<<endl;
 }
 return 0;
}
