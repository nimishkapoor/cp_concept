#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int r[1001]={0};
 for(int i=0;i<n;i++)
 {
  int x;
  cin>>x;
  if(r[x]==0)
  {
   r[x]=1;
  }
  else
  {
   r[x]=0;
  }
 }
 bool flag=true;
 for(int i=0;i<1001;i++)
 {
  if(r[i]==1)
  {
   flag=false;
   break;
  }
 }
 if(flag==true)
 {
  cout<<"no"<<endl;
 }
 else
 {
  cout<<"yes"<<endl;
 }
 return 0;
}
