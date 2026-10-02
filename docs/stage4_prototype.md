# Stage 4 – Initial Implementation & Prototype

## 1. Introduction

Stage 4 focuses on the initial implementation and development of a working prototype for the Smart Energy Smart-Meter Pulse Counter & Analytics Agent.

During this stage, the major software modules were implemented using C++ in a Linux environment. The individual modules were tested and then integrated into a working smart-meter simulation.

The prototype demonstrates pulse counting, energy calculation, analytics, usage classification, cost estimation, and data logging.

---

## 2. Development Environment

The project was developed and tested using:

- Operating System: Ubuntu Linux
- Programming Language: C++
- Compiler: G++
- Version Control: Git
- Repository: GitHub
- Development Interface: Linux Terminal

---

## 3. Project Structure

The implementation is organized into separate header, source, and test files.

```text
smart_meter_pulse_analytics/
│
├── include/
│   ├── analytics.h
│   ├── data_logger.h
│   ├── energy_calculator.h
│   └── pulse_counter.h
│
├── src/
│   ├── analytics.cpp
│   ├── data_logger.cpp
│   ├── energy_calculator.cpp
│   ├── main.cpp
│   └── pulse_counter.cpp
│
├── tests/
│   ├── test_analytics.cpp
│   ├── test_data_logger.cpp
│   ├── test_energy_calculator.cpp
│   └── test_pulse_counter.cpp
│
├── data/
│   ├── meter_readings.csv
│   └── test_meter_readings.csv
│
└── logs/
    └── meter.log
```

---

## 4. Implemented Modules

### 4.1 Pulse Counter

The Pulse Counter module is responsible for maintaining the number of pulses received from the simulated smart meter.

Source files:

```text
include/pulse_counter.h
src/pulse_counter.cpp
```

Test file:

```text
tests/test_pulse_counter.cpp
```

The module was implemented as a separate C++ component so that pulse-counting functionality can be tested independently.

---

### 4.2 Energy Calculator

The Energy Calculator processes the pulse count and converts it into an energy value.

Source files:

```text
include/energy_calculator.h
src/energy_calculator.cpp
```

Test file:

```text
tests/test_energy_calculator.cpp
```

The module is used by the main application to calculate energy consumption from the meter pulse count.

---

### 4.3 Analytics Engine

The Analytics Engine stores energy readings and performs basic calculations on them.

Source files:

```text
include/analytics.h
src/analytics.cpp
```

Test file:

```text
tests/test_analytics.cpp
```

The module supports:

- Adding energy readings.
- Calculating total energy.
- Calculating average energy.

The energy readings are stored using a C++ vector.

```cpp
std::vector<double> energyReadings;
```

---

### 4.4 Data Logger

The Data Logger module is responsible for saving relevant meter information.

Source file:

```text
src/data_logger.cpp
```

Header file:

```text
include/data_logger.h
```

Test file:

```text
tests/test_data_logger.cpp
```

The prototype uses files for storing meter information and logs.

Example files:

```text
data/meter_readings.csv
logs/meter.log
```

---

### 4.5 Main Application

The main application integrates the implemented modules.

Source file:

```text
src/main.cpp
```

The application:

1. Starts the meter simulation.
2. Accepts a pulse count.
3. Accepts measurement time.
4. Calculates energy used.
5. Calculates average power.
6. Applies the configured energy rate.
7. Estimates the energy cost.
8. Determines the usage status.
9. Saves the reading.
10. Displays the meter status.

---

## 5. Prototype Data Flow

The implemented prototype follows this flow:

```text
          Smart Meter Simulation
                    |
                    v
              Pulse Count
                    |
                    v
             Pulse Counter
                    |
                    v
            Energy Calculator
                    |
                    v
              Energy Used
                    |
          +---------+---------+
          |                   |
          v                   v
   Average Power        Cost Calculation
          |                   |
          +---------+---------+
                    |
                    v
             Usage Status
                    |
                    v
              Data Logger
                    |
             +------+------+
             |             |
             v             v
       CSV Reading      Meter Log
```

---

## 6. Module Testing During Prototype Development

Each major module was executed independently before running the complete application.

### Pulse Counter Test

Command:

```text
./pulse_counter_test
```

Result:

```text
PulseCounter test passed
```

This confirms that the Pulse Counter test completed successfully.

---

### Energy Calculator Test

Command:

```text
./energy_calculator_test
```

Result:

```text
EnergyCalculator test passed
```

This confirms that the Energy Calculator test completed successfully.

---

### Analytics Engine Test

Command:

```text
./analytics_test
```

Result:

```text
Total Energy: 46
Average Energy: 15.3333
```

This demonstrates that the Analytics Engine successfully processed the test energy readings and produced total and average values.

---

### Data Logger Test

Command:

```text
./data_logger_test
```

Result:

```text
DataLogger test passed
```

This confirms that the Data Logger test completed successfully.

---

## 7. Complete Prototype Demonstration

After testing the individual components, the complete application was executed using:

```text
./smart_meter
```

The following test input was provided:

```text
Pulse Count: 900
Measurement Time: 1 hour
```

The application produced:

```text
========================================
          SMART ENERGY METER
========================================

Starting meter simulation...

Enter pulse count: 900
Enter measurement time (hours): 1

        ENERGY METER ANALYTICS

Pulse Count       : 900
Energy Used       : 0.90 kWh
Time Measured     : 1.00 hour
Average Power     : 900.00 W
Rate              : ₹8.00 / kWh
Estimated Cost    : ₹7.20
Usage Status      : HIGH

Log File          : logs/meter.log
Reading Status    : SAVED

Meter Status      : RUNNING
```

---

## 8. Prototype Results

The prototype successfully demonstrated the following:

| Function | Result |
|---|---|
| Pulse input | 900 pulses accepted |
| Energy calculation | 0.90 kWh |
| Measurement duration | 1 hour |
| Average power | 900 W |
| Energy rate | ₹8.00/kWh |
| Estimated cost | ₹7.20 |
| Usage classification | HIGH |
| Reading storage | SAVED |
| Meter status | RUNNING |

The usage status is generated by the application's configured classification logic.

---

## 9. Prototype Features

The current prototype provides:

- Command-line meter simulation.
- Pulse-count input.
- Pulse counting.
- Energy calculation.
- Measurement-time input.
- Average power calculation.
- Energy-rate based cost estimation.
- Usage-status classification.
- Energy reading storage.
- Logging.
- Modular C++ implementation.
- Individual module tests.

---

## 10. Issues and Development Observations

During development, the project was divided into separate modules instead of implementing all functionality inside the main program.

This modular approach makes it easier to:

- Test individual components.
- Identify errors.
- Modify individual modules.
- Reuse functionality.
- Integrate components progressively.

The prototype also uses separate test programs for the major modules, allowing the components to be verified before complete-system execution.

---

## 11. Current Prototype Status

The initial prototype is operational.

The following modules have been implemented:

```text
Pulse Counter       → Implemented
Energy Calculator   → Implemented
Analytics Engine    → Implemented
Data Logger         → Implemented
Main Application    → Implemented
Module Tests        → Implemented
```

The complete smart-meter simulation runs successfully in the Linux environment.

---

## 12. Git and Version Control

The project is maintained using Git and hosted on GitHub.

Development is tracked through commits so that changes to source code and documentation can be monitored throughout the project lifecycle.

The Stage 4 documentation will be committed along with the prototype development.

---

## 13. Next Stage

The next stage is:

**Stage 5 – Testing, Integration & Improvement**

The next stage will focus on:

- More systematic unit testing.
- Integration testing.
- System testing.
- Testing different input values.
- Testing invalid inputs.
- Identifying and fixing issues.
- Improving reliability.
- Improving code quality.
- Updating documentation.
