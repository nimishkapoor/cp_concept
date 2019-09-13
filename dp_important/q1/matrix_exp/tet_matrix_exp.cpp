#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
struct mat{
	int x11;
	int x12;
	int x21;
	int x22;
};
mat mul(mat m1,mat m2)
{
	mat ret;
	ret.x11=(((m1.x11%mod)*(m2.x11%mod))%mod+((m1.x12%mod)*(m2.x21%mod))%mod)%mod;
	ret.x12=(((m1.x11%mod)*(m2.x12%mod))%mod+((m1.x12%mod)*(m2.x22%mod))%mod)%mod;
	ret.x21=(((m1.x21%mod)*(m2.x11%mod))%mod+((m1.x22%mod)*(m2.x21%mod))%mod)%mod;
	ret.x22=(((m1.x21%mod)*(m2.x12%mod))%mod+((m1.x22%mod)*(m2.x22%mod))%mod)%mod;
	return ret; 
}
mat binexp(int n,mat x)
{
	if(n==1)
	{
		return x;
	}
	mat temp;
	if(n%2==0)
	{
		temp=binexp(n/2,x);
		return mul(temp,temp);
	}
	else
	{
		temp=binexp(n/2,x);
		return mul(mul(temp,temp),x);
	}
}
int main()
{
	int n;
	cin>>n;
	mat magic;
	magic.x11=2;
	magic.x12=1;
	magic.x21=3;
	magic.x22=0;
	mat final=binexp(n-1,magic);
	cout<<final.x21<<endl;
	return 0;
}
