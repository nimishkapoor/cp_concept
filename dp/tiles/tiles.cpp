#include<bits/stdc++.h>
using namespace std;
int rec(int n)
{
 if(n==1 || n==2)
 {
  return n;
 }
 return rec(n-1)+rec(n-2);
}
int main()
{
 int n;
 cin>>n;
 cout<<rec(n)<<endl;
 return 0;
}
