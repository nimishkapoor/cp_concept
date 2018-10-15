#include<bits/stdc++.h>
using namespace std;
int lll( string A, string B )
{
  int sol = 0;
  int length = min( A.size(), B.size() );
  while ( sol < length && A[sol] == B[sol] )
  {  
   sol++;
  }
  return sol;
}
int main()
{
 int N, Q, R;
 string P, str;
 map<string,int> S;
 map<string,int>::iterator aagya, item, it;
 cin >> N;
 for ( int i = 0; i < N; i++ ) 
 {
  cin >> str;
  S.insert( pair<string,int>( str, i + 1 ) );
 }
 cin >> Q;
 for ( int q = 0; q < Q; q++ )
 {
  cin >> R >> P;
  auto milgya = S.find( P );
  if ( milgya != S.end() && milgya->second <= R )      
  {
   cout << P << '\n';
   continue;
  }
  auto ins = milgya;                                    
  if ( milgya == S.end() ) ins = S.insert( pair<string,int>( P, -1 ) ).first;     
  int nnn = -1, mmm= -1;
  aagya = ins;
  for ( aagya++; aagya != S.end(); aagya++ )                 
  {
   if ( aagya->second <= R )
   {
    mmm = lll( aagya->first, P );
    break;
   }
  }
  item = ins;
  while ( item != S.begin() )                           
  {
   item--;
   if ( item->second <= R )
   {
    nnn = lll( item->first, P );
    break;
   }
  }

  if ( mmm > nnn )               
  {
   cout << aagya->first << '\n';
  }
  else                            
  {
   it = item;
   while ( it != S.begin() )
   {
    it--;
    if ( it->second <= R )
    {
     if ( lll( it->first, P ) == nnn ) 
       item = it;
     else                                               
     break;
    }
   }
   cout << item->first << '\n';
  }

  if ( milgya == S.end() ) S.erase( P );              
 }
}
