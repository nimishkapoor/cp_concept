#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,k;
 cin>>n>>k;
 int total= k;
 int same=0,diff=k;
 for(int i=2;i<=n;i++)
 {
  same=diff;
  diff=total*(k-1);
  total=same+diff;
 }
 cout<<total<<endl;
 return 0;
}
