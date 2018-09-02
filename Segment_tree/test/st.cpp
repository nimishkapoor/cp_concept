#include<bits/stdc++.h>
using namespace std;
int construct(int arr[],int *st,int ss,int se,int index)
{
 if(ss==se)
 {
  st[index]=arr[ss];
  return arr[ss];
 }
 int mid=(ss+se)/2;
 st[index]=min(construct(arr,st,ss,mid,index*2+1),construct(arr,st,mid+1,se,index*2+2));
 return st[index];
}
int query(int *st,int ss,int se,int qs,int qe,int index)
{
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
  return min(query(st,ss,mid,qs,qe,index*2+1),query(st,mid+1,se,qs,qe,index*2+2));
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
 construct(arr,st,0,n-1,0);
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

 
