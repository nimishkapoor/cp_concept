#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long int t;
 cin>>t;
 while(t--)
 {
  long long int n;
  cin>>n;
  long long int a[n];
  for(int i=0;i<n;i++)
  {
   cin>>a[i];
  }
  long long int mins=999999999,sum1=0,sum2=0;
  long long 
int minIn;
  for(int i=0;i<n;i++)
  {
   sum1=0,sum2=0;
   int j=0;
   while(j<=i)
   {
    sum1+=a[j];
    j++;
   }
   //cout<<sum1<<endl;
   j--;
   while(j<n)
   {
    sum2+=a[j];
    j++;
   }
   //cout<<sum2<<endl;
   if((sum1+sum2)<mins)
   {
    mins=sum1+sum2;
    //cout<<mins<<endl;
    minIn=i;
   }
  }
  cout<<minIn+1<<endl;
 }
 return 0;
}
