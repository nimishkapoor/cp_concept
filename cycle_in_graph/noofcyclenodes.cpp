#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n;
		int a[n],in[n]={0};
		for(int i=0;i<n;i++)
		{
			cin>>x;
			a[i]=(x+1+i)%n;
			in[a[i]]++;
		}
		vector<int> v;
		for(int i=0;i<n;i++)
		{
			if(in[i]==0)
			{
				v.push_back(i);
			}
		}
		for(int i=0;i<v.size();i++)
		{
			in[a[v[i]]]--;
			if(in[a[v[i]]]==0)
			{
				v.push_back(a[v[i]]);
			}
		}
		cout<<n-v.size()<<endl;
	}
	return 0;
}
	
