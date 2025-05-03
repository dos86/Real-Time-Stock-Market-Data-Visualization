cmake_minimum_required(VERSION 3.10)
project(StockMarketVisualization)

set(CMAKE_CXX_STANDARD 17)

add_executable(StockMarketVisualization
    src/Stock.cpp
    src/StockMarket.cpp
    src/ChartRenderer.cpp
    src/Logger.cpp
    src/TechnicalIndicators.cpp
    main.cpp
)
