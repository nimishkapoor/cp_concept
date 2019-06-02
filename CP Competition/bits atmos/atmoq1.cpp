#include<bits/stdc++.h>
using namespace std;
bool cmp(string x,string y,int k)
{
 //int c1=0;
 int a[26]={0},b[26]={0};
 for(int i=0;i<y.length();i++)
 {
  a[y[i]-97]=1;
 }
 //for(int i=0;i<26;i++)
 //{
 // if(a[i]==1)
 // {
 //  c1++;
 // }
 //cout<<c1<<endl;
 //}
 for(int i=0;i<x.length();i++)
 {
  b[x[i]-97]=1;
 }
 int c=0;
 for(int i=0;i<26;i++)
 {
  if(a[i]==1 && b[i]==1)
  {
   c++;
  }
 }
 if(k<=c)
 {
  return true;
 }
 else
 {
  return false;
 }
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,m,count=0;
  string s,x;
  cin>>s;
  cin>>n>>m;
  vector<string> s1;
  vector<string> s2;
  for(int i=0;i<n;i++)
  {
   cin>>x;
   s1.push_back(x);
  }
  for(int i=0;i<n;i++)
  {
   if(cmp(s,s1[i],m))
   {
    s2.push_back(s1[i]);
   }
   //cout<<i<<" "<<cmp(s,s1[i])<<endl;
  }
  if(s2.size()!=0)
  {
   cout<<"Yes"<<endl;
   for(int i=0;i<s2.size();i++)
   {
    cout<<s2[i]<<endl;
   }
  }
  else
  {
   cout<<"No"<<endl;
  }
 }
 return 0;
}
