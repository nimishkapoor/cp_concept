#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define inf 1000000000
vector<vector<ll> > a,b,c;
int main()
{
 ll t,m,n,i,j,temp;
 cin>>t;
 while(t--)
 {
  cin>>n>>m;

  a.clear();b.clear();c.clear();
  a.resize(n);b.resize(n);c.resize(n);
  for(i=0;i<n;i++)
  {
   a[i].resize(m);b[i].resize(m);c[i].resize(m);
  }
  for(i=0;i<n;i++)
  {
   for(j=0;j<m;j++)
   {
    cin>>a[i][j];
   }
  } 
  for(i=0;i<n;i++)
  {
   for(j=0;j<m;j++)
   {
    cin>>b[i][j];
   }
  }

  ll prev1=(ll)inf*inf,prev2;
  for(j=0;j<m;j++)
  {
   c[0][j]=a[0][j];
   prev1=min(prev1,c[0][j]);
  }
  
  for(i=1;i<n;i++)
  {
   prev2=(ll)inf*inf;
   for( j=0;j<m;j++)
   {
    temp=max(a[i][j]-b[i-1][j],0LL);
    c[i][j]=min((c[i-1][j]+temp),(a[i][j]+prev1));
    prev2=min(prev2,c[i][j]);
   }
   prev1=prev2;
  }
  ll ans=c[n-1][0];
  for( j=0;j<m;j++)
  {
   ans=min(ans,c[n-1][j]);		
  }
  cout<<ans<<endl;
 }
 return 0;
}
