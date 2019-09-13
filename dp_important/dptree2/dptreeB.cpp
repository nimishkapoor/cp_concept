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
#define clr(a) memset(a, -1, sizeof(a))	
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
vi g[1000];
int in[1000];
int out[1000];
void dfs1(int parent)
{
	int mx=0;
	in[parent]=0;
	for(unsigned int i=0;i<g[parent].size();i++)
	{
		if(in[g[parent][i]]==-1)
		{
			dfs1(g[parent][i]);
			mx=max(mx,1+in[g[parent][i]]);
		}
	}
	in[parent]+=mx;
}
void dfs2(int parent)
{
	int mx1=0,mx2=0;
	for(unsigned int i=0;i<g[parent].size();i++)
	{
		if(out[g[parent][i]]==-1)
		{
			if(in[g[parent][i]]>mx1)
			{
				mx2=mx1;
				mx1=in[g[parent][i]];
			}
			else if(in[g[parent][i]]>mx2)
			{
				mx2=in[g[parent][i]];
			}
		}
	}
	for(unsigned int i=0;i<g[parent].size();i++)
	{
		if(out[g[parent][i]]==-1)
		{	
			if(in[g[parent][i]]==mx1)
			{
				out[g[parent][i]]=max(1+out[parent],2+mx2);
			}
			else
			{
				out[g[parent][i]]=max(1+out[parent],2+mx1);
			}
			dfs2(g[parent][i]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,e,u,v;
    cin>>n;
    e=n-1;
    for(int i=0;i<e;i++)
    {
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	clr(in);
	clr(out);
	dfs1(1);
	out[1]=0;
	dfs2(1);
	for(int i=1;i<=n;i++)
	{
		cout<<in[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<out[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<max(in[i],out[i])<<" ";
	}
	cout<<endl;
	return 0;
}
