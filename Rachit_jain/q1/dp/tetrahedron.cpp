#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int ans=0;
const int MOD=1000000007;
int dp[2][10000007];
int main()
{
	ll n;
	cin>>n;
	dp[1][0]=1;
	dp[0][0]=0;
	for(int i=1;i<10000007;i++)
	{
		dp[1][i]=(3LL*dp[0][i-1])%MOD;
		dp[0][i]=(2LL*dp[0][i-1]+dp[1][i-1])%MOD;
	}
	cout<<dp[1][n]<<endl;
	return 0;
}
