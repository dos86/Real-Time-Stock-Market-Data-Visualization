#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>
#include <string>
#include <unordered_map>
#include "Stock.hpp"

class Logger {
public:
    Logger(const std::string& logFilePath);
    ~Logger();

    void logStockData(const std::unordered_map<std::string, Stock>& stocks);

private:
    std::ofstream logFile;
};

#endif // LOGGER_HPP
