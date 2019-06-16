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
    return std::invoke(this->valueFunction, this->pStock, up, down);
}