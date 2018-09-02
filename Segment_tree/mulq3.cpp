#include<bits/stdc++.h>
using namespace std;
const int size=1e6+100;
struct node
{
 int s0;
 int s1;
 int s2;
}st[size];
int lazy[size];
node operator + (node x,node y)
{
 return node{x.s0+y.s0,x.s1+y.s1,x.s2+y.s2};
}
void construct(int ss,int se,int index)
{
 if(ss==se)
 {
  st[index]={1,0,0};
  return;
 }
 int mid=(ss+se)/2;
 construct(ss,mid,index*2+1);
 construct(mid+1,se,index*2+2);
 st[index]=st[index*2+1]+st[index*2+2];
}
void update(int ss,int se,int us,int ue,int index)
{
 if(lazy[index]!=0)
 {
  if(lazy[index]%3==1)
  {
   swap(st[index].s1,st[index].s2);
   swap(st[index].s0,st[index].s1);
  }
  else if(lazy[index]%3==2)
  {
   swap(st[index].s0,st[index].s2);
   swap(st[index].s0,st[index].s1);
  }
  if(ss!=se)
  {
   lazy[index*2+1]+=lazy[index];
   lazy[index*2+2]+=lazy[index];
  }
  lazy[index]=0;
 }
 if(us>se || ue<ss || ss>se)
 { 
  return;
 }
 if(us<=ss && ue>=se)
 {
  swap(st[index].s1,st[index].s2);
  swap(st[index].s0,st[index].s1);
  if(ss!=se)
  {
   lazy[index*2+1]+=1;
   lazy[index*2+2]+=1;
  }
  return;
 }
 int mid=(ss+se)/2;
 update(ss,mid,us,ue,index*2+1);
 update(mid+1,se,us,ue,index*2+2);
 st[index]=st[index*2+1]+st[index*2+2];
}
int query(int ss,int se,int qs,int qe,int index)
{
 if(qs>se || qe<ss)
 {
  return 0;
 }
 if(lazy[index]!=0)
 {
  if(lazy[index]%3==1)
  {
   swap(st[index].s1,st[index].s2);
   swap(st[index].s0,st[index].s1);
  }
  if(lazy[index]%3==2)
  {
   swap(st[index].s0,st[index].s2);
   swap(st[index].s0,st[index].s1);
  }
  if(ss!=se)
  {
   lazy[index*2+1]+=lazy[index];
   lazy[index*2+2]+=lazy[index];
  }
  lazy[index]=0;
 }
 
 if(qs<=ss && qe>=se)
 {  
  return st[index].s0;
 }
 int mid=(ss+se)/2;
 return query(ss,mid,qs,qe,index*2+1)+query(mid+1,se,qs,qe,index*2+2);
}
int main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL);
 int n,q;
 cin>>n>>q;
 construct(0,n-1,0);
 for(int i=0;i<q;i++)
 {
  int x,y,z;
  cin>>x>>y>>z;
  if(x==1)
  {
   cout<<query(0,n-1,y,z,0)<<endl;
  }
  else
  {
   update(0,n-1,y,z,0);
  }
 }
 return 0;
} 
  
