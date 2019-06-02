#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
int sol(int A)
{
   int result = 0;
   for ( ; A; A /= 2 ) result += A % 2;
   return result;
}
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  ll a,b,s,c;
  cin>>a>>b;
  s=b-1;
  if(a==b)
  cout<<0<<endl;
  else if (b==0)
  cout<<-1<<endl;  
  else if(b==1)
  cout<<(a==0 ? 1 : -1)<<endl;
  else
  c=sol(s)-sol(a)+1;
  cout<<(c>0 ? c:2)<<endl;
 }
 return 0;
}
