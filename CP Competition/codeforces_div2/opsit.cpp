#include<bits/stdc++.h>
using namespace std;
int main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL);
 int n;
 cin>>n;
 int one=0,two=0,count=0,x;
 for(int i=0;i<n;i++)
 {
  cin>>x;
  if(x==2)
  {
   two++;
  }
  else
  {
   one++;
  }
 }
 if(two>=one)
 {
  count+=one;
 }
 else if(one>two && two>0)
 {
  count+=two;
  one=one-two;
  count+=(one/3);
 }
 else if(one>two)
 {
  count+=one/3;
 }
 cout<<count<<endl;
 return 0;
}
