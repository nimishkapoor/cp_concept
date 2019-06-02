#include<bits/stdc++.h>
using namespace std;
int pd(string s,int st,int en)
{
 if(st==en)
 {
  return 1;
 }
 if(st>en)
 {
  return 0;
 }
 if(s[st]==s[en])
 {
  return 2+pd(s,st+1,en-1);
 }
 else
 {
  return max(pd(s,st,en-1),pd(s,st+1,en));
 }
}
int main()
{
 string s;
 cin>>s;
 int l=s.size();
 cout<<pd(s,0,l-1)<<endl;
 return 0;
}
 
