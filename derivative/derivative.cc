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

double Derivative::value() {
    return priceAtIntermediate(0, 0, 0);
}

double Derivative::priceAtIntermediate(int n, int up, int down) {
    const double discountRate = 1/(1+this->pStock->getR());
    std::cout << "Pricing at n: " << n << ", up: " << up << ", down: " << down << std::endl;
    if(n == this->pStock->getN()) {
        return payoff(up, down);
    }

    // todo: cache these results for performance improvement 
    return discountRate*(this->pStock->getPtilde()*priceAtIntermediate(n+1, up+1, down) + this->pStock->getQtilde()*priceAtIntermediate(n+1, up, down+1));
}