	#include<bits/stdc++.h>
	using namespace std;
	int main()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n,m,flag,f=0;
			cin>>n>>m;
			string s[n];
			int v[n]={0},h[m]={0};
			for(int i=0;i<n;i++)
			{
				cin>>s[i];
			}
			for(int i=0;i<n;i++)
			{
				flag=0;
				for(int j=0;j<m;j++)
				{
					if(s[i][j]=='1')
					{
						h[j]=1;
						flag=1;
						f=1;
					}
				}
				if(flag==1)
				{
					v[i]=1;
				}
			}
			if(f==0)
			{
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<m;j++)
					{
						cout<<-1<<" ";
					}
					cout<<endl;
				}
				//cout<<-1<<endl;
			}
			else{
			for(int i=0;i<n;i++)
			{
				if (v[i]==1)
				{
					for(int j=0;j<m;j++)
					{
						if(s[i][j]=='1')
						{
							cout<<0<<" ";
						}
						else
						{
							cout<<1<<" ";
						}
					}
				}
				else
				{
					for(int j=0;j<m;j++)
					{
						if(h[j]==1)
						{
							cout<<1<<" ";
						}
						else
						{
							cout<<2<<" ";
						}
					}
				}
				cout<<endl;
			}}}
			/*for(int i=0;i<m;i++)
			{
				cout<<h[i]<<" ";
			}
			cout<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<v[i]<<" ";
			}
			cout<<endl;*/
		return 0;
	}
