#include<bits/stdc++.h>
using namespace std;
struct pairs
{
 int a;
 int b;
};
int main()
{
 int n;
 cin>>n;
 int mcl[n];
 struct pairs arr[n];
 for(int i=0;i<n;i++)
 {
  cin>>arr[i].a>>arr[i].b;
  mcl[i]=1;
 }
 int ans=0;
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<i;j++)
  {
   if(arr[i].a>arr[j].b)
   {
    mcl[i]=max(mcl[i],mcl[j]+1);	
    ans=max(ans,mcl[i]);
   }
  }
 }
 for(int i=0;i<n;i++)
 {
  cout<<mcl[i]<<" ";
 }
 cout<<endl;
 cout<<ans<<endl;
 return 0;
}
