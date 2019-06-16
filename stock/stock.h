#ifndef STOCK_H
#define STOCK_H

class Stock {
    public:
        Stock();
        Stock(double, double, double, int, double);
        double price(int, int);
        int getN();
        double getR();
        double getPtilde();
        double getQtilde();
    private:
        double u;
        double d;
        double r;
        int N;
        double S_0;
        double p_tilde;
        double q_tilde;
};

#endif
