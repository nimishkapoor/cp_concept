#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		for(auto &it: s) {
			it -= 'a';
		}
		int n=s.length();
		int y,y0=0,x,ans=INT_MAX;
		int b[n][26],f[n][26];
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		for(int i=1;i<n;i++)
		{
			int fr=i,bk=n-i-1;
			for(int j=0;j<26;j++)
			{
					b[fr][j]=b[fr-1][j] + (s[fr-1] < j);
					f[bk][j]=f[bk+1][j] + (s[bk+1] > j); 
			}
			y0+=b[i][s[i]];	
		}
		ans=y0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<26;j++)
			{
				x=abs(s[i]-j);
				y=y0-(b[i][s[i]]+f[i][s[i]])+(b[i][j]+f[i][j]);
				ans=min(ans,x+y);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
