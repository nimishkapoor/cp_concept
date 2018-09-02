#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int mask;
  cin>>mask;
  //cout<<floor(log2(n))<<" "<<ceil(log2(n))<<endl;
  cout<<mask<<" "<<pow(2,floor(log2(mask)))<<" "<<pow(2,floor(log2(mask)))-(pow(2,ceil(log2(mask)))-mask)<<endl;
 }
 return 0;
} 

