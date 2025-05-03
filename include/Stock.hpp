#ifndef STOCK_HPP
#define STOCK_HPP

#include <string>
#include <vector>

struct Stock {
    std::string symbol;              // Stock symbol (e.g., "AAPL")
    std::vector<double> prices;      // Historical prices
    std::vector<double> movingAvg;   // Moving average
    std::vector<double> rsi;         // Relative Strength Index
    std::vector<double> macd;        // Moving Average Convergence Divergence

    void updatePrice(double price);
};

#endif // STOCK_HPP
