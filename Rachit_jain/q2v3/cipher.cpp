#include<bits/stdc++.h>
using namespace std;
set<string> pool;
int len,lmt; 
map<string, int> cnt;
int dp[400];
string f(string x)
{
	sort(x.begin(),x.end());
	return x;
}
int go(int i,string s)
{
	if(dp[i]!=-1)
	{
		return dp[i];
	}
	int ans=0;
	len=s.length();
	if(i==len)
	{
		return 1;
	}
	string cur="";
	for(int j=i;j<lmt+i+1;j++)
	{
		cur+=s[j];
		sort(cur.begin(),cur.end());
		if(cnt[cur]>0)
		{
			ans+=cnt[cur]*go(j+1,s);
		}
	}
	return dp[i]=ans;
}
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		memset(dp,-1,sizeof(dp));
		cout<<"Case #"<<i<<": ";
		int v,s;
		string x;
		cin>>v>>s;
		cnt.clear();
		pool.clear();
		lmt=0;
		for(int i=0;i<v;i++)
		{
			cin>>x;
			lmt=max(len,(int)x.size());
			if(pool.find(x)==pool.end())
			{
				pool.insert(x);
				cnt[f(x)]++;
			}
		}
		for(int i=0;i<s;i++)
		{
			cin>>x;
			cout<<go(0,x)<<" ";
		}
		cout<<endl;
	}
	return 0;
}
