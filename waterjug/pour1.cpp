#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair

using namespace std;

void bfs(int a,int b, int target)
{
 vector<pii> path;
 map<pii,int> m;
 queue<pii> q;
 bool isSolvable=false;
 q.push({0,0});
 while(!q.empty())
 {
  pii  u=q.front();
  q.pop();
  if(m[{u.first,u.second}]==1)
  {
   continue;
  }
  if((u.first>a||u.second>b||u.first<0||u.second<0))
  {
   continue;
  }
  path.push_back({u.first,u.second});
  m[{u.first,u.second}]=1;
  if(u.first==target|| u.second==target)
  {
   isSolvable=true;
   if(u.first==target)
   {
    if(u.second!=0)
    {
     path.push_back({u.first,0});
    }
   }
  
  else
  {
   if(u.first!=0)
   {
    path.push_back({0,u.second});
   }
  }
  int sz=path.size();
  for(int i=0;i<sz;i++)
  {
   cout<<"("<<path[i].first<<","<<path[i].second<<")"<<endl;
  }
  cout<<sz<<endl;
  break;
  }
  q.push({u.first,b});
  q.push({a,u.second});
  
  for(int ap=0;ap<=max(a,b);ap++)
  {
   int c=u.first+ap;
   int d=u.second-ap;
   if(c==a||(d==0&&d>=0))
   {
    q.push({c,d});
   }
   c=u.first-ap;
   d=u.second+ap;

   if((c==0 && c>=0) || d==b)
   {
    q.push({c,d});
   }
  }
  q.push({a,0});
  q.push({0,b});
 }
 if(!isSolvable)
 {
  cout<<-1<<endl;
 }
}

int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int a,b,c;
  cin>>a>>b>>c;
  bfs(a,b,c);
 }
 return 0;
}
  
