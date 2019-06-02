#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=0;
	string a,b;
	cin>>n;
	cin>>a;
	cin>>b;
	a=' '+a;
	b=' '+b;
	for(int i=1;i<=n/2;i++)
	{
		if(a[i]==b[i])
		{
			continue;
		}
		if(a[i]==b[n-i+1])
		{
			swap(b[i],b[n-i+1]);
		}
		else if(b[i]==a[n-i+1])
		{
			swap(a[i],a[n-i+1]);
		}
		else if(b[i]==b[n-i+1])
		{
			swap(a[i],b[n-i+1]);
		}
	}
	//cout<<a<<endl;
	//cout<<b<<endl;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=b[i])
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
	
