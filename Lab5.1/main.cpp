#include <iostream>
#include <sstream>
#include "PiCalculator.h"

int main(int argc, char *argv[]) {
    const size_t precision = 10000;
    if (argc == 2) {
        std::istringstream ss(argv[1]);
        int threadsAmount;
        if (ss >> threadsAmount && threadsAmount > 0) {
            std::cout << threadsAmount << std::endl;
            auto result = PiCalculator::GetPiWithThreads(precision, static_cast<size_t>(threadsAmount));
            for (int i = 0; i < threadsAmount; ++i) {
                std::cout << result[i] << std::endl;
            }
        }
        else {
            std::cout << "The input parameter: " << argv[1] << " should be a positive number" << std::endl;
        }
    }
    else {
        std::cout << PiCalculator::GetPi(precision) << std::endl;
    }

    return 0;
}