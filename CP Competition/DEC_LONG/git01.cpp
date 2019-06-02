#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,m,count=0,count2=0;
  cin>>n>>m;
  char a[n][m];
  char s[101];
  for(int i=0;i<n;i++)
  {
   cin>>s;
   for(int j=0;j<m;j++)
   {
    a[i][j]=s[j];
   }
  }
  for(int i=0;i<n;i++)
  {
   if(i%2==0)
   {
    for(int j=0;j<m;j++)
    {
     if(j%2==0)
     {
      if(a[i][j]=='R')
      continue;
      else
      count+=3;
     }
     else
     {
      if(a[i][j]=='G')
      continue;
      else
      count+=5;
     }
    }
   }
   else
   {
    for(int j=0;j<m;j++)
    {
     if(j%2==0)
     {
      if(a[i][j]=='G')
      continue;
      else
      count+=5;
     }
     else
     {
      if(a[i][j]=='R')
      continue;
      else
      count+=3;
     }
    }
   }   
  }
  for(int i=0;i<n;i++)
  {
   if(i%2==1)
   {
    for(int j=0;j<m;j++)
    {
     if(j%2==0)
     {
      if(a[i][j]=='R')
      continue;
      else
      count2+=3;
     }
     else
     {
      if(a[i][j]=='G')
      continue;
      else
      count2+=5;
     }
    }
   }
   else
   {
    for(int j=0;j<m;j++)
    {
     if(j%2==0)
     {
      if(a[i][j]=='G')
      continue;
      else
      count2+=5;
     }
     else
     {
      if(a[i][j]=='R')
      continue;
      else
      count2+=3;
     }
    }
   }   
  }
  cout<<min(count,count2)<<endl;
 }
 return 0;
}
