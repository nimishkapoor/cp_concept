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
//#define endl "\n"

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
int n;
vi g[1001];
int par[1001][101];
int lvl[1000];
void dfs(int n)
{
	for(unsigned int i=0;i<g[n].size();i++)
	{
		if(lvl[g[n][i]]==-1)
		{
			lvl[g[n][i]]=lvl[n]+1;
			par[g[n][i]][0]=n;
			dfs(g[n][i]);
		}
	}
}
void getanc()
{
	for(int i=1;i<=log2(n);i++)
	{
		for(int j=1;j<=n;j++)
		{
			par[j][i]=par[par[j][i-1]][i-1];
		}
	}
}
int lca(int u,int v)
{
	if(lvl[u]<lvl[v])
	{
		swap(u,v);
	}
	int dif=lvl[u]-lvl[v];
	int jp;
	while(dif!=0)
	{
		jp=log2(dif);
		u=par[u][jp];
		dif-=1<<jp;
	}
	if(u==v)
	{
		return v;
	}
	int i=log2(lvl[u]);
	for(;i>=0;i--)
	{
		if(par[u][i]!=-1 && par[u][i]!=par[v][i])
		{
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}
int dist(int u,int v)
{
	if(lvl[u]<lvl[v])
	{
		swap(u,v);
	}
	int w=lca(u,v);
	return lvl[u]+lvl[v]-(2*lvl[w]);
}
int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int u,v,q;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	clr(lvl);
	lvl[1]=0;
	par[1][0]=0;
	dfs(1);
	getanc();
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>u>>v;
		cout<<lca(u,v)<<" ";
		cout<<dist(u,v)<<endl;
	}
	return 0;
}
