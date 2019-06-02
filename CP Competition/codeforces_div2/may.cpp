#include<bits/stdc++.h>
using namespace std;
int main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL);
 int n,x,flag=1,f31=0,f30=0,f29=0,f28=0,leap=0,count31=0;
 cin>>n;
 for(int i=0;i<n;i++)
 {
  cin>>x;
  if(x==30)
  {
   if(((x==30 && f30==0) && f28==0) && f29==0)
   {
    f30=1;
   
    if(f31==1)
    {
     f30=1;
     f31=0;
     count31=0;
    }
   }
   else
   { 
     flag=0;
    break;
   } 
  }
  if(x==29)
  {
   if((((x==29 && f28==0) && f29==0) &&f30==0) && leap==0)
   {
    f29=1;
    leap=1;
   
    if(f31==1)
    {
     f29=1;
     leap=1;
     f31=0;
     count31==0;
    }
   }
   else 
   {
    flag=0;
    break;
   }
  }
  if(x==28)
  {
   if((((x==28 && f28==0) && f29==0) &&f30==0))
   {
    f28=1;
    if(f31==1)
    {
     f28=1;
     f31=0;
     count31=0;
    }
   }
   else 
   {
    flag=0;
    break;
   }
  }
  if(x==31)
  {
   if(x==31 && count31<=2)
   {
    count31++;
    f31=1;
    f30=0;
    f28=0;
    f29=0;
   } 
   else 
   {
    flag=0;
    break;
   }
  }
 }
 if(flag==1)
 {
  cout<<"YES"<<endl;
 }
 else
 {
  cout<<"NO"<<endl;
 }
 return 0;
}








