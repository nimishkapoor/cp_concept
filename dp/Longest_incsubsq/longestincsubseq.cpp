#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int arr[n];
 int  temp[n];
 for(int i=0;i<n;i++)
 {
  temp[i]=1;
 }
 for(int i=0;i<n;i++)
 {
  cin>>arr[i];
 }
 for(int i=1;i<n;i++)
 {
  for(int j=0;j<i;j++)
  {
   if(arr[j]<arr[i])
   {
    temp[i]=max(temp[i],temp[j]+1);
   }
  }
 }

 int maxn=0;
 for(int i=0;i<n;i++)
 {
  if(maxn<temp[i])
     maxn=temp[i];
 }
 for(int i=0;i<n;i++)
 {
  cout<<temp[i]<<" ";
 }
 cout<<endl;
 cout<<maxn<<endl;
 return 0;
}

