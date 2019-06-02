#include<bits/stdc++.h>
using namespace std;
int bicof(int p,int t)
{
 if(p==t || t==0)
 {
  return 1;
 }
 return bicof(p-1,t)+bicof(p-1,t-1);
}
int main()
{
 int p,t;
 cin>>p>>t;
 cout<<bicof(p,t)<<endl;
 return 0;
}
