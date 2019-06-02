#include<bits/stdc++.h>
using namespace std;
void update(int bit[],int p,int v,int n)
{
 int index=p+1;
 while(index<=n)
 {
  bit[index]+=v;
  index+=index & (-index);
 }
}

void createBit(int a[],int bit[],int n)
{
 int index;
 for(int i=0;i<n;i++)
 {
  update(bit,i,a[i],n);
 }
}
int getSum(int bit[],int p)
{
 int sum=0,index=p+1;
 while(index>0)
 {
  sum+=bit[index];
  index-=index & (-index);
 }
 return sum;
}
  
int main()
{
 int n;
 cin>>n;
 int a[n];
 for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }
 int bit[n+1]={0};
 
 createBit(a,bit,n);
 for(int i=0;i<=n;i++)
 {
  cout<<bit[i]<<" ";
 }
 cout<<endl;

 cout<<getSum(bit,5)<<endl;
 update(bit,3,6,n);
 cout<<getSum(bit,5)<<endl;
 return 0;
}
