    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    int main()
    {
    	int t;
    	cin>>t;
    	while(t--)
    	{
    		ll n,k1,l,sum=0;
    		cin>>n>>k1;
    		ll intensity;
    		ll a[n];
    		for(int i=0;i<n;i++)
    		{
    			cin>>a[i];
    			sum+=a[i];
    		}
    		if(sum%k1!=0)
    		{
    			cout<<"no"<<endl;
    			continue;
    		}
    		if(n<k1)
    		{
    			cout<<"no"<<endl;
    			continue;			
    		}
    		if(sum==0)
    		{
    			cout<<"yes"<<endl;
    			continue;			
    		}
    		intensity=sum/k1;
    		ll subset=1<<n;
    		ll dp[k1+1][subset+1];
    		memset(dp,0,sizeof(ll)*((k1+1)*(subset+1)));
    		dp[0][0]=1;
    		for(int i=0;i<k1;i++)
    		{
    		for(int i1=0;i1<k1+1;i1++)
    		{
    			for(int j1=0;j1<subset;j1++)
    			{
    				cout<<dp[i1][j1]<<" ";
    			}
    			cout<<endl;
    		}				
    		cout<<endl;
    			for(int j=0;j<subset;j++)
    			{
    				if(dp[i][j]!=1)
    				{
    					continue;
    				}
    				sum=0;
    				for(int k=0;k<n;k++)
    				{
    					if(j & (1ll<<k))
    					{
    						sum+=a[k];
    							
    					}
    				}
    				sum-=(intensity*i);
    				for(int k=0;k<n;k++)			
    				{
    					if(j & (1ll<<k))
    					{
    						continue;
    					}
    					l=(j | (1ll<<k));
    					if(a[k]+sum==intensity)
    					{
    						dp[i+1][l]=1;
    					}
    					else if(a[k]+sum<intensity)
    					{
    						dp[i][l]=1;
    					}
    				}
    			}
    		}
    		for(int i=0;i<k1+1;i++)
    		{
    			for(int j=0;j<subset;j++)
    			{
    				cout<<dp[i][j]<<" ";
    			}
    			cout<<endl;
    		}
    		if(dp[k1][subset-1]==1)
    		{
    			cout<<"yes"<<endl;
    		}
    		else
    		{
    			cout<<"no"<<endl;
    		}
    	}
    	return 0;
    }
     
