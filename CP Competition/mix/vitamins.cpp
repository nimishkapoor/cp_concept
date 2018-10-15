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
const int inf = 300005;
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
    
	int n,x;
	cin>>n;
	string s;
	int a=inf,b=inf,c=inf,ab=inf,bc=inf,ac=inf,abc=inf,s1,s2,s3,t1,t2,t3;

	for(int i=0;i<n;i++)
	{
		cin>>x>>s;
		if(s.size()==3)
		{
			abc=min(abc,x);
		}
		else if(s.size()==1)
		{
			if(s[0]=='A')
			{
				a=min(a,x);
			}
			else if(s[0]=='B')
			{
				b=min(b,x);
			}
			else if(s[0]=='C')
			{
				c=min(c,x);
			}
		}
		else if(s.size()==2)
		{
			if((s[0]=='A' && s[1]=='B') || (s[0]=='B' && s[1]=='A'))
			{
				ab=min(ab,x);
			}
			else if((s[0]=='B' && s[1]=='C') || (s[0]=='C' && s[1]=='B'))
			{
				bc=min(bc,x);
			}
			else if((s[0]=='A' && s[1]=='C') || (s[0]=='C' && s[1]=='A'))
			{
				ac=min(ac,x);
			}
		}
	}
	
	t1=min3(ab+c,ab+bc,ab+ac);
	t2=min3(ac+b,ac+bc,ac+ab);
	t3=min3(bc+a,bc+ac,bc+ab);
	
	s2=min3(t1,t2,t3);
	s1=a+b+c;
	s3=abc;
	
	cout<<(min3(s1,s2,s3)<inf?min3(s1,s2,s3):-1)<<endl;
	
	return 0;
}
