#include<bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  float n,ans=0;
  cin>>n;
  for (int i=1;i<=n;i++)
  {
   ans+=n/i;
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(1);
  cout<<ans<<endl;
 }
 return 0;
}
