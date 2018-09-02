#include<bits/stdc++.h>
using namespace std;
void bucksort(float arr[],int n)
{
 vector<float> b[n];
 for(int i=0;i<n;i++)
 {
  int bi=n*arr[i];
  b[bi].push_back(arr[i]);
 }
 for(int i=0;i<n;i++)
 sort(b[i].begin(),b[i].end());
 int index=0;
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<b[i].size();j++)
  {
   arr[index++]=b[i][j];
  }
 }
}
int main()
{
 int n;
 cin>>n;
 float a[n];
 for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }
 bucksort(a,n);
 for(int i=0;i<n;i++)
 {
  cout<<a[i]<<endl;
 }
 return 0;
}
