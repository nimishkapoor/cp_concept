#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n;
  double count=0;
  cin>>n;
  double a[n];
  for(int i=0;i<n;i++)
  {
   cin>>a[i];
  }
  


  double sm=0;
  for(int i=0;i<n;i++)
  {
   for(int j=i+1;j<n;j++)
   {
    if(a[j]+a[i]>sm)
    {
     sm=a[j]+a[i];
    }
   }
  }
  
  for(int i=0;i<n;i++)
  {
   for(int j=i+1;j<n;j++)
   {
    if(a[j]+a[i]==sm)
    {
     count++;
    }
   }
  } 
  


  double s=((n-1)*((n-1)+1))/2;
  
  double ans=count/s;
 
  
  cout << fixed;
  cout << setprecision(8);

  cout<<ans<<endl;
 }
 return 0;
}
 
