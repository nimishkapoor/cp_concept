#include<bits/stdc++.h>
#define x first
#define y second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<'\n'
#define FOR(a,b,c) for(int a=(b),a##_end=(c);a<=a##_end;++a)
#define ROF(a,b,c) for(int a=(b),a##_end=(c);a>=a##_end;--a)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<int,PII> PIP;
const int INF=0x3f3f3f3f,N=1e5+10;
template<class T>inline bool chkmin(T &A,T B){return B<A?A=B,1:0;}
template<class T>inline bool chkmax(T &A,T B){return A<B?A=B,1:0;}
int n,K;
vector<PII>E[N];
int main(){
	int cas,x;
	scanf("%d",&cas);
	while(cas--){
		ll ans=0;
		scanf("%d%d",&n,&K);
		FOR(i,1,n)E[i].clear();
		FOR(i,1,n){
			scanf("%d",&x);
			E[i].push_back({x,i});
			int las=x;
			for(auto y:E[i-1])
				if((las|y.x)>las){
					las|=y.x;
					E[i].push_back({las,y.y});
				}
		}
		FOR(i,1,n)for(auto y:E[i])
				ans+=y.x*y.y-y.x;
		printf("%lld\n",ans);
	}
	return 0;
}
