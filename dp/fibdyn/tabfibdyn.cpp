#include<bits/stdc++.h>
int cycle;
using namespace std;

int fib(int n,int a[])
{
 for(int i=2;i<=n;i++)
 {cycle++;
  a[i]=a[i-1]+a[i-2];
 }
 return a[n];
}
 
int main()
{
 int n;
 cin>>n;
 cycle=0;
 int a[n+1];
 a[0]=0;
 a[1]=1;
 cout<<fib(n,a)<<endl;
 cout<<cycle<<endl;

 return 0;
}
