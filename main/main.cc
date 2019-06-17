#include <string>
#include <iostream>
#include "stock/stock.h"
#include "derivative/europeanCall.h"

int main(int argc, char** argv) {
    const double u = 1.5;
    const double d = 0.9;
    const double r = 0.0;
    const int N = 1;
    const int S_0 = 10;
    try {
        Stock* stock = new Stock(u, d, r, N, S_0);
        EuropeanCall deriv = EuropeanCall(stock, 10.0);
        std::cout << "p_tilde: " << stock->getPtilde() << ", q_tilde: " << stock->getQtilde() << std::endl;
        std::cout << "Payoff: ";
        std::cout << deriv.payoff(1,0) << "\n";
        std::cout << "Value: " << deriv.value() << "\n";
    } catch (const char* msg) {
        std::cout << "Error in processing, recieved message: " << msg << std::endl;
    }

    return 0;
}