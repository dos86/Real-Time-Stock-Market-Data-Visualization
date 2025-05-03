#include "Stock.hpp"
#include <numeric>

void Stock::updatePrice(double price) {
    prices.push_back(price);

    // Update moving average
    if (prices.size() >= 10) { // Example: 10-day moving average
        double sum = std::accumulate(prices.end() - 10, prices.end(), 0.0);
        movingAvg.push_back(sum / 10);
    }

    // Update RSI
    if (prices.size() >= 14) { // Example: 14-day RSI
        rsi.push_back(TechnicalIndicators::calculateRSI(prices, 14).back());
    }

    // Update MACD
    if (prices.size() >= 26) { // Example: MACD requires at least 26 days of data
        macd.push_back(TechnicalIndicators::calculateMACD(prices).back());
    }
}
