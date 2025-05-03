#include "TechnicalIndicators.hpp"
#include <numeric>

std::vector<double> TechnicalIndicators::calculateMovingAverage(const std::vector<double>& prices, int windowSize) {
    std::vector<double> ma;
    for (size_t i = windowSize - 1; i < prices.size(); ++i) {
        double sum = std::accumulate(prices.begin() + i - windowSize + 1, prices.begin() + i + 1, 0.0);
        ma.push_back(sum / windowSize);
    }
    return ma;
}

std::vector<double> TechnicalIndicators::calculateRSI(const std::vector<double>& prices, int period) {
    std::vector<double> gains, losses;
    for (size_t i = 1; i < prices.size(); ++i) {
        double diff = prices[i] - prices[i - 1];
        gains.push_back(diff > 0 ? diff : 0);
        losses.push_back(diff < 0 ? -diff : 0);
    }
    std::vector<double> rsi;
    for (size_t i = period; i < gains.size(); ++i) {
        double avgGain = std::accumulate(gains.begin() + i - period, gains.begin() + i, 0.0) / period;
        double avgLoss = std::accumulate(losses.begin() + i - period, losses.begin() + i, 0.0) / period;
        double rs = avgLoss == 0 ? 0 : avgGain / avgLoss;
        rsi.push_back(100 - (100 / (1 + rs)));
    }
    return rsi;
}

std::vector<double> TechnicalIndicators::calculateMACD(const std::vector<double>& prices) {
    auto ema12 = calculateMovingAverage(prices, 12);
    auto ema26 = calculateMovingAverage(prices, 26);
    std::vector<double> macd;
    for (size_t i = 0; i < ema12.size(); ++i) {
        macd.push_back(ema12[i] - ema26[i]);
    }
    return macd;
}
