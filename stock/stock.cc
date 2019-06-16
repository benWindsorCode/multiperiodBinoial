#include <iostream>
#include "math.h"
#include "stock.h"

Stock::Stock() {
    double u, d, r, S_0;
    int N;
    std::cout << "Enter u:";
    std::cin >> u;
    std::cout << "Enter d:";
    std::cin >> d;
    std::cout << "Enter r:";
    std::cin >> r;
    std::cout << "Enter N:";
    std::cin >> N;    
    std::cout << "Enter S_0:";
    std::cin >> S_0;    
    this->u = u;
    this->d = d;
    this->r = r;
    this->N = N;
    this->S_0 = S_0;

    // As per Shreve, require 0<d<1+r<u to be arbitrage free
    if(d <= 0 || d >= 1 + r || 1 + r >= u) {
        throw "Input values will admit arbitrage";
    }

    this->p_tilde = (1+r-d)/(u-d);
    this->q_tilde = 1-this->p_tilde;
}

Stock::Stock(double u, double d, double r, int N, double S_0) {
    this->u = u;
    this->d = d;
    this->r = r;
    this->N = N;
    this->S_0 = S_0;
}

// returns S_0*(u^up)*(d^down) stock price at that position in the tree
double Stock::price(int up, int down) {
    if (up+down > this->getN()) {
        throw "Can't evalute time period past end of binomial model.";
    }
    return this->S_0 * pow(this->u, up) * pow(this->d, down);
}

int Stock::getN() {
    return this->N;
}

double Stock::getR() {
    return this->r;
}

double Stock::getPtilde() {
    return this->p_tilde;
}

double Stock::getQtilde() {
    return this->q_tilde;
}