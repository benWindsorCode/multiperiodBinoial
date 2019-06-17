#ifndef EUROPEANCALL_H
#define EUROPEANCALL_H
#include "derivative/derivative.h"

/**
 * Class to model european call option. 
 * i.e. a derivative which gives the option to buy one unit of underlying at given strike price at time N
 */
class EuropeanCall : public Derivative {
    public: 
        EuropeanCall(Stock*, double);
    private:
        double strike;
};

#endif