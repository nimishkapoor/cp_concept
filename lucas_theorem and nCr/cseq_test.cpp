#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD=1e6+3;
const ll N=1e6+7;
ll fact[N],inv[N];
ll nCr(ll n, ll r)
{
	if(n<r)
	{
		return 0;
	}
	if(n==r||r==0)
	{
		return 1;
	}
	return (fact[n] * (inv[r]*inv[n-r])%MOD) %MOD;
}
int main()
{
	fact[0]=fact[1]=inv[1]=1;
	for(int i=2;i<MOD;i++)
	{
		inv[i]=(MOD-ll(MOD/i) *inv[MOD%i])%MOD;
	}
	for(int i=2;i<MOD;i++)
	{
		fact[i]=(i*fact[i-1])%MOD;
		inv[i]=(inv[i]*inv[i-1])%MOD;
	}
	int t;
	cin>>t;
	while(t--)
	{
		ll n,l,r,ans=1,p;
		cin>>n>>l>>r;
		p=n+r-l+1;
		while(n||p)
		{
			ans=(ans*nCr(p%MOD,n%MOD))%MOD;
			n/=MOD;
			p/=MOD;
		}
		cout<<(ans-1+MOD)%MOD<<endl;
	}
	return 0;
}
