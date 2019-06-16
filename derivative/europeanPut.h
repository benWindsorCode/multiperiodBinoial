#ifndef EUROPEANCALL_H
#define EUROPEANCALL_H
#include "derivative/derivative.h"

class EuropeanPut : public Derivative {
    public: 
        EuropeanPut(Stock*, double);
    private:
        double strike;
};

#endif