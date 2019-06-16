#include "derivative/europeanPut.h"
#include "math.h"
#include <iostream>

// Payoff of (K-S)^+
EuropeanPut::EuropeanPut(Stock* pStock, double strike) : Derivative(pStock) {
    auto europeanPayoff = [strike](Stock* pStock, int up, int down) { 
        return std::max(strike-(pStock->price(up, down)), 0.0); 
    };
    this->strike = strike;
    this->valueFunction = europeanPayoff;
}