#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


//=====================================================================


int lcp( string A, string B )
{
   int result = 0;
   int length = min( A.size(), B.size() );
   while ( result < length && A[result] == B[result] ) result++;
   return result;
}


//=====================================================================


int main()
{
// istream &in = cin;                 // Use this for actual input
   stringstream in(                   // Version for testing
                    "4       \n"
                    "abcd    \n"
                    "abce    \n"
                    "abcdex  \n"
                    "abcde   \n"
                    "3       \n"
                    "3 abcy  \n"
                    "3 abcde \n"
                    "4 abcde \n"
                  );

   int N, Q, R;
   string P, str;
   map<string,int> S;
   map<string,int>::iterator ita, itb, it;


   // Read strings
   cin >> N;
   for ( int i = 0; i < N; i++ ) 
   {
      cin >> str;
      S.insert( pair<string,int>( str, i + 1 ) );
   }


   // Now deal with the queries one by one
   cin >> Q;
   for ( int q = 0; q < Q; q++ )
   {
      cin >> R >> P;

      // Find where P is or would be in the map (which is sorted, so longest common prefix is just before or after)
      auto found = S.find( P );
      if ( found != S.end() && found->second <= R )        // If this is already available before line R, just print it out
      {
         cout << P << '\n';
         continue;
      }
      auto ins = found;                                    // Otherwise either use current position of P ...
      if ( found == S.end() ) ins = S.insert( pair<string,int>( P, -1 ) ).first;     // ... or insert if necessary

      // Find the common prefix length on either side; the larger will be the maximum common prefix
      int bef = -1, aft= -1;
      ita = ins;
      for ( ita++; ita != S.end(); ita++ )                 // Strings after P in lexicographical order
      {
         if ( ita->second <= R )
         {
            aft = lcp( ita->first, P );
            break;
         }
      }

      itb = ins;
      while ( itb != S.begin() )                           // Strings before P in lexicographical order
      {cout<<"test6"<<endl;
         itb--;
         if ( itb->second <= R )
         {cout<<"test7"<<endl;
            bef = lcp( itb->first, P );
            break;
         }
      }

      if ( aft > bef )               // Answer is immediately after in lexicographical order
      {
         cout << ita->first << '\n';
      }
      else                             // Otherwise, work backwards to find earliest string with same common prefix
      {cout<<"test1"<<endl;
         it = itb;
         while ( it != S.begin() )
         {cout<<"test2"<<endl;
            it--;
            if ( it->second <= R )
            {cout<<"test3"<<endl;
               if ( lcp( it->first, P ) == bef ) 
                {itb = it;cout<<"test4"<<endl;}
               else 	
                {break;cout<<"test5"<<endl;}
            }
         }
         cout << itb->first << '\n';
      }

      if ( found == S.end() ) S.erase( P );                // You put it ... you have to take it out!
   }
}
