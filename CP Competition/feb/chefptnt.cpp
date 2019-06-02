#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
 ll t,n,m,x,k,oc,ec;
 string s;
 cin>>t;
 while(t--)
 {
  oc=0;ec=0;
  cin>>n>>m>>x>>k; 
  cin>>s;
  for(int i=0;i<k;i++)
  {
   if(s[i]=='O') 
   {
    oc++;
   }
   else
   {
    ec++;
   }
  }
  for(int i=1;i<=m;i++)
  {
   if(i%2!=0)
   {
    if(oc>=x)
    {
     n=n-x;
     if(n<0)
      n=0;
     oc=oc-x;
    }
    else if (oc>0)
    {
     n=n-oc;
     if(n<0)
     {
      n=0;
     }
     oc=0;
    }
   }
   else
   {
    if(ec>x)
    {
     n=n-x;
     if(n<0)
      n=0;
     ec=ec-x;
    }
    else if (ec>0)
    {
     n=n-ec;
     if(n<0)
     n=0;
     ec=0;
    }
   }
 // cout<<n<<endl;
   if(n==0 || oc==0 && ec==0)
   {
    break;
   }
  }
  if(n==0)
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
