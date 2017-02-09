#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>

bool inCircle(double x, double y) {
	return x*x + y*y < 1;
}

double GetPi(size_t n) {
    boost::uniform_01<boost::mt19937> gen((boost::mt19937()));
    size_t inside = 0;

    for (size_t i = 0; i < n; i++)
        inside += inCircle(gen(), gen());

    return 4.0 * inside / n;
}

int main() {
    std::cout << GetPi(10000000) << std::endl;
    return 0;
}