#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int a[n+1];
 memset(a,0,sizeof a);
 a[0]=1;
 for(int i=3;i<=n;i++)
 {
  a[i]+=a[i-3];
 }
 for(int i=5;i<=n;i++)
 {
  a[i]+=a[i-5];
 }
 for(int i=8;i<=n;i++)
 {
  a[i]+=a[i-8];
 }
 cout<<a[n]<<endl;
 return 0;
}
