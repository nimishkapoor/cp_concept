#include<bits/stdc++.h>
using namespace std;
int construct(int arr[],int *st,int *lazy,int ss,int se,int index)
{
 if(ss==se)
 {
  st[index]=arr[ss];
  lazy[index]=0;
  return arr[ss];
 }
 int mid=(ss+se)/2;
 st[index]=min(construct(arr,st,lazy,ss,mid,index*2+1),construct(arr,st,lazy,mid+1,se,index*2+2));
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
   lazy[index*2+1]+=lazy[index];
   lazy[index*2+2]+=lazy[index];
  }
  lazy[index]=0;
 }
 
 if(us<=ss && ue>=se)
 {
  st[index]+=add;
  if(ss!=se)
  {
   lazy[index*2+1]+=add;
   lazy[index*2+2]+=add;
  }
  lazy[index]=0;
 }
 
 else if(ue<ss || us>se)
 {
 }
 
 else
 {
  int mid=(ss+se)/2;
  update(st,lazy,ss,mid,us,ue,index*2+1,add);
  update(st,lazy,mid+1,se,us,ue,index*2+2,add);
  st[index]=min(st[index*2+1],st[index*2+2]);
 }
 
}  
int query(int *st,int *lazy,int ss,int se,int qs,int qe,int index)
{
 if(lazy[index]!=0)
 {
  st[index]+=lazy[index];
  if(ss!=se)
  {
   lazy[index*2+1]+=lazy[index];
   lazy[index*2+2]+=lazy[index];
  }
  lazy[index]=0;
 }
 if(qs<=ss && qe>=se)
 {
  return st[index];
 }
 if(qe<ss || qs>se)
 {
  return INT_MAX;
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
 construct(arr,st,lazy,0,n-1,0);
 update(st,lazy,0,n-1,1,5,0,3);
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

 
