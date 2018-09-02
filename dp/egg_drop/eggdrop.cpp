#include<bits/stdc++.h>
using namespace std;
int ed(int n,int k)
{
 
 if(k==1 || k==0)
 { 
  return k;
 }
 if(n==1)
 { 
  return k;
 }
 int res,ans=INT_MAX;
 for(int i=1;i<=k;i++)
 {
  res=max(ed(n-1,i-1),ed(n,k-i));
  ans=min(ans,res);
 }
  
 return ans+1;
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,k;
  cin>>n>>k;
  
  cout<<ed(n,k)<<endl;
 }
 return 0;
}


