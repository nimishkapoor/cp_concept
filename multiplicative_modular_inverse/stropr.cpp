#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long a[100100];
#define MOD 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll inv[100005];
	inv[1]=1;
	inv[0]=1;
	for(int i = 2; i <= 100005; i++)
	inv[i] = inv[MOD % i]*(MOD-MOD / i) % MOD;
	int t;
	cin>>t;
	while(t--)
	{
		ll n,x,m,ans=0,mul,l;
		cin>>n>>x>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			a[i]%=MOD;
		}
		mul=1;
		l=1;
		for(int i=x;i>0;i--)
		{
			ans=((a[i]*mul)%MOD+ans)%MOD;
			mul=((mul*((m+l-1)%MOD))%MOD)/(l%MOD);
			l++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
