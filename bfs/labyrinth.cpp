#include<bits/stdc++.h>
using namespace std;
int n,m,val[1001][1001];
bool isvalid(int x,int y)
{
 if(x<=n && y<=m && x>=1 && y>=1 && val[x][y]!=-1)
 {
  return true;
 }
 else
 {
  return false;
 }
}
int main()
{
 int t;
 int vis[1001][1001];
 set<pair<int,pair<int,int>>,greater<pair<int,pair<int,int>>>> s;
 cin>>t;
 while(t--)
 {
  s.clear();
  cin>>n>>m;
  memset(vis,0,sizeof (vis));
  for(int i=1;i<=n;i++)
  {
   for(int j=1;j<=m;j++)
   {
    cin>>val[i][j];
    if(val[i][j]>0)
    {
     s.insert(make_pair(val[i][j],make_pair(i,j)));
    }
   }
  }
 while(!s.empty())
 {
  auto it=s.begin();
  int time=(*it).first;
  int x=(*it).second.first;
  int y=(*it).second.second;
  vis[x][y]=1;
  if(it!=s.end())
  {
   s.erase(it);
  }
  if(time==0)
  continue;
  if(isvalid(x-1,y) && vis[x-1][y]==0)
  {
   it=s.find(make_pair(val[x-1][y],make_pair(x-1,y)));
   if(it!=s.end())
   {
    s.erase(it);
   }
   val[x-1][y]=max(val[x-1][y],time-1);
   s.insert(make_pair(val[x-1][y],make_pair(x-1,y)));
  }
  if(isvalid(x+1,y) && vis[x+1][y]==0)
  {
   it=s.find(make_pair(val[x+1][y],make_pair(x+1,y)));
   if(it!=s.end())
   {
    s.erase(it);
   }
   val[x+1][y]=max(val[x+1][y],time-1);
   s.insert(make_pair(val[x+1][y],make_pair(x+1,y)));
  }
  if(isvalid(x,y-1) && vis[x][y-1]==0)
  {
   it=s.find(make_pair(val[x][y-1],make_pair(x,y-1)));
   if(it!=s.end())
   {
    s.erase(it);
   }
   val[x][y-1]=max(val[x][y-1],time-1);
   s.insert(make_pair(val[x][y-1],make_pair(x,y-1)));
  }
  if(isvalid(x,y+1) && vis[x][y+1]==0)
  {
   it=s.find(make_pair(val[x][y+1],make_pair(x,y+1)));
   if(it!=s.end())
   {
    s.erase(it);
   }
   val[x][y+1]=max(val[x][y+1],time-1);
   s.insert(make_pair(val[x][y+1],make_pair(x,y+1)));
  }
 }  
  for(int i=1;i<=n;i++)
  {
   for(int j=1;j<=m;j++)
   {
    if(val[i][j]==-1)
    {
     cout<<'B';
    }
    else if(vis[i][j]==1)
    {
     cout<<'Y';
    }
    else if(vis[i][j]==0)
    {
     cout<<'N';
    }
   }
   cout<<endl;
  }
 }
 return 0;
} 

