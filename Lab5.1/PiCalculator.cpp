#include "PiCalculator.h"

bool PiCalculator::InCircle(double x, double y) {
    return x * x + y * y < 1;
}

double PiCalculator::GetPi(size_t precision) {
    boost::uniform_01<boost::mt19937> gen((boost::mt19937()));
    size_t inside = 0;

    for (size_t i = 0; i < precision; i++)
        inside += InCircle(gen(), gen());

    return 4.0 * inside / precision;
}

std::vector<double> PiCalculator::GetPiWithThreads(size_t precision, size_t threadsAmount) {
    std::vector<double> result;
    for (int threadsCounter = 0; threadsCounter < threadsAmount; ++threadsCounter) {
        boost::uniform_01<boost::mt19937> gen((boost::mt19937()));
        size_t inside = 0;

        for (size_t i = 0; i < precision; i++)
            inside += InCircle(gen(), gen());

        result.push_back(4.0 * inside / precision);
    }
    return result;
}
