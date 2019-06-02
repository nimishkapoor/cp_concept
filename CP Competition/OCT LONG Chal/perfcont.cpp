#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
 ll t;
 cin>>t;
 while(t--)
 {
  ll n,m,c=0,h=0;
  cin>>n>>m;
  ll a[n];
  for(ll i=0;i<n;i++)
  {
   cin>>a[i];
  }
  for(ll i=0;i<n;i++)
  {
   if(a[i]>=(m/2)) 
   {
    c++;
   // cout<<"i "<<i<<" a[i] "<<a[i]<<" m/2 "<<m/2<<" c "<<c<<endl;
   }
   else if(a[i]<=(m/10))
   {
    h++;
    //cout<<"i "<<i<<" a[i] "<<a[i]<<" m/10 "<<m/10<<" h "<<h<<endl;
   }
  }
  if(c==1 && h==2)
  {
   cout<<"yes"<<endl;
  }
  else
  {
   cout<<"no"<<endl;
  }
 }
 return 0;
}
