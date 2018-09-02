#include<bits/stdc++.h>
using namespace std;
int rec(int a[],int v,int n)
{
 if(v==0)
 {
  return 0;
 }
 int res=INT_MAX;
 int sub_res;
 for(int i=0;i<n;i++)
 {
  if(a[i]<=v)
  {
   sub_res=1+rec(a,v-a[i],n);
   if(sub_res<res)
   {
    res=sub_res;
   }
  }
 }
 return res;
}
int main()
{
 int n,v;
 cin>>n>>v;
 int a[n];
 for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }
 cout<<rec(a,v,n)<<endl;
 return 0;
}
