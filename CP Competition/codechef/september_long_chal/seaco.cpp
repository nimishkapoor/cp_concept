#include<bits/stdc++.h>

using namespace std;
void rec(int *a,int *t,int *l,int *r,int x)
{
 if(t[x]==1){
  for(int i=l[x];i<=r[x];i++)
    a[i]++;
   return;} 
 else{
  for(int j=l[x];j<=r[x];j++){
    rec(a,t,l,r,j);}
  return;}
}


int main()
{
 int t;
 cin>>t;
 while(t--)
 { 
  int n,m;
  cin>>n>>m;
  int a[n+1]={0};
  int t[m+1],l[m+1],r[m+1];
  
  for(int i=1;i<=m;i++)
  {
   cin>>t[i]>>l[i]>>r[i];
   rec(a,t,l,r,i);
  }
  for(int i=1;i<=n;i++)
  { 
   cout<<a[i]<<" ";
  }
  cout<<endl;
 }
 return 0;
}
   
