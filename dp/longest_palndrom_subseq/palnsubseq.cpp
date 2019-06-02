#include<bits/stdc++.h>
using namespace std;
int pd(string s,int start,int n)
{
 if(start==n)
 {
  return 1;
 }
 if(s[start]==s[n] && start+1==n)
 {
  return 0;
 }
   
 if(s[start]==s[n])
 {
  return 2+pd(s,start+1,n-1);
 }
 else
 {
  return max(pd(s,start,n-1),pd(s,start+1,n));
 }
}
int  main()
{
 string s;
 cin>>s;
 int l=s.size();
 cout<<pd(s,0,l-1)<<endl;
}
