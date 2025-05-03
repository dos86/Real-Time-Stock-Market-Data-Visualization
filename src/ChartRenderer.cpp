#include "ChartRenderer.hpp"
#include <iostream>

void ChartRenderer::renderCharts(const std::unordered_map<std::string, Stock>& stocks) {
    for (const auto& [symbol, stock] : stocks) {
        renderLineChart(stock);
    }
}

void ChartRenderer::renderLineChart(const Stock& stock) {
    std::cout << "Rendering line chart for stock: " << stock.symbol << "\n";
    for (size_t i = 0; i < stock.prices.size(); ++i) {
        std::cout << "Day " << i + 1 << ": Price = " << stock.prices[i]
                  << ", MA = " << (i < stock.movingAvg.size() ? stock.movingAvg[i] : 0)
                  << ", RSI = " << (i < stock.rsi.size() ? stock.rsi[i] : 0)
                  << ", MACD = " << (i < stock.macd.size() ? stock.macd[i] : 0) << "\n";
    }
}
