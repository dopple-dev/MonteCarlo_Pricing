#include "gaussian_rnd.h"
#include<cstdlib>
#include<cmath>

// basic math functions should be in namespace std but aren't in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif

double gaussian_rnd_summation()

{
    double result = 0;

    for (unsigned long j=0; j<12; j++)
        {
            result += rand()/static_cast<double>(RAND_MAX);
            result -= 6.0; 
        }

    return result; 

}

double gaussian_rnd_BoxMuller()

{
    double result;
    double x; 
    double y; 
    double square;

    do
        {
            x = 2.0*rand()/static_cast<double>(RAND_MAX)-1; 
            y = 2.0*rand()/static_cast<double>(RAND_MAX)-1; 
            square = x*x + y*y;
        }
    while(square >= 1.0); 

    result = x*sqrt(-2.0*log(square)/square); 

    return result; 
    
}