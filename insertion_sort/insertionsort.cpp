#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int a[n+1];
 a[0]=-1;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
 }
 for(int i=2;i<=n;i++)
 {
  int temp=a[i],j	;
  for(j=i;a[j-1]>temp;j--)
  {
   a[j]=a[j-1];
  }
  a[j]=temp;
 }
 for(int i=1;i<=n;i++)
 {
  cout<<a[i]<<" ";
 }
 cout<<endl;
 return 0;
}
