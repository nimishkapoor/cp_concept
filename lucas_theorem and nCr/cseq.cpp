#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll N =1e6 + 1;
const ll MOD = 1e6+3;
ll fact[N],infact[N];
ll nCr(ll n, ll r)
{
	if(n<r)
	{
		return 0;
	}
	if(r==0 || r==n)
	{
		return 1;
	}
	return (fact[n] * (infact[r] * infact[n-r])%MOD)%MOD;
}
ll expm(ll a,ll n)
{
	ll ans=1;
	while(n)
	{
		if(n&1)ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		n=n/2;
	}
	return ans;
}
	
int main()
{
	fact[0]=fact[1]=infact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=(i*fact[i-1])%MOD;
		infact[i]=(expm(i,MOD-2)*infact[i-1])%MOD;
	}
	int t;
	cin>>t;
	while(t--)
	{
		ll n,r,l,ans=1;
		cin>>n>>l>>r;
		ll p=n+r-l+1; 
		while(n || p)
		{
			ans=(ans*nCr(p%MOD,n%MOD))%MOD;
			p=p/MOD;
			n=n/MOD;
		}
		cout<<(ans-1+MOD)%MOD<<endl;
	}
	return 0;
}
