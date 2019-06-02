#include<bits/stdc++.h>
using namespace std;
struct Box
{
 int h;
 int b;
 int l;
};
int compare(const void *x,const void *y)
{
 return ((*(Box *)y).l*(*(Box *)y).b)-((*(Box *)x).l*(*(Box *)x).b);
}
int main()
{
 Box arr[]={ {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
 int n=sizeof(arr)/sizeof(arr[0]);
 Box rot[n*3];
 int index=0;
 for(int i=0;i<n;i++)
 {
  rot[index]=arr[i];
  index++;
  rot[index].h=arr[i].l;
  rot[index].l=max(arr[i].h,arr[i].b);
  rot[index].b=min(arr[i].h,arr[i].b);
  index++;
  rot[index].h=arr[i].b;
  rot[index].l=max(arr[i].h,arr[i].l);
  rot[index].b=min(arr[i].h,arr[i].l);
  index++;
 }
 qsort(rot,n*3,sizeof(rot[0]),compare);
  for (int i = 0; i < n*3; i++ )
      printf("%d x %d x %d\n", rot[i].h, rot[i].b, rot[i].l);
  
 int lis[n*3];
 for(int i=0;i<n*3;i++)
 {
  lis[i]=rot[i].h;
 }
 for(int i=0;i<n*3;i++)
 {
  cout<<lis[i]<<" ";
 }
 cout<<endl;
 
 for(int i=1;i<n*3;i++)
 {
  for(int j=0;j<i;j++)
  {
   if(rot[i].l < rot[j].l && rot[i].b < rot[j].b && lis[i]<lis[j]+rot[i].h)
   {
    lis[i]=lis[j]+rot[i].h;
   }
  }
 }
 for(int i=0;i<n*3;i++)
 {
  cout<<lis[i]<<" ";
 }
 cout<<endl;
 int mx=0;
 for(int i=0;i<n*3;i++)
 {
  mx=max(mx,lis[i]);
 }
 cout<<mx<<endl;
 return 0;
} 
