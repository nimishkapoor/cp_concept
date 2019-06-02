#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long int t;
 cin>>t;
 while(t--)
 {
  long long int n,ps=0,ss=0,in,prevmin=LONG_MAX;
  cin>>n;
  long long int a[n];
  for(int i=0;i<n;i++)
  {
   cin>>a[i];
   ss=ss+a[i];
  }
  
  for(int i=0;i<n;i++)
  {
   ps=ps+a[i];
   
   if(prevmin>(ss+ps))
   {
    prevmin=ss+ps;
    in=i+1;
   }
   //cout<<"ss="<<ss<<" ps="<<ps<<" ss+ps "<<ss+ps<<" prevmin="<<prevmin<<" index="<<in<<endl;
   ss=ss-a[i];
  }
  cout<<in<<endl;
 }
 return 0;
}
  
