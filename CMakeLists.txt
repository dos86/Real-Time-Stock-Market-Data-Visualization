cmake_minimum_required(VERSION 3.10)
project(StockMarketVisualization)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Charts)

add_executable(StockMarketVisualization
    src/Stock.cpp
    src/StockMarket.cpp
    src/ChartRenderer.cpp
    main.cpp
)

target_link_libraries(StockMarketVisualization
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Charts
)
