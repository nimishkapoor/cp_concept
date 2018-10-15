#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
 ll t;
 cin>>t;
 while(t--)
 {
  ll flaga=0,flagb=0,flagc=0;
  ll a[3]={0};
  ll b[3]={0};
  ll c[3]={0};
  ll suma=0,sumb=0,sumc=0;
  for(ll i=0;i<3;i++)
  {
   cin>>a[i];
   suma+=a[i];
  }
  for(ll i=0;i<3;i++)
  {
   cin>>b[i];
   sumb+=b[i];
  }
  for(ll i=0;i<3;i++)
  {
   cin>>c[i];
   sumc+=c[i];
  }
  if(suma>sumb && sumb> sumc)
  {
   for(int i=0;i<3;i++){
   if(a[i]>=b[i] && b[i]>=c[i])
   flaga=1;
   else
   {flaga=0;
    break;
   }
   }
  } 
  if(sumb>suma && suma> sumc)
  {
   for(int i=0;i<3;i++){
   if(b[i]>=a[i] && a[i]>=c[i])
   flagb=1;
   else
   {flagb=0;
    break;
   }
   }
  }
  if(sumb>sumc && sumc> suma)
  {
   for(int i=0;i<3;i++){
   if(b[i]>=c[i] && c[i]>=a[i])
   flagb=1;
   else
   {flagb=0;
    break;
   }
   }
  }
  if(suma>sumc && sumc> sumb)
  {
   for(int i=0;i<3;i++){
   if(a[i]>=c[i] && c[i]>=b[i])
   flaga=1;
   else
   {flaga=0;
    break;
   }
   }
  }
  if(sumc>suma && suma> sumb)
  {
   for(int i=0;i<3;i++){
   if(c[i]>=a[i] && a[i]>=b[i])
   flagc=1;
   else
   {flagc=0;
    break;
   }
   }
  }
  if(sumc>sumb && sumb> suma)
  {
   for(int i=0;i<3;i++){
   if(c[i]>=b[i] && b[i]>=a[i])
   flagc=1;
   else
   {flagc=0;
    break;
   }
   }
  }
  if(flaga==1 || flagb==1 || flagc==1)
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

