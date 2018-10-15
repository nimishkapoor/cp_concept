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
bool prime(int x)
{
	if(x==1)
	{
		return false;
	}
	if(x==2)
	{
		return true;
	}
	if(x%2==0)
	{
		return false;
	}
	for(int i=3;i*i<=x;i+=2)
	{
		if(x%i==0)
		{
			return false;
		}
	}
 return true;
}
//=============================
int xc[1000006];
int yc[1000006];
int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
		vii a;
		int x,y,mx=0,my=0,x1,y1;
		clr(xc);
		clr(yc);
		for(int i=0;i<5;i++)
		{
			cin>>x>>y;
			a.pb(mp(x,y));
			xc[x]++;
			yc[y]++;
			if(mx<xc[x])
			{
				mx=xc[x];
				x1=x;
			}
			if(my<yc[y])
			{
				my=yc[y];
				y1=y;
			}
		}
		//sort(all(a));
		if(xc[x1]<3 || yc[y1]<3)
		{
			cout<<"No"<<endl;
			continue;
		}
		vector<int> xq,yq;
		for(int i=0;i<5;i++)
		{
			if(a[i].second==y1 && a[i].first==x1)
			{
				continue;
			}
			if(a[i].first==x1)
			{
				yq.pb(a[i].second);
			}
		}
		for(int i=0;i<6;i++)
		{
			if(a[i].second==y1 && a[i].first==x1)
			{
				continue;
			}
			if(a[i].second==y1)
			{
				xq.pb(a[i].first);
			}
		}
		sort(all(xq));
		sort(all(yq));
		if(yq[0]==(y1-1) && yq[1]==(y1+1))
		{
			if(xq[0]==(x1-2) && xq[1]==(x1-1))
			{
				cout<<"Yes"<<endl;
				continue;
			}
			if(xq[0]==(x1+1) && xq[1]==(x1+2))
			{
				cout<<"Yes"<<endl;
				continue;
			}
		}
		if(xq[0]==(x1-1) && xq[1]==(x1+1))
		{
			if(yq[0]==(y1-2) && yq[1]==(y1-1))
			{
				cout<<"Yes"<<endl;
				continue;
			}
			if(yq[0]==(y1+1) && yq[1]==(y1+2))
			{
				cout<<"Yes"<<endl;
				continue;
			}
		}
		cout<<"No"<<endl;
	}
	return 0;
}
