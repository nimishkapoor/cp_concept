#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,m,a,b,c,d;
 cin>>n>>m;
 map< pair<int,int>, int> val;
 map< pair<int,int>, int> prior;
 for(int i=0;i<n;i++)
 {
  cin>>a>>b>>c>>d;
  if(val[make_pair(a,b)]==0)
  {
   val[make_pair(a,b)]=c;
   prior[make_pair(a,b)]=d;
  }
  else if(prior[make_pair(a,b)]<=d)
  {
   val[make_pair(a,b)]=c;
   prior[make_pair(a,b)]=d;
  }
 }
 for(int i=0;i<m;i++)
 {
  cin>>a>>b;
  cout<<val[make_pair(a,b)]<<endl;
 }
 return 0;
}
