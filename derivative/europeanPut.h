#ifndef EUROPEANCALL_H
#define EUROPEANCALL_H
#include "derivative/derivative.h"

/**
 * Class to model european put option. 
 * i.e. a derivative which gives the option to sell one unit of underlying at given strike price at time N
 */
class EuropeanPut : public Derivative {
    public: 
        EuropeanPut(Stock*, double);
    private:
        double strike;
};

#endif