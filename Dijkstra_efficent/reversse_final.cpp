#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a,b;
	cin>>n>>m;
	vector<pair<int ,int> > graph[n+1];
	vector<int> dis(n+1,INT_MAX);
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		graph[a].push_back(make_pair(b,0));
		graph[b].push_back(make_pair(a,1));
	}
	priority_queue<pair<int,int> ,vector<pair<int,int> >, greater<pair<int,int> > > pq;
	pq.push(make_pair(0,1));
	dis[1]=0;
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		vector<pair<int,int> > ::iterator  it;
		for(it=graph[u].begin();it!=graph[u].end();it++)
		{
			int v=(*it).first;
			int weight=(*it).second;
			if(dis[v]>dis[u]+weight)
			{
				dis[v]=dis[u]+weight;
				pq.push(make_pair(dis[v],v));
			}
		}
	}
	if(dis[n]!=INT_MAX)
	{
		cout<<dis[n]<<endl;
	}
	else
	{
		cout<<-1<<endl;
	} 
	return 0;
}
