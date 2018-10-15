#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 cin.get();
 string s;
 getline(cin,s);

 int vw=0,vt=0,i;
 for(i=0;i<n;i++)
 {
  vw=0;
  while(s[i]!=' ' && i<n)
  {
   if(s[i]>='A' && s[i]<='Z')
   {
    vw++;
   }
   i++;
  }
  if(vw>vt)
  {
   vt=vw;
  }
 }
 cout<<vt<<endl;
 return 0;
}
 
