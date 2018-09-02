#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
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
//====================
const int N=3e5;
const int rtn=800;
int mat[rtn+1][rtn+1];
int dp[rtn+1][rtn+1];
int bkt[N];
int local[N];
int en[rtn+1];
int a[N];
unordered_map<int, int> cnt[rtn+1];
void compute(int b)
{
	cnt[b].clear();	
	dp[b][0]=mat[b][0];
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
    int n,q,b=-1,li;
    si(n);si(q);
    for(int i=0;i<n;i++)
    {
		si(a[i]);
		if(i%rtn==0)
		{
			if(b>=0) compute(b);
			b++;
			li=0;
		}
		en[b]=li;
		bkt[i]=b;
		local[i]=li;
		mat[b][li]=a[i];
		li++;
	}
	compute(b);
	int i,k,type;
	for(int j=0;j<q;j++)
	{
		si(type);
		si(i);
		si(k);
		i--;
		li=local[i];
		b=bkt[i];
		if(type==1)
		{
			mat[b][li]=k;
			compute(b);
		}
		else
		{
			
			int pre=0,ptr=0,ans=0,need,cur_bkt;
			while(bkt[ptr]<b)
			{
				need=k^pre;
				cur_bkt=bkt[ptr];
				ans+=cnt[cur_bkt][need];
				pre^=dp[cur_bkt][en[cur_bkt]];
				ptr+=rtn;
			}
			for(int j1=0;j1<=li;j1++)
			{
				pre^=mat[b][j1];
				if(pre==k)
				{
					ans++;
				}
			}
			pi(ans);
		}
	}
	return 0;
}

