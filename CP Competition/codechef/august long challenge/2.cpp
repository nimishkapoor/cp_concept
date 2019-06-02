#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long int t;
 cin>>t;
 while(t--)
 {
  long long int n,d,flag=1,moves=0;
  cin>>n>>d;
  long long int a[n+1];
  for(long long int i=1;i<=n;i++)
  {
   cin>>a[i];
  }
  for(long long int i=1;i<=n;i++)
  {
   for(long long int j=1;j<=n;j++)
   {if(i<j)
    {
    if((i+d-j)==0)
    {
     moves++;
     a[i]--;
     a[j]++;
    }
    }
    else
    {
    if((i-d-j)==0)
    {
     moves++;
     a[i]--;
     a[j]++;
    }
    }

   }
  }
  for(long long int i=1;i<=n;i++)
  {
   cout<<a[i];
  }    
  for(long long int i=1;i<=n;i++)
  {
   if(a[i]!=a[1])
   {
    flag=0;
    break;
   }
  }
  if(flag==1)
  {
   cout<<moves<<endl;
  }
  else
  {
   cout<<-1<<endl;
  }
 }
 return 0;
}
