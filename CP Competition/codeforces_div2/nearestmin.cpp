#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
 ll n,a,s,e,l=0,ans=INT_MAX;
 cin>>n;
 ll min=INT_MAX;
 for(ll i=0;i<n;i++)
 {
  cin>>a;
  if(a<min)
  {
   min=a;
   l=0;
  }
  else if(a==min)
  {  
   if(l<ans)
   {
    ans=l;
   }
   l=0;
  }
  else
  {
   l++;
  }
 // cout<<"ans="<<ans<<endl;
 // cout<<"l="<<l<<endl;
 // cout<<"min="<<min<<endl;
 }
 cout<<ans+1<<endl;
 return 0;
}
