#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,ans=0,one=0;
 cin>>n;
 int  a[n];
 int marked[n]={0};
 for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }
 sort(a,a+n,greater<int>());
 for(int i=0;i<n;i++)
 {
  if(a[i]==2 && marked[i]==0)
  {
   for(int j=i+1;j<n;j++)
   {	
    if(a[j]==1 && marked[j]==0)
    {
     marked[j]=1;
     marked[i]=1;
     ans++;
     break;
    }
   }
  }
  else if(a[i]==1 && marked[i]==0)
  {
   one++;
  }
 }
 ans+=(one/3);
 cout<<ans<<endl;
 return 0;
}
