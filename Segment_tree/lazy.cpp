#include<bits/stdc++.h>
using namespace std;
int construct(int *lazy,int arr[],int *st,int ss,int se,int index)
{
 if(ss==se)
 {
  st[index]=arr[ss];
  lazy[index]=0;
  return arr[ss];
 }
 int mid=(ss+se)/2;
 st[index]=min(construct(lazy,arr,st,ss,mid,index*2+1),construct(lazy,arr,st,mid+1,se,index*2+2));
 lazy[index]=0;
 return st[index];
}
void update(int *st,int *lazy,int ss,int se,int us,int ue,int index,int add)
{
 if(lazy[index]!=0)
 {
  st[index]+=lazy[index];
  if(ss!=se)
  {
   lazy[index*2+1]=lazy[index];
   lazy[index*2+2]=lazy[index];
  }
  lazy[index]=0;
 }
 if(ss<=us && se>=ue)
 {
  st[index]+=add;
  if(ss!=se)
  {
  lazy[index*2+1]+=add;
  lazy[index*2+2]+=add;
  }
 }
 else
 {
  int mid=(ss+se)/2;
  update(st,lazy,ss,mid,us,ue,index*2+1,add);
  update(st,lazy,mid+1,se,us,ue,index*2+2,add);
 }
 st[index]=min(st[index*2+1],st[index*2+2]);
}
int query(int *st,int*lazy,int ss,int se,int qs,int qe,int index)
{
 if(lazy[index]!=0)
 {
  st[index]+=lazy[index];
  if(ss!=se)
  {
  lazy[index*2+1]=lazy[index];
  lazy[index*2+2]=lazy[index];
  }
  lazy[index]=0;
 }
 if(se<qs || qe<ss)
 {
  return INT_MAX;
 }
 if(ss>=qs && se<=qe)
 {
  return st[index];
 }
 else
 {
  int mid=(ss+se)/2;
  return min(query(st,lazy,ss,mid,qs,qe,index*2+1),query(st,lazy,mid+1,se,qs,qe,index*2+2));
 }
}
   
int main()
{
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++)
 {
  cin>>arr[i];
 }
 int x=(int)(ceil(log2(n)));
 int size=2*(int)pow(2,x)-1;
 int *st=new int[size];
 int *lazy=new int[size];
 construct(lazy,arr,st,0,n-1,0);
 int us,ue,add;
 cin>>us>>ue>>add;
 update(st,lazy,0,n-1,us,ue,0,add);
 int t;
 cin>>t;
 while(t--)
 {
  int qs,qe;
  cin>>qs>>qe;
  cout<<query(st,lazy,0,n-1,qs,qe,0)<<endl;
 }  
 return 0;
}  
