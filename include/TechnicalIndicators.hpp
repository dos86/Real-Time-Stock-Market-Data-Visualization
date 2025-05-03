#ifndef TECHNICALINDICATORS_HPP
#define TECHNICALINDICATORS_HPP

#include <vector>

class TechnicalIndicators {
public:
    static std::vector<double> calculateMovingAverage(const std::vector<double>& prices, int windowSize);
    static std::vector<double> calculateRSI(const std::vector<double>& prices, int period);
    static std::vector<double> calculateMACD(const std::vector<double>& prices);
};

#endif // TECHNICALINDICATORS_HPP
