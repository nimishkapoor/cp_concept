#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int n,m,c=0;
  cin>>n>>m;
  int max=0;
  int a[1000000]={0};
  for(int i=0;i<n;i++)
  {
   int x;
   cin>>x;
   a[x]=1;
   if(x>max)
   max=x;
  }
 // for(int i=0;i<=max;i++)
  //{
   //cout<<a[i]<<endl;
  //}
 // cout<<max<<endl;
 // cout<<"exit1"<<endl;
  int j=0;
  for(int i=0;i<=max && m!=0;i++)
  {
   if(a[i]==0)
   {
    a[i]=1;
    m--;
   }
//   cout<<i<<"loop1"<<a[i]<<endl;
  }

  //cout<<max+m<<endl;
  for(int i=max;i<=max+m;i++)
  {
   a[i]=1;
   c++;
   //cout<<i<<" "<<a[i]<<endl;
  }
  // cout<<"exit2"<<endl;
  int flag=0;
  for(int i=0;i<=(max+c);i++)
  {//cout<<a[i]<<endl;
   if(a[i]==0)
   {
    cout<<i<<endl;
    flag=0;
   // cout<<"exit3"<<endl;
    break;
	
   }
   flag=1;
  }
  if(flag==1)
  {
   cout<<max<<endl;
  }

  // cout<<"exit3"<<endl;
 }
 return 0;
}
