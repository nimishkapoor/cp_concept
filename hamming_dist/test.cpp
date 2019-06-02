#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 1e9+7;
ll hamweight(ll n)
{
	ll count=0;
	while(n)
	{
		count++;
		n&=n-1;
	}
	return count;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,x,k,ans=1,c,f;
		cin>>n>>k;
		vector<ll> v;
		for(ll i=0;i<n;i++)
		{
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		for(ll i=1;i<=pow(2,n);i++)
		{
			if(hamweight(i)==k)
			{
				c=k-2;
				f=0;
				for(ll j=0;j<n;j++)
				{
					if(i&(1<<j))
					{
						if(f==0)
						{
							f=1;
							continue;
						}
						//cout<<v[j]<<endl;
						ans=((ans%MOD)*v[j]%MOD)%MOD;
						c--;
						if(c==0)
						{
							break;
						}
					}
				}
			}
		}
		cout<<ans%MOD<<endl;
		
	}
	return 0;
}
