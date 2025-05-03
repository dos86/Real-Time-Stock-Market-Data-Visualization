#ifndef CHARTRENDERER_HPP
#define CHARTRENDERER_HPP

#include <unordered_map>
#include "Stock.hpp"

class ChartRenderer {
public:
    void renderCharts(const std::unordered_map<std::string, Stock>& stocks);

private:
    void renderLineChart(const Stock& stock);
    void renderCandlestickChart(const Stock& stock);
};

#endif // CHARTRENDERER_HPP
