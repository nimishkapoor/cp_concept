#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,flag=1;
  cin>>n;
  int a;
  int dp=0;
  for(int i=0;i<n;i++)
  {
   cin>>a;
   dp=a ^ dp;
  }
  if(dp==0 || n%2==0)
   flag=0;
  else
   flag=1;
  
  
  
  if(flag==0)
  {
   cout<<"First"<<endl;
  }
  else
  {
   cout<<"Second"<<endl;
  }
 }
 return 0;
}
