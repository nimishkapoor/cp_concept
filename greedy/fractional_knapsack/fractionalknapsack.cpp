#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,v,wt,val;
 double r;
 cin>>n;
 multimap<double, pair<int,int > ,greater<double> > ml;
 for(int i=0;i<n;i++)
 {
  cin>>wt>>val;
  r=(double)val/wt;
  ml.insert(make_pair(r,make_pair(wt,val)));
 }
 cin>>v;
 
 double cw=0,cv=0;
 multimap<double, pair<int,int > >::iterator it=ml.begin();
 for(it=ml.begin();it!=ml.end();it++)
 {
  cout<<"wt:"<<it->second.first<<" "<<"val:"<<it->second.second<<" "<<"rat"<<it->first<<endl;
 }
 it=ml.begin();
 while(true)
 {
  if(cw+it->second.first<v)
  {
   cw+=it->second.first;
   cv+=it->second.second;
   it++;
  }
  else
  {
   int rw=v-cw;
   cv+=(double)it->first*rw;
   cout<<cv<<endl;
   cw+=cw+rw;
   break;
  }
  cout<<cv<<endl;
 }
 cout<<cv<<endl;
 return 0;
}
