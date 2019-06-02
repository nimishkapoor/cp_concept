#include<bits/stdc++.h>
using namespace std;
int main()
{
 int R=6,C=5;
 int M[R][C]={{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
 int S[R][C]={0};
 for(int i=0;i<C;i++)
 {
  S[0][i]=M[0][i];
 }
 for(int i=0;i<R;i++)
 {
  S[i][0]=M[i][0];
 }
 int maxl=0,temp;
 for(int i=1;i<R;i++)
 {
  for(int j=1;j<C;j++)
  {
   if(M[i][j]!=0)
   {
    temp=min(S[i-1][j],S[i][j-1]);
    S[i][j]=min(temp,S[i-1][j-1])+1;
    if(maxl<S[i][j])
    {
     maxl=S[i][j];
    }
   }
  }
 }
 for(int i=0;i<R;i++)
 {
  for(int j=0;j<C;j++)
  {
   cout<<S[i][j]<<" ";
  }
  cout<<endl;
 }	
 cout<<maxl<<endl;
 return 0;
}
 
