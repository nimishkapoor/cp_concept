#include<bits/stdc++.h>
using namespace std;
#define n 4
int wt[n]={1,3,4,5};
int val[n]={1,4,5,7};
int allmask=pow(2,n)-1;
int kp(int mask)
{
 int w=0,v=0;
 for(int i=0;i<n;i++)
 {
  if((1<<i & mask)==(1<<i))
  { 
   w+=wt[i];
   v+=val[i];
  }
 }
 if(w<=7)
 {
  return v;
 }
 else
 {
  return 0;
 }
}
using namespace std;
int main()
{
 int ans=0;
 int sol;
 for(int i=0;i<allmask;i++)
 {
  if(ans<kp(i))
  {
   ans=kp(i);
   sol=i;
  }
 }
 cout<<ans<<endl;
 
 for(int i=0;i<n;i++)
 {
  if((1<<i & sol)==(1<<i))
  {
   cout<<wt[i]<<" ";
  }
 }
 cout<<endl;
 return 0;
}
 
 
 
