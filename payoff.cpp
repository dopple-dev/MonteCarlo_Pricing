#include "payoff.h"
#include <algorithm>
using namespace std;

Payoff::Payoff(double strike, OptionPayoff option_type):

    Strike(strike),Option_type(option_type){}

double Payoff::operator()(double Spot) const
{
    switch (Option_type)
    {
        case call:
            return max(Spot - Strike, 0.0);
        case put:
            return max(Strike - Spot,0.0);
            
        default:
            throw("unknow option type found.");
    }
}