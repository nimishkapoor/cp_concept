#include<bits/stdc++.h>
using namespace std;
int main()
{
 string a,b;
 cin>>a>>b;
 int lsp[b.length()]={0};
 int i=1,j=0;
 while(i<b.length())
 {
  if(b[i]==b[j])
  {
   lsp[i]=j+1;
   i++;
   j++;
  }
  else
  {
   if(j!=0)
   {
    j=lsp[j-1];
   }
   else
   {
    i++;
   }
  }
 }
 i=0;j=0;
 while(i<a.length() && j<b.length())
 {
  if(a[i]==b[j])
  {
   i++;
   j++;
  }
  else
  {
   if(j!=0)
   {
    j=lsp[j-1];
   }
   else
   {
    i++;
   }
  }
 }
 if(j==b.length())
 {
  cout<<"true"<<endl;
 }
 else
 {
  cout<<"false"<<endl;
 }
 return 0;
}
   
