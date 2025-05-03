# Real-Time-Stock-Market-Data-Visualization

#### Overview:
This project simulates a **real-time stock market data visualization system** that processes live stock price updates from a server or API and visualizes them using dynamic charts. The system uses **TCP/IP** for receiving stock price updates, **multithreading** for efficient data processing, and **graphical rendering** for displaying real-time trends. The application also allows users to filter and analyze specific stocks or indices.

---

### Key Features:
1. **Real-Time Data Streaming**:
   - Receive live stock price updates via TCP/IP sockets.
   - Simulate a stock exchange server that broadcasts price updates for multiple stocks.

2. **Data Processing**:
   - Process incoming stock price updates using multithreading.
   - Store historical data for each stock in memory for analysis.

3. **Dynamic Visualization**:
   - Use a GUI framework (e.g., Qt or WxWidgets) to render real-time line charts for stock prices.
   - Allow users to zoom in/out, pause/resume, and filter specific stocks or indices.

4. **STL Usage**:
   - Use `std::unordered_map` to store stock data (e.g., stock symbol → price history).
   - Use `std::vector` to store price history for each stock.

5. **OOP Design**:
   - Encapsulate the stock data, visualization logic, and networking in separate classes (`Stock`, `StockMarket`, `ChartRenderer`).
   - Use polymorphism to allow different types of visualizations (e.g., line chart, candlestick chart).

6. **Error Handling**:
   - Handle invalid stock symbols, missing data, and network errors.
   - Provide meaningful error messages for debugging.

7. **Optional Enhancements**:
   - **Custom Indicators**: Add technical indicators like moving averages, RSI, or MACD.
   - **Performance Metrics**: Display real-time performance metrics (e.g., latency, update frequency).
   - **Database Integration**: Store historical stock data in a database (e.g., Microsoft SQL Server) for later retrieval.

---

#### Folder Structure:
```
StockMarketVisualization/
├── include/
│   ├── Stock.hpp           // Stock class definition
│   ├── StockMarket.hpp     // Stock market class definition
│   ├── ChartRenderer.hpp   // Chart rendering class definition
│   ├── Logger.hpp          // Logging utility
│   └── TechnicalIndicators.hpp // Technical indicators implementation
├── src/
│   ├── Stock.cpp
│   ├── StockMarket.cpp
│   ├── ChartRenderer.cpp
│   ├── Logger.cpp
│   └── TechnicalIndicators.cpp
├── main.cpp                // Main entry point
├── CMakeLists.txt          // Build configuration
└── README.md               // Project documentation
```

---

### Workflow:
1. **Stock Exchange Server**:
   - Simulates a stock exchange by broadcasting random price updates for multiple stocks over TCP/IP.

2. **Stock Market Client**:
   - Connects to the server and receives real-time stock price updates.
   - Processes updates using a thread pool and stores historical data in memory.

3. **Chart Rendering**:
   - Renders real-time line charts for selected stocks.
   - Allows users to interact with the charts (e.g., zoom, filter, pause).

4. **Optional Database Integration**:
   - Stores historical stock data in a database for later analysis.

---

### Example Use Case:
- A user starts the stock exchange server, which broadcasts random price updates for stocks like AAPL, MSFT, and GOOG.
- The user launches the client application, which connects to the server and displays real-time charts for the selected stocks.
- The user can zoom in on specific time intervals, add technical indicators, or filter specific stocks.

---

### Technologies Used:
1. **STL**: `std::unordered_map`, `std::vector`, `std::thread`, `std::mutex`.
2. **OOP**: Encapsulation and modularity in designing `Stock`, `StockMarket`, and `ChartRenderer` classes.
3. **Multithreading**: Concurrent handling of data processing and rendering.
4. **Networking**: TCP/IP sockets for real-time data streaming.
5. **GUI Framework**: Qt or WxWidgets for graphical rendering.
6. **Database (Optional)**: Interaction with Microsoft SQL Server using ODBC for storing historical data.
