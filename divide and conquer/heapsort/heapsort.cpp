#include<bits/stdc++.h>
using namespace std;
int arr[10];
void swap(int* a,int* b)
{
 int temp=*a;
 *a=*b;
 *b=temp;
}
void heapify(int i,int n)
{
 int largest=i;
 int l=2*i;
 int r=2*i+1;
 if(arr[largest]<arr[l] && l <=  n)
 {
  largest=l;
 }
 if(arr[largest]<arr[r] && r <=  n)
 {
  largest=r;
 }
 if(largest!=i)
 {
  swap(arr[largest],arr[i]);
  heapify(largest,n);
 }
}
int main()
{
 int n,x;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>arr[i];
 }
 for(int i=n/2;i>0;i--)
 {
  heapify(i,n);
 }	
 for(int i=n;i>0;i--)
 {
  swap(arr[i],arr[1]);
  heapify(1,i-1);
 }
 for(int i=1;i<=n;i++)
 {
  cout<<arr[i]<<" ";
 }
 cout<<endl;
 return 0;
}
