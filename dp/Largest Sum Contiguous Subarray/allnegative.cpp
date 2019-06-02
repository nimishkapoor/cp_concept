#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++)
 {
  cin>>arr[i];
 }
 int lso=arr[0],mx=-999999,s=-1,start,end,prev;
 for(int i=0;i<n;i++)
 {
  prev=lso;
  lso=max(arr[i],lso+arr[i]);
  if(mx<lso)
  {
   mx=lso;
   if(s!=-1)
   {
    start=s;
   }
   else
   {
    start=i;
   }
   end=i;
  }
  if(lso>=0 && prev<0)
  {
   s=i;
  }  
 }
 for(int i=start;i<=end;i++)
 {
  cout<<arr[i]<<" ";
 }
 cout<<endl;
 cout<<mx<<endl;
 return 0;
}
