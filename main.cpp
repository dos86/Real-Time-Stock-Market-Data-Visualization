#include <QApplication>
#include "include/StockMarket.hpp"
#include "include/ChartRenderer.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    StockMarket stockMarket;
    ChartRenderer renderer;

    stockMarket.addStock("AAPL");
    stockMarket.addStock("MSFT");
    stockMarket.addStock("GOOG");

    stockMarket.start();

    QObject::connect(&stockMarket, &StockMarket::dataUpdated, [&renderer, &stockMarket]() {
        renderer.renderCharts(stockMarket.getStocks());
    });

    renderer.resize(800, 600);
    renderer.show();

    return app.exec();
}
