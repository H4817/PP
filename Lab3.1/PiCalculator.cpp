#include "PiCalculator.h"

bool PiCalculator::InCircle(double x, double y) {
    return x*x + y*y < 1;
}

double PiCalculator::GetPi(size_t precision) {
    boost::uniform_01<boost::mt19937> gen((boost::mt19937()));
    size_t inside = 0;

    for (size_t i = 0; i < precision; i++)
        inside += InCircle(gen(), gen());

    return 4.0 * inside / precision;
}
