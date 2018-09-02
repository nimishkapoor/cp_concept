#include<bits/stdc++.h>
using namespace std;
int solve(int a,int b,int c)
{//cout<<"case"<<endl;
 int ans=0;
 int x=0;
 int y=0;

 while(x!=c and y!=c)
 {
  if(x==0)
  {
   x=a;
  }
  else if(y==b)
  {
   y=0;
  }
  else
  {
   y=y+x;
   x=0;
   if(y>b)
   {
    x=y-b;
    y=b;
   }
  }
 ans++;
 //cout<<x<<" "<<y<<endl;///steps
 }
 return ans;
}
 
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int a,b,c;
  cin>>a>>b>>c;
  
  if(c>max(a,b))
  {
   cout<<-1<<endl;
  }
  else if(c==a || c==b)
  {
   cout<<1<<endl;
  }
  else if((c%__gcd(a,b))==0)
  {
   cout<<min(solve(a,b,c),solve(b,a,c))<<endl;
  }
  else
  {
   cout<<-1<<endl;
  }
 }
 return  0;
}
