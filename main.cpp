#include <iostream>
#include "include/StockMarket.hpp"
#include "include/ChartRenderer.hpp"
#include "include/Logger.hpp"

int main() {
    try {
        StockMarket stockMarket;
        ChartRenderer renderer;
        Logger logger("stock_data_log.txt");

        stockMarket.addStock("AAPL");
        stockMarket.addStock("MSFT");
        stockMarket.addStock("GOOG");

        stockMarket.start();

        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            renderer.renderCharts(stockMarket.getStocks());
            logger.logStockData(stockMarket.getStocks());
        }

        stockMarket.stop();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
