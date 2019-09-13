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
vi g[1001];
int lvl[1001];
int p[1001][100];
int lg,n;
void dfs1(int parent)
{
	for(unsigned int i=0;i<g[parent].size();i++)
	{
		if(lvl[g[parent][i]]==-1)
		{
			p[g[parent][i]][0]=parent;
			lvl[g[parent][i]]=lvl[parent]+1;
			dfs1(g[parent][i]);
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
	while(dif>0)
	{
		jp=log2(dif);
		u=p[u][jp];
		dif-=1<<jp;
	}
	while(u!=v)
	{
		int i=log2(lvl[u]);
		for(;i>0 && p[u][i]==p[v][i];i--)
		{
		}
		u=p[u][i];
		v=p[v][i];
	}
	return u;
}
void getanc()
{
	for(int i=1;i<=lg;i++)
    {
		for(int j=1;j<=n;j++)
		{
			p[j][i]=p[p[j][i-1]][i-1];
		}
	}
}
int dist(int u,int v)
{
	if(lvl[u]<lvl[v])
	{
		swap(u,v);
	}
	int w=lca(u,v);
	return lvl[u]+lvl[v]-2*lvl[w];
}
int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int e,q1,q2,u,v;
    cin>>n;
    e=n-1;
    clr(lvl);
    for(int i=0;i<e;i++)
    {
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	cin>>q1;
	lvl[1]=0;
	clr(p);
	dfs1(1);
	p[1][0]=0;
    lg=log2(n);
    getanc();
    for(int i=0;i<q1;i++)
    {
    cin>>u>>v;
    cout<<lca(u,v)<<endl;
    cout<<dist(u,v)<<endl;
	}
	return 0;
}
