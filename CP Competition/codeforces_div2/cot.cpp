#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,ans=0;
 cin>>n;
 int edge[n+1]={0};
 int color[n+1]={0};
 int set[n+1]={0};
 for(int i=2;i<=n;i++)
 {
  cin>>edge[i];
 }
 for(int i=1;i<=n;i++)
 {
  cin>>color[i];
 }
 for(int i=1;i<=n;i++)
 {
  if(set[i]!=color[i])
  {
   set[i]=color[i];
   ans++;
  }
  for(int j=2;j<=n;j++)
  {
   if(edge[j]==i)
   {
    set[j]=color[i];
   }
  }
 }
 cout<<ans<<endl;
 return 0;
}
