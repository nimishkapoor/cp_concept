#include<bits/stdc++.h>
using namespace std;
int visited[100005];
vector<int> v[100005];
vector<int> ans;
void dfs(int i)
{
	if(visited[i]==1)
	{
		return;
	}
	visited[i]=1;
	ans.push_back(i);
	for(unsigned int j=0;j<v[i].size();j++)
	{
		dfs(v[i][j]);
	}
}
int main()
{
	int n,q,x;
	cin>>n>>q;
	memset(visited,0,sizeof(visited));
	for(int i=2;i<=n;i++)
	{
		cin>>x;
		v[x].push_back(i);
	}
/*	for(int i=1;i<n;i++)
	{
		cout<<i<<" ";
		for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}*/
	dfs(1);
	int u,k;
	for(int i=0;i<q;i++)
	{
		cin>>u>>k;
		auto it=find(ans.begin(),ans.end(),u);
		if(it!=ans.end())
		{
			it+=k-1;
			if(*it != 0)
			{
				cout<<*it<<endl;
			}
			else
			{
				cout<<-1<<endl;
			}
		}
		else
		{
			cout<<-1<<endl;
		}
	}
	return 0;
}
