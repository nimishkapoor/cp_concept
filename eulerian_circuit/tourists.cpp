#include<bits/stdc++.h>
using namespace std;
#define N 200005
vector<pair <int,int> > v[N];
pair<int,int> out[N];
int cnt=0;
int visited[N]={0};
void dfs(int p)
{
	visited[p]=1;
	for(int i=0;i<v[p].size();i++)
	{
		int q=v[p][i].first;
		int idx=v[p][i].second;
		if(out[idx].first==0)
		{
			out[idx]=make_pair(p,q);
			cnt++;
		}
		if(visited[q]==0)
		{
			dfs(q);
		}
	}
}
int main()
{
	int n,e,x,y;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		v[x].push_back(make_pair(y,i));
		v[y].push_back(make_pair(x,i));
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i].size()==0 || v[i].size()&1)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	dfs(1);
	if(cnt!=e)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=0;i<e;i++)
	{
		cout<<out[i].first<<" "<<out[i].second<<endl;
	}
	return 0;
}
