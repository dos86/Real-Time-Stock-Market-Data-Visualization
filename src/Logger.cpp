#include "Logger.hpp"
#include <iomanip>

Logger::Logger(const std::string& logFilePath) {
    logFile.open(logFilePath, std::ios::out);
    if (!logFile) {
        throw std::runtime_error("Failed to open log file.");
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::logStockData(const std::unordered_map<std::string, Stock>& stocks) {
    for (const auto& [symbol, stock] : stocks) {
        logFile << "Stock: " << symbol << "\n";
        for (size_t i = 0; i < stock.prices.size(); ++i) {
            logFile << "Day " << i + 1 << ": Price = " << stock.prices[i]
                    << ", MA = " << (i < stock.movingAvg.size() ? stock.movingAvg[i] : 0)
                    << ", RSI = " << (i < stock.rsi.size() ? stock.rsi[i] : 0)
                    << ", MACD = " << (i < stock.macd.size() ? stock.macd[i] : 0) << "\n";
        }
    }
}
