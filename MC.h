#ifndef SIMPLEMC_H
#define SIMPLEMC_H
#include "payoff.h"

double MonteCarlo(const Payoff& payoff,double spot,double strike, double expiry,double vol,double r,unsigned long number_paths);

#endif