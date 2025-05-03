#include "ChartRenderer.hpp"
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

ChartRenderer::ChartRenderer(QWidget* parent)
    : QChartView(new QChart(), parent) {
    chart = this->chart();
    chart->setTitle("Real-Time Stock Market Visualization");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
}

void ChartRenderer::renderCharts(const std::unordered_map<std::string, Stock>& stocks) {
    chart->removeAllSeries(); // Clear previous data

    for (const auto& [symbol, stock] : stocks) {
        QLineSeries* series = new QLineSeries();
        series->setName(QString::fromStdString(symbol));

        for (size_t i = 0; i < stock.prices.size(); ++i) {
            series->append(i, stock.prices[i]);
        }

        chart->addSeries(series);

        // Configure axes
        QValueAxis* axisX = new QValueAxis();
        axisX->setTitleText("Time (Days)");
        axisX->setLabelFormat("%d");

        QValueAxis* axisY = new QValueAxis();
        axisY->setTitleText("Price ($)");
        axisY->setLabelFormat("%.2f");

        chart->addAxis(axisX, Qt::AlignBottom);
        chart->addAxis(axisY, Qt::AlignLeft);

        series->attachAxis(axisX);
        series->attachAxis(axisY);
    }
}
