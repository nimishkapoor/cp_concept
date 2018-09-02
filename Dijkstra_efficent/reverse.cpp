#include<bits/stdc++.h>
using namespace std;
#define inf 100000000
int visited[100005];
int w[100005];
vector<pair<int, int> > v[100005];
int mn(int x)
{                                                                       
	int m=inf,i;
	for(int it=1;it<=x;it++)
	{	
		if(visited[it]==0 && w[it]<=m)
		{
			m=w[it];
			i=it;
		}
	}
	return i;
}
void relax(int x)
{                     
	vector< pair<int, int> >::iterator it;
	for(it=v[x].begin();it!=v[x].end();it++)
	{									
		if((w[x]+(*it).second)<w[(*it).first])
		{
			w[(*it).first]=(w[x]+(*it).second);
		}
	}
}
void dfs(int n)
{
	int j=1;
	visited[1]=1;
	w[1]=0;
	relax(j);
	for(int i=1;i<n;i++)
	{		
		j=mn(n);
        visited[j]=1;
        relax(j);
	}
}
int main()
{
	int n,m,a,b;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		v[a].push_back(make_pair(b,0));
		v[b].push_back(make_pair(a,1));
	}
	memset(visited,0,sizeof(int)*(n+100));
	for(int i=0;i<n+2;i++)
	{
		w[i]=inf;
	}
	dfs(n);
    if(w[n]!=inf)
	{
		cout<<w[n]<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
	return 0;
}
