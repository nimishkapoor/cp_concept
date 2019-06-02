#include<bits/stdc++.h>
using namespace std;
bool isPerfectSquare(int x)
{
    int s = sqrt(x);
    return (s*s == x);
}
 

bool isFibonacci(int n)
{
    return isPerfectSquare(5*n*n + 4) ||
           isPerfectSquare(5*n*n - 4);
}
int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  if(isFibonacci(i)==1)
  {
   cout<<'O';
  }
  else
  {
   cout<<'o';
  }
 }
 cout<<endl;
 return 0;
}
