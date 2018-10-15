#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
 int t,n;
 double c,d,s,mx;
 cin>>t;
 while(t--)
 {
  mx=0;
  cin>>n;
  double a[n];
  for(int i=0;i<n;i++)
  {
   cin>>a[i];
   mx=max(a[i],mx);
  }
  cin>>c>>d>>s;
  cout<< setprecision (9) << fixed;
  cout<<mx*(c-1)<<endl;
 }
 return 0;
}
