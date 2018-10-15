#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,count=0;

  cin>>n;
  string s;
  cin>>s;
  int a[26]={0};
  for(int i=0;i<n;i++)
  {
   a[s[i]-97]++;
  }
  for(int i=0;i<26;i++)
  {
    if(a[i]%2!=0)
     count++;
  }
  if(count<=1)
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
