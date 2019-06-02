#include<bits/stdc++.h>
using namespace std;
int main()
{
 
 string s1,s2;
 cin>>s1>>s2;
 int l1=s1.size();
 int l2=s2.size();
 int a[l1+1][l2+1]={0};
 for(int i=0;i<=l1;i++)
 {
  a[i][0]=i;
 }
 for(int i=0;i<=l2;i++)
 {
  a[0][i]=i;
 }

 
 for(int i=1;i<=l1;i++)
 {
  for(int j=1;j<=l2;j++)
  {
   if(s1[i-1]==s2[j-1])
   {
    a[i][j]=a[i-1][j-1];
   }
   else
   {
    int t=min(a[i-1][j-1],a[i-1][j]);
    a[i][j]=min(t,a[i][j-1])+1;
   }
  }
 }
 int i=l1,j=l2;
 while(true)
 {
  if(i==0 || j==0)
  {
   break;
  }
  if(a[i][j]==(a[i-1][j-1]+1))
  {
   cout<<"Edit:"<<s2[j-1]<<" with "<<s1[i-1]<<endl;
   i=i-1;
   j=j-1;
  }
  if(a[i][j]==(a[i-1][j]+1))
  {
   cout<<"Delete :"<<s1[j-1]<<endl;
   i=i-1;
  }
  if(a[i][j]==(a[i][j-1]+1)) 
  {
   cout<<"Delete :"<<s2[j-1]<<endl;
   j=j-1;
  }
  if(s1[i-1]==s2[j-1])
  {
   i=i-1;
   j=j-1;
  }
 }
 cout<<a[l1][l2]<<endl;
 return 0;
}
