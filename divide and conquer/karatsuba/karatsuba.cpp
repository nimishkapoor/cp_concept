#include<bits/stdc++.h>
using namespace std;
int getlen(int x)
{
 int ans=0;
 while(x>0)
 {
  x=x/10;
  ans++;
 }
 return ans;
}
int mult(int x,int y,int n)
{
 if(n==1)
 {
  return x*y;
 }
 int xl=x/pow(10,n/2);
 int xr=x-(xl*pow(10,n/2));
 int yl=y/pow(10,n/2);
 int yr=y-(yl*pow(10,n/2));
 int p1=mult(xl,yl,n/2);
 int p2=mult(xr,yr,n/2);
 int p3=mult(xl+xr,yl+yr,n/2);
 return (p1*pow(10,n))+(p3-(p1+p2))*pow(10,n/2)+p2;
} 
int main()
{
 int x,y;
 cin>>x>>y;
 int n=getlen(x);
 cout<<mult(x,y,n)<<endl;
 return 0;
} 
