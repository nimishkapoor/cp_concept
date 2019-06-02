#include<bits/stdc++.h>
using namespace std;
int knapsack(int n,int w,int wt[],int val[])
{
 if(n==0||w==0)
 {
  return 0;
 }
 if(wt[n-1]>w)
 {
  knapsack(n-1,w,wt,val);
 }
 return max(val[n-1]+knapsack(n-1,w-wt[n-1],wt,val),knapsack(n-1,w,wt,val));
}
int main()
{
 int n;
 cin>>n;
 int w;
 cin>>w;
 int val[n];
 int wt[n];
 for(int i=0;i<n;i++)
 {
  cin>>wt[i];
 }
 for(int i=0;i<n;i++)
 {
  cin>>val[i];
 }
 cout<<knapsack(n,w,wt,val)<<endl;
 return 0;
}
