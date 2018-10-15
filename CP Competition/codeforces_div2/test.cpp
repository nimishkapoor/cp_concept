#include<bits/stdc++.h>
using namespace std;
int main(){
long long int t,n,k,i,l,c;
cin>>t;
while(t--){
	cin>>n>>k>>l;
	c=0;
	if(n+k<l)
		c=(l-(n+k));
	else if(n+k==l)
		c=0;
	else if(n>l && n>k)
		c=n-(l+k);
	else if(k>n && k>l)
		c=k-(n+l);
if(c<0)
	c=0;
	cout<<c<<endl;}
		
return 0;}
