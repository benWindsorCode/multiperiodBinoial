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

double Derivative::priceAtIntermediate(int n, int up, int down) {
    const double discountRate = 1/(1+this->pStock->getR());

    if(n == this->pStock->getN()) {
        return payoff(up, down);
    }

    return discountRate*(this->pStock->getPtilde()*priceAtIntermediate(n, up+1, down) + this->pStock->getQtilde()*priceAtIntermediate(n, up, down+1));
}