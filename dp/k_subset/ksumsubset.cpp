#include<bits/stdc++.h>
using namespace std;
int sol(vector <int> &a,vector< vector <int> > &dp,int i,int k)
{
	if(i<0)
	{
		return 0;
	}	
	if(dp[i][k]!=0)
	{
		return  dp[i][k];
	}
	if(k==0)
	{
		return 1;
	}
	else if(a[i]>k)
	{
		return dp[i][k]=sol(a,dp,i-1,k);
	}
	else 
	{
		return dp[i][k]=sol(a,dp,i-1,k)+sol(a,dp,i-1,k-a[i]);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,x;
		cin>>n>>k;
		vector<int> a;
		vector<vector <int> > dp;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		sort(a.begin(),a.end());
	    for(int i=0;i<=n+1;i++)
	    {
			vector<int> row;
			for(int j=0;j<=k;j++)
			{
				row.push_back(0);
			}
			dp.push_back(row);
		}
	    cout<<sol(a,dp,n-1,k)<<endl;		
	}
	return 0;
}
