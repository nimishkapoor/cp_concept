#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,a,b,ans,a1,b2;
 cin>>n>>a>>b;
 if(n==a+b)
 {
  ans=1;
 }
 if(n<a|| n<b)
 {
  if(a>n && (a<b||a>b))
  {
   ans=1;
  }
 }
 if(n>a+b)
 {
  ans=min(a/(n/2),b/(n/2));
 }
 cout<<ans<<endl;
 return 0;
}
  
 
