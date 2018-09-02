#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int s,int m,int e)
{
 int i,j,k;
 int n1=m-s+1;
 int n2=e-m;
 int x[n1];
 int y[n2];
 for(i=0;i<n1;i++)
 {
  x[i]=a[i+s];
 }
 for(i=0;i<n2;i++)
 {
  y[i]=a[m+1+i];
 }
 i=0;j=0;k=s;
 while(i<n1 && j<n2)
 {
  if(x[i]<=y[j])
  {
   a[k]=x[i];
   i++;
  }
  else
  {
   a[k]=y[j];
   j++;
  }
  k++;
 }
 while(i<n1)
 {
  a[k]=x[i];
  i++;k++;
 }
 while(j<n2)
 {
  a[k]=y[j];
  j++;k++;
 }
} 
void mergesort(int a[],int s,int e)
{
 
 if(s>=e)
 {
  return;
 }
 int m=s+(e-s)/2;
 mergesort(a,s,m);
 mergesort(a,m+1,e);
 merge(a,s,m,e);

}

int main()
{

 int arr[8]={19,54,28,47,48,33,14,16};
 mergesort(arr,0,7);
 for(int i=0;i<7;i++)
 {
  cout<<arr[i]<<" ";
 }
 cout<<endl;
 return 0;
}
