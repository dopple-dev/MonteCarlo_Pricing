#include "MC.h" 
#include<iostream> 
#include<cmath> 

int main()

{
    double expiry;
    double strike;
    double spot; 
    double vol; 
    double r;
    unsigned long number_paths;

    std::cout << "\nEnter spot: ";
    std::cin >> spot; 
    std::cout << "\nEnter strike: ";
    std::cin >> strike;
    std::cout << "\nEnter expiry: ";
    std::cin >> expiry;  
    std::cout << "\nEnter volatility: ";
    std::cin >> vol; 
    std::cout << "\nEnter risk free rate: ";
    std::cin >> r; 
    std::cout << "\nEnter number of Monte Carlo paths: ";
    std::cin >> number_paths;

    Payoff call_payoff(strike, Payoff::call);
    Payoff put_payoff(strike, Payoff::put);

    double call_price = MonteCarlo(call_payoff,spot,strike,expiry,vol,r,number_paths);
    double put_price = MonteCarlo(put_payoff,spot,strike,expiry,vol,r,number_paths);

    std::cout << "\n------------------- " << std::endl;
    std::cout << "MONTE CARLO RESULTS " << std::endl;
    std::cout << "Call price: " << call_price << std::endl;
    std::cout << "Put price: " << put_price << std::endl;
    std::cout << "-------------------\n" << std::endl;
    std::cout << "\nPress any key and enter to end the program" << std::endl;

    double tmp;
    std::cin >> tmp;

    return 0;

} 

