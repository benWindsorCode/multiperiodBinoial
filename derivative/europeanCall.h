#ifndef EUROPEANCALL_H
#define EUROPEANCALL_H
#include "derivative/derivative.h"

class EuropeanCall : public Derivative {
    public: 
        EuropeanCall(Stock*, double);
    private:
        double strike;
};

#endif