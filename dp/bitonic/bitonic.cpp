#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int a[n],lis[n],lds[n];

 for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }
 for(int i=0;i<n;i++)
 {
  lis[i]=1;
 }
 
 for(int i=0;i<n;i++)
 {
  lds[i]=1;
 }
 int temp;
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<i;j++)
  {
   if(a[i]>a[j])
   {
    temp=lis[j]+1;
    lis[i]=max(temp,lis[i]);
   }
  }
 }
 for(int i=n-1;i>=0;i--)
 {
  for(int j=n-1;j>i;j--)
  {
   if(a[i]>a[j])
   {
    temp=lds[j]+1;
    lds[i]=max(temp,lds[i]);
   }
  }
 }
 
 int current,ans=0;
 for(int i=0;i<n;i++)
 {
  current=lis[i]+lds[i]-1;
  ans=max(ans,current);
 }
 cout<<ans<<endl;
 return 0;
}
