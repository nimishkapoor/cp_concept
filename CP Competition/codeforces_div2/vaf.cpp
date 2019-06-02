#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,m,x,y,end=0,set=0,flag=1;
 cin>>n>>m;
 for(int i=0;i<n;i++)
 {
  if(x==0)
  {
   set=1;
  }
  cin>>x>>y;
  if(x>end)
  {
   flag=0;
  }

  end=max(y,end);
 }
 if(flag==1 && m<=end && set==1)
 {
  cout<<"YES"<<endl;
 }
 else
 {
  cout<<"NO"<<endl;
 }
 return 0;
}
