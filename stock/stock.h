#ifndef STOCK_H
#define STOCK_H

/**
 * Class to model a single stock (or any asset really) with properties:
 * S_0 = initial value of asset
 * u = multiplier when moving up in the multinomial tree
 * d = multiplier when moving down in the multinomial tree
 * r = risk free rate of return
 * N = number of periods in the multinomial model
 * p_tilde, q_tilde = risk neutral probabilities, such that q_tilde = 1 - p_tilde
 */
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
