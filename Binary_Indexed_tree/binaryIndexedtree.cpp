#include<bits/stdc++.h>
using namespace std;
void createBit(int a[],int bit[],int n)
{
 int index;
 for(int i=0;i<n;i++)
 {
  index=i+1;
  while(index<=n)
  { 
   bit[index]+=a[i];
   index+=index & (-index);
  }
 }
}
void update(int bit[],int v,int pos,int n)
{
 int index=pos+1;
 while(index<=n)
 {
  bit[index]+=v;
  index+=index & (-index);
 }
}
int getSum(int bit[],int v)
{
 int sum=0;
 int index=v+1;
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
 cout<<getSum(bit,5)<<endl;
 update(bit,6,3,n);
 cout<<getSum(bit,5)<<endl;
 return 0;
}
