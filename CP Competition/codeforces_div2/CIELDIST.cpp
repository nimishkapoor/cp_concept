#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  float a,b,c,d;
  cin>>a>>b>>c;
  if(a+b>=c)
  {
   d=0;
  }
  if(c>a+b)
  {
   d=c-b-a;
  }
  if(a>c+b)
  {
   d=a-b-c;
  }
  if(b>a+c)
  {
   d=b-c-a;
  }
  cout<<d<<endl;
 }
 return 0;
}
