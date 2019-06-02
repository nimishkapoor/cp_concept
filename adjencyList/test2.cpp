#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,count=0;
 cin>>n;
 char a[n][n];
 char s[2001];
 list<int> li[2001];
 for(int i=0;i<n;i++)
 {
  cin>>s; 
  for(int j=0;j<n;j++)
  {
   
   a[i][j]=s[j];
   if(a[i][j]=='1')
   {
    li[i].push_back(j);
   }
  }
 }
 for(int i=0;i<n;i++)
 {
  for(int j=i+1;j<n;j++)
  {
   if(a[i][j]=='0')
   {
    list<int>::iterator it;
    for(it=li[i].begin();it!=li[i].end();it++)
    {
     if(a[*it][j]=='1')
     {
      count++;
      break;
     }
    }
   }
  }
 }
 cout<<count*2<<endl;
 return 0;
}
 
