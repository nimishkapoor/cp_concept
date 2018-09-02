#define N 5
#include<bits/stdc++.h>
using namespace std;
int issafe(int a[N][N], int r, int c)
{
 for(int i=0;i<r;i++)
 {
  if(a[i][c])
  {	
   return false;
  }
 }
 for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--)
 {
  if(a[i][j])
  {
   return false;
  }
 }
 for(int i=r-1,j=c+1;i>=0 && j<N;i--,j++)
 {
  if(a[i][j])
  {
   return false;
  }
 }
 return true;
}
int sol(int a[N][N], int r)
{
 if(r>=N)
 {
  return true;	
 }
 for(int i=0;i<N;i++)
 {
  if(issafe(a,r,i))
  {
   a[r][i]=1;
   if(sol(a, r+1))
   {
    return true;
   }
   a[r][i]=0;
  }
 }
 return false;
}
int main()
{
 int board[N][N]={0};
 if(sol(board, 0))
 {
  for(int i=0;i<N;i++)
  {
   for(int j=0;j<N;j++)
   {
    cout<<board[i][j]<<" ";
   }
   cout<<endl;
  }
 }
 else
 {
  cout<<"Not Possible"<<endl;
 }
 return 0;
}
