#include<bits/stdc++.h>
using namespace std;
int f(int n)
{
 if(n==1 || n==2)
 {
  return n;
 }
 return ((n-1)*f(n-2))+f(n-1);
}
int main()
{
 int n;
 cin>>n;
 cout<<f(n)<<endl;
 return 0;
}
