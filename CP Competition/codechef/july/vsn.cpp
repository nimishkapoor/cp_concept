#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
using namespace std;


const double EPS = 1.0e-40;


//======================================================================


struct vec{ double x, y, z; };

istream &operator >> ( istream & strm, vec &V ) { return strm >> V.x >> V.y >> V.z; }

double dot( vec &A, vec &B ) { return A.x * B.x + A.y * B.y + A.z * B.z; }

vec operator - ( vec &A, vec &B ) { return { A.x - B.x, A.y - B.y, A.z - B.z }; }


//======================================================================


int main()
{
   istream &in2 = cin;                 // Use this for actual input
   stringstream in(                    // Version for testing
                    "1                                        \n"
                    "3 0 0   -10 -10 0    0 10 0   0 -3  0  3 \n"
                  );

   int T;
   vec P, Q, D, C;
   double R;
   vec PC, PQ;
   double PCdotD, PQdotD, PCdotPQ, Dsq, PQsq, PCsqminusRsq;
   double a, b, c;
   double t;


   in >> T;
   for ( int i = 0; i < T; i++ ) 
   {
      in >> P >> Q >> D >> C >> R;
      PC = C - P;
      PQ = Q - P;
      Dsq = dot( D, D );
      PQsq = dot( PQ, PQ );
      PCsqminusRsq = dot( PC, PC ) - R * R;
      PQdotD  = dot( PQ, D );
      PCdotD  = dot( PC, D );
      PCdotPQ = dot( PC, PQ );

      a = PCsqminusRsq * Dsq - PCdotD * PCdotD;
      b = 2 * ( PCsqminusRsq * PQdotD - PCdotPQ * PCdotD );
      c = PCsqminusRsq * PQsq - PCdotPQ * PCdotPQ;

      if ( abs( a ) < EPS ) t = - c / b;
      else if ( a >  0 )    t = ( -b + sqrt( b * b - 4.0 * a * c ) ) / ( 2.0 * a );
      else                  t = ( -b - sqrt( b * b - 4.0 * a * c ) ) / ( 2.0 * a );

      cout << scientific << setprecision( 12 ) << t << '\n';
   }
}
