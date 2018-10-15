#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,q,m;
  cin>>n;
  int a[n][2];
  for(int i=0;i<n;i++)
  {
   cin>>a[i][0]>>a[i][1];
  }
  /*for(int i=0;i<n;i++)
  {
   cout<<a[i][0]<<" "<<a[i][1]<<endl;
  }*/
  
  cin>>q;
  while(q--)
  {
   int m,ans=0,temp=0;
   cin>>m;
   int x[m];
   for(int i=0;i<m;i++)
   {
    cin>>x[i];
   }
  /* for(int i=0;i<m;i++)
   {
    cout<<x[i]<<" ";
   }*/
   for(int i=0;i<n;i++)
   {
    temp=0;
    for(int j=0;j<m;j++)
    {
     if(a[i][0]<=x[j] && a[i][1]>=x[j])
     {
      temp++;
     }
    }
    if(temp%2!=0)
    {
     ans++;
    } 
   }
   cout<<ans<<endl;
  }
 }
 return 0;
}    
