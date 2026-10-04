#!/bin/bash

echo "Building Smart Energy Meter..."

g++ -Wall -Wextra -std=c++11 src/main.cpp src/pulse_counter.cpp src/energy_calculator.cpp src/analytics.cpp src/data_logger.cpp src/pulse_generator.cpp src/device_driver.cpp -Iinclude -o smart_meter

g++ -Wall -Wextra -std=c++11 tests/test_pulse_counter.cpp src/pulse_counter.cpp -Iinclude -o pulse_counter_test

g++ -Wall -Wextra -std=c++11 tests/test_energy_calculator.cpp src/energy_calculator.cpp -Iinclude -o energy_calculator_test

g++ -Wall -Wextra -std=c++11 tests/test_analytics.cpp src/analytics.cpp -Iinclude -o analytics_test

g++ -Wall -Wextra -std=c++11 tests/test_data_logger.cpp src/data_logger.cpp -Iinclude -o data_logger_test

echo "Build completed successfully."
