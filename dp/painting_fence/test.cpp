#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,k;
 cin>>n>>k;
 int arr[n+1];
 memset(arr,0,sizeof arr);
 arr[1]= k;
 int same=0,diff=k;
 for(int i=2;i<=n;i++)
 {
  same=diff;
  diff=arr[i-1]*(k-1);
  arr[i]=same+diff;
 }
 cout<<arr[n]<<endl;
 return 0;
}
