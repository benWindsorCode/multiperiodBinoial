#include "derivative.h"
#include <iostream>

Derivative::Derivative() {
}

Derivative::Derivative(Stock* pStock) {
    this->pStock = pStock;
}

Derivative::Derivative(Stock* pStock, std::function<double(Stock*, int, int)> func) {
    this->pStock = pStock;
    this->valueFunction = func;
}

double Derivative::payoff(int up, int down) {
    if (up+down != this->pStock->getN()) {
        throw "Can only evaluate derivative at final period";
    }
    return std::invoke(this->valueFunction, this->pStock, up, down);
}