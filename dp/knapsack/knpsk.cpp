#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL);
 ll n,c,m,M=0,ec=0,oc=0;
 cin>>n;
 priority_queue<ll> one;
 priority_queue<ll> two;
 for(ll i=0;i<n;i++)
 {
  cin>>c>>m;
  if(c==1)
  {
   one.push(m);
  }
  else
  {
   two.push(m);
  }
   M+=c;
 } 
// cout<<"M= "<<M<<endl;
 
 for(ll i=1;i<=M;i++)
 {
  if(i%2==0)
  {
   ll x=0;
   if(two.size()>0)
   {
    x=two.top();two.pop();
   }
   ll y=0,z=0;
   if(one.size()>1)
   {
    y=one.top();one.pop();
    z=one.top();one.pop();
   }
   if(x>=(y+z))
   {
    one.push(y);
    one.push(z);
    ec+=x;
   // cout<<"x= "<<x<<endl;
   }
   else
   {
    two.push(x);
    ec+=(y+z);
   // cout<<"y= "<<y<<" z= "<<z<<endl;
   }
   cout<<ec<<" ";
  }
  else
  {
   ll x=0;
   if(one.size()>0)
   {
    x=one.top();
   // cout<<"ox= "<<x<<endl;
   }
   ll t1=ec+x;
   ll y=0;
   if(two.size()>0 && i>1)
   {
    y=two.top();
   }
   ll t2=oc+y;
   oc=max(t1,t2);
   cout<<oc<<" ";
  }  
 }
 cout<<endl;
 return 0;
}	
