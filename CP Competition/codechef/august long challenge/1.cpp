#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t; 
 cin>>t;

 while(t--)
 {
  int n,flag=0,count=1;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
   cin>>a[i];
  
  }
  for(int i=0;i<=n/2;i++)
  {if(a[i+1]>a[i])
   {
    count++;
   }
   if(a[i]==a[(n-1)-i] && a[i]<=7 && n>=7  )
   {
    flag=1;
   }
   else
   {
    flag=0;
    break;
   }
  }
  if(flag==1 && count ==7)
  {
   cout<<"yes"<<endl;
  }
  else
  {
   cout<<"no"<<endl;
  }
 }
 return 0;
}
