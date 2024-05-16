#include "MC.h"
#include "gaussian_rnd.h"
#include <cmath>
#if !defined(_MSC_VER)
using namespace std;
#endif

double MonteCarlo(const Payoff& Payoff_,
                  double spot,
                  double strike,
                  double expiry,
                  double vol,
                  double r,
                  unsigned long number_paths)

{
    double variance = vol*vol*expiry;
    double sqrt_variance = sqrt(variance);
    double drift_adjustment = -0.5 * variance;
    double partial_spot = spot*exp(r*expiry + sqrt_variance);

    double terminal_spot;
    double payoff_sum = 0;

    for (unsigned long i =0; i< number_paths; i++) // loop over all the paths 
            {
                double gaussian_rnd = gaussian_rnd_BoxMuller(); // draw random from standard normal 
                terminal_spot = partial_spot*exp(sqrt_variance*gaussian_rnd);
                double PayOff = Payoff_(terminal_spot);
                payoff_sum += PayOff;
            }
            
    double MC_mean = payoff_sum / number_paths;
    MC_mean *= exp(-r*expiry);

    return MC_mean;
}