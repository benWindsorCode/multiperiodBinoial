#ifndef DERIVATIVE_H
#define DERIVATIVE_H
#include <functional>
#include "stock/stock.h"

/**
 * Class to represent a derivative, with payoff defined by the valueFunction.
 * payoff(int up, int down) determines the payoff after #up moves up and #down moves down in the multinomial tree. 
 * value() determines the fair price (under arbitrage free assumption) at time zero.
 */
class Derivative {
    public:
        Derivative();
        Derivative(Stock*);
        Derivative(Stock*, std::function<double(Stock*, int, int)>);
        double payoff(int, int);
        double value();
    protected:
        double priceAtIntermediate(int, int, int);
        std::function<double(Stock*, int, int)> valueFunction;
        Stock* pStock;
};

#endif