#include<bits/stdc++.h>
using namespace std;

int fib(int n,int a[])
{
 if(a[n]!=-1)
 {
  return a[n];
 }
 if(n==0)
 {
  return a[n]=0;
 }
 if(n==1)
 {
  return a[n]=1;
 }
 return a[n]=fib(n-1,a)+fib(n-2,a);
}
 
int main()
{
 int n;
 cin>>n;
 int a[n+1];
 memset(a,-1,sizeof a);
 cout<<fib(n,a)<<endl;


 return 0;
}
