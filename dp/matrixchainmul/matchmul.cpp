#include<bits/stdc++.h>
using namespace std;
int mam( vector< pair<int,int> > l)
{
 int dp[5][5]={0};
 for(int len=1;len<=4;len++)
 {
  for(int i=0;i<4;i++)
  {
   int j=i+len;
   int k;
   int temp=min(dp[i][j-1],dp[i+1][j]);
   if(temp==dp[i+1][j])
   {
    k=l[i+1].first;
   }
   else
   {
    k=l[j-1].second;
   }
   dp[i][j]=temp+l[i].first*l[j].second*k;
   //cout<<l[i].first<<" "<<l[j].second<<" "<<l[i].first*l[j].second*l[i].second<<endl;
  }
 }
 for(int i=0;i<4;i++)
 {
  for(int j=0;j<4;j++)
  {
   cout<<dp[i][j]<<" ";
  }
  cout<<endl;
 }
 return dp[0][3];
}
int main()
{
 vector< pair<int,int> > l;
 //l.push_back(make_pair(1,2));
// l.push_back(make_pair(2,3));
// l.push_back(make_pair(3,4));
 l.push_back(make_pair(50,10));
 l.push_back(make_pair(10,40));
 l.push_back(make_pair(40,30));
 l.push_back(make_pair(30,5));
 cout<<mam(l)<<endl;
 return 0;
}
