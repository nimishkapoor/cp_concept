#include<bits/stdc++.h>
using namespace  std;
typedef long long int ll;
int main()
{
 ll t;
 cin>>t;
 while(t--)
 {
  string s;
  cin>>s;
  s='x'+s;
  ll arr[s.size()]={0LL};
  arr[0]=0LL;
  ll ans=0LL;
  
  for(ll i=1LL;i<s.size();i++)
  {
   if(s[i]=='c'||s[i]=='h'||s[i]=='e'||s[i]=='f')
   {
     arr[i]++;
     if(s[i]!=s[i+1] &&(s[i+1]=='c'||s[i+1]=='h'||s[i+1]=='e'||s[i+1]=='f'))
     {
      arr[i]++;
    
      if(s[i]!=s[i+2] && s[i+1]!=s[i+2] && (s[i+2]=='c'||s[i+2]=='h'||s[i+2]=='e'||s[i+2]=='f'))
      {
       arr[i]++;
      
       if(s[i]!=s[i+3] && s[i+3]!=s[i+2] && s[i+1]!=s[i+3]&&(s[i+3]=='c'||s[i+3]=='h'||s[i+3]=='e'||s[i+3]=='f'))
       {
        arr[i]++;
       }
      }
     }
   }
   if(arr[i]==4)
   {
    ans++;
   }
  }
/*  for(int i=1;i<s.size();i++)
  {
   cout<<arr[i]<<" ";
  }
  cout<<endl;*/
  if(ans>0)
  {
   cout<<"lovely "<<ans<<endl;
  }
  else
  {
   cout<<"normal"<<endl;
  }
 }
 return 0;
}
