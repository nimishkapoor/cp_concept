#include<bits/stdc++.h>
using namespace std;
int main()
{
 string a,b;
 cin>>a>>b;
 bool flag=true;
 cout<<a[0];
 int i=1;
 while(flag && i<a.size())
 {
  if(a[i]<b[0])
  {
   cout<<a[i];
   i++;
  }
  else
  {
   flag=false;
  }
 }
 cout<<b[0]<<endl;
 return 0;
}
