#include<bits/stdc++.h>
using namespace std;
int a[1000];
int maxcros(int l,int mid ,int h)
{
 int leftsum=INT_MIN;
 int rightsum=INT_MIN;
 int sum=0;

 
 for(int i=mid;i>=l;i--)
 {
  sum+=a[i];
  leftsum=max(leftsum,sum);
 }
 
 sum=0;
 for(int i=mid+1;i<=h;i++)
 {
  sum+=a[i];
  rightsum=max(rightsum,sum);
 }
 
 return leftsum+rightsum;
}
int maxsum(int l,int h)
{
 if(l==h)
 {
  return a[l];
 }
 
 int mid=(h+l)/2;
 int lf=maxsum(l,mid);
 
 int rt=maxsum(mid+1,h);
 
 int mcros=maxcros(l,mid,h);
 
 return max(mcros,max(lf,rt));
}

int main()
{
 int n;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
 }
 cout<<maxsum(1,n)<<endl;
 return 0;
}
