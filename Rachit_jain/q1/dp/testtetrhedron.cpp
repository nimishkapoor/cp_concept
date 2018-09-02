#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MOD=1000000007;
int dp[2][10000007];
int vis[2][10000007];
int rec(int s, ll n)
{
	if(n==0)
	{
		if(s==1)
		{
			return 1;
		}
		return 0;
	}
	if(vis[s][n]==1)
	{
		return dp[s][n];
	}
	vis[s][n]=1;
	if(s==1)
	{
		return dp[s][n]=(3LL*rec(0,n-1))%MOD;
	}
	else
	{
		return dp[s][n]=(2LL*rec(0,n-1))+rec(1,n-1)%MOD;
	}
}
int main()
{
	ll n;
	cin>>n;
	memset(vis,0,sizeof(vis));
	cout<<rec(1,n)<<endl;
	return 0;
}

