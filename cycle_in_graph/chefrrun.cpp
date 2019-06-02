#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
class Graph
{
	ll V;
	list<ll> *adj;
	void DFS(ll u,bool visited[],bool isCycle[],stack<ll> s);
public:
	Graph(ll V);
	void addEdge(ll u,ll v);
	ll Cycle();
};
Graph::Graph(ll V)
{
	this->V=V;	
	adj=new list<ll>[V];
}
void Graph::addEdge(ll u,ll v)
{
	adj[u].push_back(v);
}
void Graph::DFS(ll u,bool visited[],bool isCycle[],stack<ll>s)
{
	if(visited[u]==true)
	{	
		if(isCycle[u]==false)
		{
			ll x;
			do
			{
				if(s.empty())
				{
					break;
				}
				x=s.top();
			    s.pop();
				isCycle[x]=true;
				if(x==u)
				{
					break;
				}
			}while(true);
		}
		return;
	}
	s.push(u);
	visited[u]=true;
	list<ll>::iterator it;
	for(it=adj[u].begin();it!=adj[u].end();it++)
	{   
			DFS(*it,visited,isCycle,s);
    }
}
ll Graph::Cycle()
{
	bool visited[V]={0};
	bool isCycle[V]={0};
	stack<ll> s;
	ll count=0;
	for(ll i=0;i<V;i++)
	{
		if(visited[i]==false)
		{
			DFS(i,visited,isCycle,s);
		}
	}
	for(ll i=0;i<V;i++)
	{
		if(isCycle[i]==true)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Graph g(n);
		for(ll i=0;i<n;i++)
		{
			g.addEdge(i,(i+a[i]+1)%n);
		}
		cout<<g.Cycle()<<endl;
	}
	return 0;
}
