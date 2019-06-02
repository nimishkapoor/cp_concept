#include<bits/stdc++.h>
using namespace std;
int arr[10];
void swap(int* a,int* b)
{
 int temp=*a;
 *a=*b;
 *b=temp;
}
void heapify(int i)
{
 while(i!=1)
 {
  if(arr[i]>arr[(i)/2])
  {
   swap(arr[i],arr[(i)/2]);
   i=(i)/2;
  }
  else
  {
   break;
  }
 }
}
int main()
{
 int n,x;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>arr[i];
  
  heapify(i);
 }
 for(int i=1;i<=n;i++)
 {
  cout<<arr[i]<<" ";
 }
 cout<<endl;
 return 0;
}
