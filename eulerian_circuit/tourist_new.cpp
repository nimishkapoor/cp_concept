	#include<bits/stdc++.h>
	using namespace std;
	#define N 20000
	int visited[N][N];
	int f[N];
	vector <int> v[N];
	int allvisited(int x)
	{
		vector<int>::iterator it;
		for(it=v[x].begin();it!=v[x].end();it++)
		{
			if(visited[x][*it]==0)
			{
				return 0;
			}
		}
		return 1;
	}
	int main()
	{
		int n,e,x,y,current,c=0;
		cin>>n>>e;
		int cnt=0;
		memset(visited,0,sizeof(int)*N*N);
		for(int i=0;i<e;i++)
		{
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(int i=1;i<=n;i++)
		{
			if(v[i].size()==0 || v[i].size()&1)
			{cout<<i<<" "<<v[i].size()<<endl;
				cout<<"NO"<<endl;
				return 0;
			}
		}
		stack <int> s;
		s.push(1);
		while(!s.empty())
		{
			current=s.top();
			//cout<<"current="<<current<<endl;
			if(allvisited(current)==1)
			{//cout<<"test1"<<endl;
				f[c++]=s.top();
				cnt++;
				s.pop();
				continue;
			}
			vector<int>::iterator it;
			for(it=v[current].begin();it!=v[current].end();it++)
			{//cout<<"it="<<*it<<endl;
				if(visited[current][*it]==0)
				{//cout<<"vis "<<visited[current][*it]<<endl;
					visited[*it][current]=1;
					visited[current][*it]=1;
					s.push(*it);
					break;
				}
			}
		}
		cout<<"YES"<<endl;
		int j;
		for(j=cnt-1;j>0;j--)
		{
			cout<<f[j]<<" "<<f[j-1]<<endl;
		}
		return 0;
	}
