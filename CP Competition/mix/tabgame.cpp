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
int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
		

		string n,m;
		cin>>m;
		cin>>n;
		int va1[n.size()+2],ha1[m.size()+2];
		int va2[n.size()+2],ha2[m.size()+2];
		
		n='*'+n;
		m='*'+m;
		
		if(n[1]=='0' || m[1]=='0')
		{
			va1[1]=1;
			ha1[1]=1;
		}
		else 
		{
			va1[1]=0;
			ha1[1]=0;
		}
		for(int i=2;i<n.size();i++)
		{
			if(n[i]=='0')
			{
				va1[i]=1;
			}
			else 
			{
				if(va1[i-1]==0)
				{
					va1[i]=1;
				}
				else
				{
					va1[i]=0;
				}
			}
		}
		for(int i=2;i<m.size();i++)
		{
			if(m[i]=='0')
			{
				ha1[i]=1;
			}
			else
			{
				if(ha1[i-1]==0)
				{
					ha1[i]=1;
				}
				else
				{
					ha1[i]=0;
				}
			}
		}
		
		if(n.size()>=3 || m.size()>=3)
		{
			if(va1[2]==0 || ha1[2]==0)
			{
				va2[2]=1;
				ha2[2]=1;
			}
			else
			{
				va2[2]=0;
				ha2[2]=0;
			}
			for(int i=3;i<n.size();i++)
			{
				if(va1[i]==0 || va2[i-1]==0)
				{
					va2[i]=1;
				}
				else
				{
					va2[i]=0;
				}
			}
			for(int i=3;i<m.size();i++)
			{
				if(ha1[i]==0 || ha2[i-1]==0)
				{
					ha2[i]=1;
				}
				else
				{
					ha2[i]=0;
				}
			}
		}
		
		int q,x,y;
		cin>>q;
		while(q--)
		{
			cin>>x>>y;
			if(x==1 || y==1)
			{
				if(x==1)
				{
					cout<<ha1[y];
				}
				else
				{
					cout<<va1[x];
				}
			}
			else if (x==2 || y==2)
			{
				if(x==2)
				{
					cout<<ha2[y];
				}
				else
				{
					cout<<va2[x];
				}
			}
			else
			{
				if(x<=y)
				{
					cout<<ha2[y-x+2];
				}
				else
				{
					cout<<va2[x-y+2];
				}
			}
		}
		cout<<endl;
		
	}
	return 0;
}
