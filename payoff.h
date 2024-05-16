#ifndef PAYOFF_H
#define PAYOFF_H

class Payoff
{

    public:

        enum OptionPayoff {call, put};
        Payoff(double option_strike, OptionPayoff option_type); // constructot
        double operator()(double spot) const; // given spot returns the payoff
        //const: no modification of the object (no change in strike or option type)

    private:

        double Strike;
        OptionPayoff Option_type;
};


#endif