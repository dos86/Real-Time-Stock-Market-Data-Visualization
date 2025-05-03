#include "StockMarket.hpp"
#include <iostream>
#include <random>
#include <chrono>
#include <thread>

void StockMarket::start() {
    running = true;
    std::thread updateThread(&StockMarket::simulatePriceUpdates, this);
    updateThread.detach();
}

void StockMarket::stop() {
    running = false;
}

void StockMarket::addStock(const std::string& symbol) {
    std::lock_guard<std::mutex> lock(mtx);
    stocks[symbol] = Stock{symbol};
}

void StockMarket::removeStock(const std::string& symbol) {
    std::lock_guard<std::mutex> lock(mtx);
    stocks.erase(symbol);
}

void StockMarket::processUpdates() {
    while (running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::lock_guard<std::mutex> lock(mtx);
        for (auto& [symbol, stock] : stocks) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(0.95, 1.05); // Simulate price changes
            double newPrice = stock.prices.empty() ? 100 : stock.prices.back() * dis(gen);
            stock.updatePrice(newPrice);
        }
    }
}

void StockMarket::simulatePriceUpdates() {
    processUpdates();
}
