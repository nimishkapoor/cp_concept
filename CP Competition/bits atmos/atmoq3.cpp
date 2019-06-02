#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,q;
 cin>>n>>q;
 int a[n+1];
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
 }
 for(int i=0;i<q;i++)
 {
  int x,y,z,z1,sum=0;
  cin>>x;
  if(x==1)
  {
   cin>>y>>z;
   a[y]=a[y]+z;
  }
  else if(x==2)
  {
   cin>>y>>z>>z1;
   if(z1==1)
   {
    for(int i=y;i<=z;i++)
    {
     if(a[i]%2==1)
     sum=sum+a[i];
    }
   }
   else if(z1==0)
   {
    for(int i=y;i<=z;i++)
    { 
     if(a[i]%2==0)
     sum=sum+a[i];
    }
   }
   cout<<sum<<endl;
  }
 }
 return 0;
}
