#include<bits/stdc++.h>
using namespace std;
int sol(vector <int> a,int i,int k)
{
	if(i<0)
	{
		return 0;
	}	
	if(k==0)
	{
		return 1;
	}
	else if(a[i]>k)
	{
		return sol(a,i-1,k);
	}
	else 
	{
		return sol(a,i-1,k)+sol(a,i-1,k-a[i]);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,x;
		cin>>n>>k;
		vector<int> a;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		sort(a.begin(),a.end());
	    cout<<sol(a,n-1,k)<<endl;			
	}
	return 0;
}

