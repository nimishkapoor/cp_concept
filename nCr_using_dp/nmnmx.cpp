#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD=1e9+6;
const ll mod=1e9+7;
const ll N=1e8+7;ll ncr[6001][6001];
ll fact[N],inv[N];

long long power(long long x, long long y,long long p)
{
	long long res = 1; 
	x = x % p; 

	while (y > 0)
	{
		if (y & 1)
		res = (res*x) % p;
		y = y>>1;
		x = (x*x) % p;
	}
	return res;
}
int main()
{
	for(ll i=0;i<=6000;i++)
	{
		for(ll k=0;k<=6000;k++)
		{
			if(k<=i)
			{
				if((k==0)||(k==i))
				ncr[i][k]=1;
				else
				ncr[i][k]=(ncr[i-1][k-1]+ncr[i-1][k])%MOD;
			}
		}
	}


	ll t;
	cin>>t;
	while(t--)
	{
		ll n,x,k,ans=1;
		cin>>n>>k;
		vector<ll> v;
		for(ll i=0;i<n;i++)
		{
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		for(ll i=0;i<n;i++)
		{
			ans=((ans%mod)*(power(v[i],(ncr[n-1][k-1]-ncr[n-i-1][k-1]+MOD-ncr[i][k-1]+MOD)%MOD,mod)));
			ans%=mod;

		}
		cout<<ans%mod<<endl;
}
return 0;
}
