#ifndef CHARTRENDERER_HPP
#define CHARTRENDERER_HPP

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <unordered_map>
#include "Stock.hpp"

QT_CHARTS_USE_NAMESPACE

class ChartRenderer : public QChartView {
    Q_OBJECT

public:
    explicit ChartRenderer(QWidget* parent = nullptr);
    void renderCharts(const std::unordered_map<std::string, Stock>& stocks);

private:
    QChart* chart;
};

#endif // CHARTRENDERER_HPP
