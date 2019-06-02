#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
			ll n,x, prev;
			cin>>n;
			int a[n],b[n]={0};
			for(int i=0;i<n;i++)
			{
				cin>>a[i];
			}
			x=a[n-1];
			if(x>0)
			{
				prev=1;
			}
			else
			{
				prev=-1;
			}
			b[n-1]=1;
			for(int i=n-2;i>=0;i--)
			{
				x=a[i];
				if(x>0 && prev ==-1)
				{
					b[i]=b[i+1]+1;
			        prev=1;
				}
				else if(x< 0 && prev==1)
				{
					b[i]=b[i+1]+1;
					prev=-1;
				}
		        else
		        {
					b[i]=1;
					if(x>0)
					{
						prev=1;
					}
					else
					{
						prev=-1;
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				cout<<b[i]<<" ";
			}
			cout<<endl;
			
	}
	return 0;	
}
