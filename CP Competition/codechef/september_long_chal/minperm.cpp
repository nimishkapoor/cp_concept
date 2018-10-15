#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n;
  cin>>n;
  int i=1;
  
  while(i<=n)
  {
  
    if(i!=n-2)
    {
    cout<<i+1<<" "<<i<<" ";
    i+=2;
    }
    else
    {
     cout<<i+1<<" "<<i+2<<" "<<i;
     break;
    }   
   
  }
  cout<<endl;
 }
 return 0;
}
