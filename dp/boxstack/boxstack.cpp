#include<bits/stdc++.h>
using namespace std;
struct Box
{
 int h;
 int b;
 int l;
};
int compare(const  void *x,const void *y)
{
 return ((*(Box *)y).l*(*(Box *)y).b)-((*(Box *)x).l*(*(Box *)x).b);
}
int main()
{
 Box arr[]={ {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
 int n=sizeof(arr)/sizeof(arr[0]);
 Box rot[n*3];
 int i=0;
 for(int index=0;index<n;index++)
 {
  rot[i]=arr[index];
  i++;
  
  rot[i].h=arr[index].b;
  rot[i].l=max(arr[index].h,arr[index].l);
  rot[i].b=min(arr[index].h,arr[index].l);
  i++;
  
  rot[i].h=arr[index].l;
  rot[i].l=max(arr[index].h,arr[index].b);
  rot[i].b=min(arr[index].h,arr[index].b);
  i++;
 }
 qsort(rot,n*3,sizeof(rot[0]),compare);
 
 int lis[n*3];
 for(int i=0;i<n*3;i++)
 {
  lis[i]=rot[i].h;
 }
 for(int i=1;i<n*3;i++)
 {
  for(int j=0;j<i;j++)
  {
   if(rot[i].l<rot[j].l && rot[i].b<rot[j].b && lis[i]<rot[i].h+lis[j])
   {
    lis[i]=rot[i].h+lis[j];
   }
  }
 }
 int mx=-1;
 for(int i=0;i<n*3;i++)
 {
  mx=max(lis[i],mx);
 }
 cout<<mx<<endl;
 return 0;
}
