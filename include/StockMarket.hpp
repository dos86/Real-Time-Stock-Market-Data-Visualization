#ifndef STOCKMARKET_HPP
#define STOCKMARKET_HPP

#include <unordered_map>
#include <thread>
#include <mutex>
#include "Stock.hpp"
#include "Logger.hpp"

class StockMarket {
public:
    void start();
    void stop();
    void addStock(const std::string& symbol);
    void removeStock(const std::string& symbol);
    void processUpdates();

private:
    std::unordered_map<std::string, Stock> stocks;
    std::mutex mtx;
    bool running;

    void simulatePriceUpdates();
};

#endif // STOCKMARKET_HPP
