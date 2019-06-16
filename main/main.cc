#include <string>
#include <iostream>
#include "stock/stock.h"
#include "derivative/europeanCall.h"

int main(int argc, char** argv) {
    try {
        Stock* stock = new Stock(1.5, 0.9, 0.0, 2, 10);
        EuropeanCall deriv = EuropeanCall(stock, 10.0);
        std::cout << "Payoff: ";
        std::cout << deriv.payoff(1,1) << "\n";
    } catch (const char* msg) {
        std::cout << "Error in processing, recieved message: " << msg << std::endl;
    }
    
    return 0;
}