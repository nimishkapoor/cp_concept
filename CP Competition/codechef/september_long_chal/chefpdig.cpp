#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  string n;
  cin>>n;
  vector<long long int> a;
  int set[26]={0};
  for(int i=0;i<n.size();i++)
  {if(set[n[i]-48]!=2){
   a.insert(a.begin(),n[i]-48);
   set[n[i]-48]++;
  }}
  
  
  int b[26]={0};
  for(int i=0;i<a.size();i++)
  {
   if(a[i]>=6)
   {
    
    for(int j=0;j<a.size();j++)
    {if(b[((a[i]*10)+a[j])-65]!=1){
     if((((a[i]*10)+a[j])<=90) && i!=j && (((a[i]*10)+a[j])>=65))
     {
      //cout<<(char)((a[i]*10)+a[j]);
      b[((a[i]*10)+a[j])-65]=1;
     }}
    }
   };
  }
  for(int i=0;i<26;i++)
  {
   if(b[i]==1)
   {
    cout<<char(i+65);
   }
  }
  cout<<endl;
 }
 return 0;
}

