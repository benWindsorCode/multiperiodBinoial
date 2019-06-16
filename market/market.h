#ifndef MARKET_H
#define MARKET_H

class Market {
    public:
        Market();
        Market(double, double, double, double);
    private:
        double u;
        double d;
        double r;
        double N;
        double p_tilde;
        double q_tilde;
};

#endif
