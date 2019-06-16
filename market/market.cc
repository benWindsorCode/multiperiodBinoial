#include <iostream>
#include "market.h"

Market::Market() {
    double u, d, r, N;
    std::cout << "Enter u:";
    std::cin >> u;
    std::cout << "Enter d:";
    std::cin >> d;
    std::cout << "Enter r:";
    std::cin >> r;
    std::cout << "Enter N:";
    std::cin >> N;    
    this->u = u;
    this->d = d;
    this->r = r;
    this->N = N;

    // As per Shreve, require 0<d<1+r<u to be arbitrage free
    if(d <= 0 || d >= 1 + r || 1 + r >= u) {
        throw "Input values will admit arbitrage";
    }

    this->p_tilde = (1+r-d)/(u-d);
    this->q_tilde = 1-this->p_tilde;
}

Market::Market(double u, double d, double r, double N) {
    this->u = u;
    this->d = d;
    this->r = r;
    this->N = N;
}
