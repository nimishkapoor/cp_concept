#include<bits/stdc++.h>
using namespace std;
int main()
{
	int64_t t;
	cin>>t;
	while(t--)
	{
		int64_t n,h,x,y;
		cin>>n>>h;
		int64_t empty[n];
		for(int i=0;i<n;i++)
		{
			empty[i]=0;
		}
		for(int i=0;i<n;i++)
		{
			cin>>x>>y;
			empty[x]++;
			empty[y+1]--;
		}
	    for(int i=1;i<n;i++)
	    {
			empty[i]+=empty[i-1];
		}
		for(int i=0;i<n;i++)
		{
			empty[i]=n-empty[i];
		}
		for(int i=1;i<n;i++)
		{
			empty[i]+=empty[i-1];
		}
		int64_t mn=empty[h-1];
		for(int i=h;i<n;i++)
		{
			if(mn>(empty[i]-empty[i-h]))
			{
				mn=empty[i]-empty[i-h];
			}
		}
		cout<<mn<<endl;
	}
	return 0;
}
	
