#include "derivative/europeanCall.h"
#include "math.h"
#include <iostream>

// Payoff of (S-K)^+
EuropeanCall::EuropeanCall(Stock* pStock, double strike) : Derivative(pStock) {
    auto europeanPayoff = [strike](Stock* pStock, int up, int down) { 
        return std::max((pStock->price(up, down))-strike, 0.0); 
    };
    this->strike = strike;
    this->valueFunction = europeanPayoff;
}