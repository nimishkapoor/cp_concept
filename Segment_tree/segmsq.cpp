#include<bits/stdc++.h>
using namespace std;
int construct(int *st,int arr[],int ss,int se,int si)
{
 if(ss==se)
 {
  st[si]=arr[ss];
  return arr[ss];
 }
 int mid=(ss+se)/2;
 st[si]=min(construct(st,arr,ss,mid,si*2+1),construct(st,arr,mid+1,se,si*2+2));
 return st[si];
}
int query(int *st,int ss,int se,int qs,int qe,int si)
{
 if(qs>se || qe<ss)
 {
  return INT_MAX;
 }
 if(qs<=ss && qe>=se)
 {
  return st[si];
 }
 else
 {
  int mid=(ss+se)/2;
  return min(query(st,ss,mid,qs,qe,si*2+1),query(st,mid+1,se,qs,qe,si*2+2));
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
 construct(st,arr,0,n-1,0);
 int t;
 cin>>t;
 while(t--)
 {
  int qs,qe;
  cin>>qs>>qe;
  cout<<query(st,0,n-1,qs,qe,0)<<endl;
 }
 return 0;
}

