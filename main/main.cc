#include <string>
#include <iostream>
#include "market/market.h"

int main(int argc, char** argv) {
    try {
        Market market = Market();
    } catch (const char* msg) {
        std::cout << "Error processing input, recieved message: " << msg << std::endl;
    }
    return 0;
}
