#include<bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
 int n,m;
 cin>>n>>m;
 map<string,string> s;
 string x,y;
 for(int i=0;i<n;i++)
 {
  cin>>x>>y;
  s.insert(pair<string,string>(y,x));
 }
 for(int i=0;i<m;i++)
 {
  cin>>x>>y;
  y.pop_back();
  auto it=s.find(y);
  if(it!=s.end())
  {
   cout<<x<<" "<<y<<';'<<" "<<'#'<<(*it).second;
  }
  cout<<endl;	
 }
 return 0;
} 

 
