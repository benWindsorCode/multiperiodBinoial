#ifndef DERIVATIVE_H
#define DERIVATIVE_H
#include <functional>
#include "stock/stock.h"

class Derivative {
    public:
        Derivative();
        Derivative(Stock*);
        Derivative(Stock*, std::function<double(Stock*, int, int)>);
        double payoff(int, int);
    protected:
        double priceAtIntermediate(int, int, int);
        std::function<double(Stock*, int, int)> valueFunction;
        Stock* pStock;
};

#endif