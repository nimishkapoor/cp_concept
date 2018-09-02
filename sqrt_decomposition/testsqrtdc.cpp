	#include<bits/stdc++.h>
	using namespace std;
	typedef long long int ll;

	#define watch(x) cout << (#x) << " is " << (x) << endl
	#define mod(x, m) ((((x) % (m)) + (m)) % (m))
	#define max3(a, b, c) max(a, max(b, c))
	#define min3(a, b, c) min(a, min(b, c))

	#define gcd __gcd
	#define nof1 __builtin_popcountll

	typedef long long ll;
	typedef unsigned long long ull;

	typedef pair<int, int> ii;
	typedef pair<int, ii> iii;
	typedef vector<int> vi;
	typedef vector<ii> vii;
	typedef vector<iii> viii;
	typedef vector<long long int> vl;
		
	const double pi = 2 * acos(0.0);
	const int inf = 0x3f3f3f3f;
	const double infd = 1.0/0.0;

	#define pb push_back
	#define mp make_pair
	#define fr first
	#define sc second
	#define clr(a) memset(a, 0, sizeof(a))
	#define all(v) v.begin(), v.end()
	#define alla(a,n) a, a+n
	#define endl "\n"

	long long power(long long x, long long y,long long MOD)
	{
		long long res = 1; 
		x = x % MOD; 

		while (y > 0)
		{
			if (y & 1)
			res = (res*x) % MOD;
			y = y>>1;
			x = (x*x) % MOD;
		}
		return res;
	}
	long long mul(long long a,long long b,long long MOD)
	{
	 if(b==1)
	 {
	  return a;
	 }	
	 if(b%2==0)
	 {
	  return 2*(mul(a,b/2,MOD)%MOD);
	 }
	 else
	 {
	  return (a+(2*(mul(a,b/2,MOD))%MOD))%MOD;
	 }
	}

	/*ll ncr[6001][6001];
	void nCr(long long MOD)
	{
		for(ll i=0;i<=6000;i++)
		{
			for(ll k=0;k<=6000;k++)
			{
				if(k<=i)
				{
					if((k==0)||(k==i))
					ncr[i][k]=1;
					else
					ncr[i][k]=(ncr[i-1][k-1]+ncr[i-1][k])%MOD;
				}
			}
		} 
	}

	ll inv[100005];
	void mulmodinv(long long MOD)
	{
		inv[1]=1;
		inv[0]=1;
		for(int i = 2; i <= 100005; i++)
		inv[i] = inv[MOD % i]*(MOD-MOD / i) % MOD;
	}*/

	bool ispow2(ll n)
	{
		if(((n & (n-1)) == 0) && n!=0)
		{
			return true;
		}
		return false;
	}
	//=============================
	const int N=3e5;
	const int rtn=800;
	int a[N];
	int mat[rtn][rtn];
	int dp[rtn][rtn];
	int local[N];
	int bkt[N];
	int en[rtn];
	unordered_map<int, int> cnt[rtn+1];
	void compute(int b)
	{
		dp[b][0]=mat[b][0];
		cnt[b].clear();
		for(int i=1;i<=en[b];i++)
		{
			dp[b][i]=mat[b][i]^dp[b][i-1];
		}
		for(int i=0;i<=en[b];i++)
		{
			cnt[b][dp[b][i]]++;
		}
	}
	int main()
	{
		ios_base::sync_with_stdio(0); 
		cin.tie(0);
		
		int n,q;
		cin>>n>>q;
		int li=0,b=-1;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(i%rtn==0)
			{
				if(b>=0)
				{
					compute(b);
				}
				b++;
				li=0;
			}
			local[i]=li;
			bkt[i]=b;
			en[b]=li;
			mat[b][li]=a[i];
			li++;
		}
		compute(b);
		int type,i,x;
		while(q--)
		{
			cin>>type>>i>>x;
			i--;
			b=bkt[i];
			li=local[i];
			if(type==1)
			{
				mat[b][li]=x;
				compute(b);
			}
			else
			{
				int pre=0,ans=0,need;
				for(int i=0;i<b;i++)
				{
					need=x^pre;
					ans+=cnt[i][need];
					pre=pre^dp[i][en[i]];
				}
				for(int i=0;i<=li;i++)
				{
					pre=pre^mat[b][i];
					if(pre==x)
					{
						ans++;
					}
				}
				cout<<ans<<endl;
			}
		}
		return 0;
	}
