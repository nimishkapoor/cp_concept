#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,count=1,ans=1;
		cin>>n;
		ll a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		
		}
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		for(int i=1;i<n;i++)
		{
			if(a[i]>=a[i-1])
			{
				count++;
				ans+=count;
			}
			else
			{
				count=1;
				ans+=count;				
	        }		
		}
		cout<<ans<<endl;
	}
	return 0;
}
