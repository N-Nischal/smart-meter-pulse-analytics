#!/bin/bash

g++ -std=c++11 -Iinclude \
src/main.cpp \
src/pulse_counter.cpp \
src/energy_calculator.cpp \
src/analytics.cpp \
src/data_logger.cpp \
-o smart_meter

g++ -std=c++11 -Iinclude \
tests/test_pulse_counter.cpp \
src/pulse_counter.cpp \
-o pulse_counter_test

g++ -std=c++11 -Iinclude \
tests/test_energy_calculator.cpp \
src/energy_calculator.cpp \
-o energy_calculator_test

g++ -std=c++11 -Iinclude \
tests/test_analytics.cpp \
src/analytics.cpp \
-o analytics_test

g++ -std=c++11 -Iinclude \
tests/test_data_logger.cpp \
src/data_logger.cpp \
-o data_logger_test

echo "Build completed successfully."
