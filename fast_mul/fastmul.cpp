#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000000
int power(int x, ll y)
{
    int res = 1;      // Initialize result
 
    x = x % MOD;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % MOD;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % MOD;  
    }
    return res;
}
int mul(ll a,ll b)
{
 if(b==1)
 {
  return a;
 }	
 if(b%2==0)
 {
  return 2*(mul(a,b/2)%MOD);
 }
 else
 {
  return (a+(2*(mul(a,b/2))%MOD))%MOD;
 }
}
int main()
{
 ll a,b;
 cin>>a>>b;
 cout<<mul(a,b)<<endl;
 return 0;
}
