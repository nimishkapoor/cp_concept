#include<iostream>
using namespace std;
#define INT_MAX 999999
int dp[16][4];
int n=4;
int dist[10][10] ={
       {0,20,42,25},
       {20,0,30,34},
       {42,30,0,10},
       {25,34,10,0}
};

int va=(1<<n)-1;
int tsp(int mask,int pos)
{
 if(mask==va)
 {
  return dist[pos][0];
 }
 
 if(dp[mask][pos]!=-1)
 {
  return dp[mask][pos];
 }
 int ans=INT_MAX;
 for(int i=0;i<n;i++)
 {
  if((mask & (1<<i))==0)
  {
   int newAns= dist[pos][i] + tsp( mask | (1<<i) ,i);
   ans=min(ans, newAns);
  }
 }
 //return ans; 
 return dp[mask][pos]=ans;
}
int main()
{
 
 for(int i=0;i<(1<<n);i++)
 {
  for(int j=0;j<n;j++)
  {
   dp[i][j]=-1;
  }
 }
 cout<<tsp(1,0)<<endl;
 return 0;
}
