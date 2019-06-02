#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  long long int p[2][26],sum=0;
  for(int i=0;i<26;i++)
  {
   cin>>p[0][i];
   p[1][i]=0;
  }  
  char s[100000];
  cin>>s;
  for(int  i=0;i<strlen(s);i++)
  {if(p[1][s[i]-97]==0)
   {
    p[1][s[i]-97]=1;
   }
  }
  for(int i=0;i<26;i++)
  {
   if(p[1][i]==0)
   {
    sum+=p[0][i];
   }
  }
  cout<<sum<<endl;
 }
 return 0;
}
