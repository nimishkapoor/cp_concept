#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,count=0;
 cin>>n;
 char a[n][n];
 char s[2001];
 for(int i=0;i<n;i++)
 {
  cin>>s; 
  for(int j=0;j<n;j++)
  {
   
   a[i][j]=s[j];
   
  }
 }
 int m[n][n]={0};
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
  {
   if(a[i][j]=='1')
   {
    for(int k=0;k<n;k++)
    {
     if(a[j][k]=='0' && a[i][k]=='1' && j!=k &&m[j][k]!=1)
     {//cout<<i<<" "<<j<<" "<<k<<endl;
      count++;	
      m[j][k]=1;
     }
    }
   }
  }
 }
 cout<<count<<endl;
 return 0;
}
