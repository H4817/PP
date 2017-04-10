#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>

class PiCalculator {

    PiCalculator() = delete;

    PiCalculator &operator=(PiCalculator const &) = delete;

    PiCalculator &operator=(PiCalculator &&) = delete;

public:
    static double GetPi(size_t precision);
    static std::vector<double> GetPiWithThreads(size_t precision, size_t threadsAmount);

private:
    static bool InCircle(double x, double y);

};
