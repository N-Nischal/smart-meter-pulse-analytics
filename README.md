# Smart Energy Smart-Meter Pulse Counter & Analytics Agent

## Project Overview

The **Smart Energy Smart-Meter Pulse Counter & Analytics Agent** is a Linux-based C++ application that simulates a smart electricity meter using virtual pulse readings.

The application accepts a pulse count and measurement time from the user. The input passes through a modular processing architecture consisting of a **PulseGenerator**, **DeviceDriver**, **PulseCounter**, **EnergyCalculator**, **AnalyticsEngine**, and **DataLogger**.

The system converts simulated meter pulses into energy consumption, calculates average power, estimates electricity cost, determines the usage status, and stores the reading in a local log file.

The project was developed and tested on **Ubuntu Linux using C++11**.

> **Note:** This project is a software simulation. It does not communicate with a physical electricity meter or real sensor hardware. The DeviceDriver used in this project is a user-space software abstraction and not a Linux kernel driver.

---

# Table of Contents

1. [Project Overview](#project-overview)
2. [Problem Statement](#problem-statement)
3. [Objectives](#objectives)
4. [System Architecture](#system-architecture)
5. [Data Flow](#data-flow)
6. [Module Description](#module-description)
7. [Energy Calculation](#energy-calculation)
8. [Average Power Calculation](#average-power-calculation)
9. [Electricity Cost Calculation](#electricity-cost-calculation)
10. [Usage Classification](#usage-classification)
11. [Input Validation](#input-validation)
12. [Project Structure](#project-structure)
13. [Technologies Used](#technologies-used)
14. [Requirements](#requirements)
15. [Compilation](#compilation)
16. [Running the Project](#running-the-project)
17. [Testing](#testing)
18. [Sample Execution](#sample-execution)
19. [Log File](#log-file)
20. [Linux Concepts Demonstrated](#linux-concepts-demonstrated)
21. [C++ Concepts Demonstrated](#c-concepts-demonstrated)
22. [Six-Stage Development Process](#six-stage-development-process)
23. [Limitations](#limitations)
24. [Future Improvements](#future-improvements)
25. [Development Status](#development-status)
26. [Author](#author)
27. [Conclusion](#conclusion)

---

# Problem Statement

Electricity meters generate readings that can be represented using electrical pulses. A software system can process these pulses to calculate energy consumption and provide useful information such as average power, estimated cost, and usage status.

The objective of this project is to develop a simple Linux-based C++ application that simulates this process.

The system should be able to:

- Accept a simulated pulse count.
- Accept the measurement time.
- Generate simulated pulses.
- Process pulses through a device-driver abstraction.
- Count the pulses.
- Convert pulses into energy.
- Calculate average power.
- Estimate electricity cost.
- Classify energy usage.
- Store readings in a log file.
- Perform basic analytics.
- Validate invalid input.
- Provide module-level testing.

---

# Objectives

The main objectives of the project are:

- To develop a smart-meter simulation using C++.
- To use modular object-oriented programming.
- To simulate meter pulse generation.
- To implement a user-space device-driver abstraction.
- To count meter pulses.
- To convert pulse readings into energy consumption.
- To calculate average power.
- To estimate electricity cost.
- To classify electricity usage.
- To store readings using file logging.
- To implement basic energy analytics.
- To validate user input.
- To create separate tests for major modules.
- To demonstrate Linux compilation and execution.
- To use Git and GitHub for version control.

---

# System Architecture

The project follows a modular architecture where each component has a specific responsibility.

```text
                    +----------------+
                    |   USER INPUT   |
                    +----------------+
                            |
                            v
                    +----------------+
                    | PulseGenerator |
                    +----------------+
                            |
                            v
                    +----------------+
                    |  DeviceDriver  |
                    +----------------+
                            |
                            v
                    +----------------+
                    |  PulseCounter  |
                    +----------------+
                            |
                            v
                  +--------------------+
                  |  EnergyCalculator  |
                  +--------------------+
                            |
                            v
                  +--------------------+
                  |  AnalyticsEngine   |
                  +--------------------+
                            |
                            v
                  +--------------------+
                  | Usage Classification|
                  +--------------------+
                            |
                            v
                    +----------------+
                    |   DataLogger   |
                    +----------------+
                            |
                            v
                    +----------------+
                    |  logs/meter.log|
                    +----------------+
```

---

# Data Flow

The complete application flow is:

```text
User enters pulse count and measurement time
                    |
                    v
             PulseGenerator
                    |
                    v
              DeviceDriver
                    |
                    v
              PulseCounter
                    |
                    v
            EnergyCalculator
                    |
                    v
             AnalyticsEngine
                    |
                    v
         Usage Classification
                    |
                    v
              DataLogger
                    |
                    v
             meter.log
```

### Processing Flow

1. The user enters the number of pulses.
2. The user enters the measurement time.
3. `PulseGenerator` generates the requested number of simulated pulses.
4. `DeviceDriver` receives and maintains the generated pulse count.
5. `PulseCounter` processes the pulse count.
6. `EnergyCalculator` converts pulses into energy.
7. Average power is calculated.
8. Estimated electricity cost is calculated.
9. The usage status is determined.
10. `AnalyticsEngine` stores the energy reading.
11. `DataLogger` saves the reading to `logs/meter.log`.
12. The results are displayed on the terminal.

---

# Module Description

## 1. PulseGenerator

File:

```text
include/pulse_generator.h
src/pulse_generator.cpp
```

The `PulseGenerator` simulates the generation of electricity-meter pulses.

For example, if the user enters:

```text
300
```

the PulseGenerator generates 300 simulated pulses.

It communicates with the `DeviceDriver` by calling its pulse-handling function.

---

## 2. DeviceDriver

Files:

```text
include/device_driver.h
src/device_driver.cpp
```

The `DeviceDriver` represents a simple software layer between pulse generation and pulse processing.

It maintains the number of pulses received.

Main functions:

```text
DeviceDriver()
handlePulse()
readPulseCount()
reset()
```

### Important Design Note

The DeviceDriver is a **user-space simulation**.

It is not a Linux kernel device driver and does not directly communicate with physical hardware.

It was included to demonstrate how a device-driver layer could be represented in the software architecture.

---

## 3. PulseCounter

Files:

```text
include/pulse_counter.h
src/pulse_counter.cpp
```

The `PulseCounter` maintains the pulse count used by the application.

Its main responsibilities are:

- Adding pulses.
- Maintaining the current count.
- Returning the pulse count.

The module is independently tested using:

```text
tests/test_pulse_counter.cpp
```

---

## 4. EnergyCalculator

Files:

```text
include/energy_calculator.h
src/energy_calculator.cpp
```

The `EnergyCalculator` converts pulse count into energy consumption.

The project uses a simulated conversion factor of:

```text
0.001 kWh per pulse
```

The calculation is:

```text
Energy = Pulse Count × 0.001
```

For example:

```text
300 pulses × 0.001
= 0.30 kWh
```

---

## 5. AnalyticsEngine

Files:

```text
include/analytics.h
src/analytics.cpp
```

The `AnalyticsEngine` stores energy readings and performs basic calculations.

It provides:

- Total energy calculation.
- Average energy calculation.

For example:

```text
Readings:

30
20
16

Total Energy = 66

Average Energy = 66 / 3
               = 22
```

The module is tested using:

```text
tests/test_analytics.cpp
```

---

## 6. DataLogger

Files:

```text
include/data_logger.h
src/data_logger.cpp
```

The `DataLogger` stores the pulse count and corresponding energy reading in:

```text
logs/meter.log
```

Example:

```text
300,0.3
```

Here:

```text
300 = pulse count
0.3 = energy in kWh
```

This allows meter readings to be retained locally.

---

# Energy Calculation

The project uses the following formula:

```text
Energy = Pulse Count × Conversion Factor
```

The conversion factor used in the simulation is:

```text
0.001 kWh/pulse
```

Therefore:

```text
Energy = Pulse Count × 0.001
```

### Example

For:

```text
Pulse Count = 300
```

the energy is:

```text
Energy = 300 × 0.001
       = 0.300 kWh
```

---

# Average Power Calculation

Average power is calculated using:

```text
Average Power = (Energy / Measurement Time) × 1000
```

The multiplication by 1000 converts kilowatts into watts.

### Example

For:

```text
Energy = 0.30 kWh
Time = 3 hours
```

the calculation is:

```text
Average Power = (0.30 / 3) × 1000
              = 100 W
```

---

# Electricity Cost Calculation

The project uses an assumed electricity rate of:

```text
₹8.00 per kWh
```

The estimated cost is calculated using:

```text
Estimated Cost = Energy × Electricity Rate
```

Example:

```text
Energy = 0.30 kWh
Rate = ₹8.00/kWh

Estimated Cost = 0.30 × 8
               = ₹2.40
```

> The ₹8/kWh rate is an assumed value for the software simulation and does not represent an actual electricity-board tariff.

---

# Usage Classification

The application classifies average power consumption into three levels.

| Average Power | Usage Status |
|---:|---|
| Below 500 W | NORMAL |
| 500 W to 1000 W | HIGH |
| Above 1000 W | VERY HIGH |

### Example

For:

```text
Pulse Count = 300
Measurement Time = 3 hours
```

we get:

```text
Energy = 0.30 kWh
Average Power = 100 W
```

Therefore:

```text
Usage Status = NORMAL
```

---

# Input Validation

Input validation was added to prevent invalid calculations.

## Invalid Pulse Count

The application rejects:

- Negative pulse counts.
- Non-numeric pulse input.

Example:

```text
Enter pulse count: -100
Invalid pulse count.
```

---

## Invalid Measurement Time

The application rejects:

- Zero measurement time.
- Negative measurement time.
- Non-numeric measurement time.

Example:

```text
Enter measurement time (hours): 0
Invalid measurement time.
```

This prevents division by zero and invalid power calculations.

---

# Project Structure

```text
smart_meter_pulse_analytics/
│
├── README.md
├── PRD.md
├── architecture.md
├── development_plan.md
│
├── data/
│   ├── meter_readings.csv
│   └── test_meter_readings.csv
│
├── docs/
│   ├── stage1_introduction.md
│   ├── stage2_requirements.md
│   ├── stage3_design.md
│   ├── stage4_prototype.md
│   ├── stage5_testing.md
│   └── stage6_final_report.md
│
├── include/
│   ├── analytics.h
│   ├── data_logger.h
│   ├── device_driver.h
│   ├── energy_calculator.h
│   ├── pulse_counter.h
│   └── pulse_generator.h
│
├── src/
│   ├── analytics.cpp
│   ├── data_logger.cpp
│   ├── device_driver.cpp
│   ├── energy_calculator.cpp
│   ├── main.cpp
│   ├── pulse_counter.cpp
│   └── pulse_generator.cpp
│
├── tests/
│   ├── test_analytics.cpp
│   ├── test_data_logger.cpp
│   ├── test_energy_calculator.cpp
│   └── test_pulse_counter.cpp
│
├── scripts/
│   └── run.sh
│
└── logs/
    └── meter.log
```

---

# Technologies Used

| Technology | Purpose |
|---|---|
| C++11 | Application development |
| Ubuntu Linux | Development environment |
| GNU g++ | Compilation |
| Bash | Build automation |
| Git | Version control |
| GitHub | Source-code hosting |

The project specifically uses **C++11**.

Compilation uses:

```text
-std=c++11
```

Compiler warnings are enabled using:

```text
-Wall -Wextra
```

---

# Requirements

Before running the project, the system should have:

- Ubuntu/Linux
- GNU g++
- C++11 support
- Bash
- Git

Check the compiler:

```bash
g++ --version
```

Check Git:

```bash
git --version
```

---

# Compilation

## Method 1 — Using the Build Script

The easiest method is:

```bash
./scripts/run.sh
```

The script builds:

```text
smart_meter
pulse_counter_test
energy_calculator_test
analytics_test
data_logger_test
```

The build uses:

```bash
g++ -Wall -Wextra -std=c++11
```

---

## Method 2 — Manual Compilation

The main application can also be compiled manually:

```bash
g++ -Wall -Wextra -std=c++11 src/main.cpp src/pulse_counter.cpp src/energy_calculator.cpp src/analytics.cpp src/data_logger.cpp src/pulse_generator.cpp src/device_driver.cpp -Iinclude -o smart_meter
```

---

# Running the Project

## Step 1 — Open the Project Directory

```bash
cd ~/Desktop/smart_meter_pulse_analytics
```

---

## Step 2 — Build the Project

```bash
./scripts/run.sh
```

Expected output:

```text
Building Smart Energy Meter...
Build completed successfully.
```

---

## Step 3 — Run the Smart Meter

```bash
./smart_meter
```

The program will ask:

```text
Enter pulse count:
Enter measurement time (hours):
```

Enter valid values.

For example:

```text
300
3
```

---

# Sample Execution

Example:

```text
========================================
          SMART ENERGY METER
========================================

Starting meter simulation...

Enter pulse count: 300
Enter measurement time (hours): 3

        ENERGY METER ANALYTICS

Pulse Count       : 300
Energy Used       : 0.30 kWh
Time Measured     : 3.00 hour
Average Power     : 100.00 W
Rate              : ₹8.00 / kWh
Estimated Cost    : ₹2.40
Usage Status      : NORMAL

Log File          : logs/meter.log
Reading Status    : SAVED

Meter Status      : RUNNING
```

---

# Testing

The project contains four dedicated module-level tests.

## 1. PulseCounter Test

Run:

```bash
./pulse_counter_test
```

Expected:

```text
PulseCounter test passed
```

---

## 2. EnergyCalculator Test

Run:

```bash
./energy_calculator_test
```

Expected:

```text
EnergyCalculator test passed
```

---

## 3. Analytics Test

Run:

```bash
./analytics_test
```

Current test result:

```text
Total Energy: 66
Average Energy: 22
```

---

## 4. DataLogger Test

Run:

```bash
./data_logger_test
```

Expected:

```text
DataLogger test passed
```

---

# Final Test Results

| Module | Test Result |
|---|---|
| PulseCounter | PASSED |
| EnergyCalculator | PASSED |
| AnalyticsEngine | PASSED |
| DataLogger | PASSED |

The complete project was successfully compiled using:

```text
C++11
-Wall
-Wextra
```

---

# Input Validation Testing

The application was also tested with invalid inputs.

### Test 1 — Negative Pulse Count

Input:

```text
-100
```

Result:

```text
Invalid pulse count.
```

### Test 2 — Zero Measurement Time

Input:

```text
200
0
```

Result:

```text
Invalid measurement time.
```

These tests confirm that invalid values are rejected before processing.

---

# Log File

Meter readings are stored in:

```text
logs/meter.log
```

To view the latest readings:

```bash
tail -n 5 logs/meter.log
```

Example:

```text
0,0
0,0
200,0.2
300,0.3
```

Each line represents:

```text
Pulse Count,Energy
```

For example:

```text
300,0.3
```

means:

```text
300 pulses
0.3 kWh
```

---

# Linux Concepts Demonstrated

The project demonstrates several Linux concepts.

### Terminal Navigation

```bash
cd
ls
```

### File Creation and Editing

```bash
nano
```

### Compilation

```bash
g++
```

### Executable Execution

```bash
./smart_meter
```

### Bash Scripting

```bash
./scripts/run.sh
```

### File Logging

The application writes meter readings to:

```text
logs/meter.log
```

### Git Version Control

The project uses Git for:

- Tracking changes.
- Creating commits.
- Maintaining project history.
- Pushing the project to GitHub.

---

# C++ Concepts Demonstrated

The project demonstrates:

- Classes and objects
- Object-oriented programming
- Encapsulation
- Private and public members
- Constructors
- Member functions
- Header files
- Source files
- Conditional statements
- Loops
- `std::vector`
- `std::string`
- Input/output streams
- Modular programming
- Separate compilation
- Function calls
- Basic file handling

---

# Object-Oriented Design

The project uses separate classes for different responsibilities.

```text
PulseGenerator
      |
      v
DeviceDriver
      |
      v
PulseCounter
      |
      v
EnergyCalculator
      |
      v
AnalyticsEngine
      |
      v
DataLogger
```

This separation makes the project easier to understand, test, and extend.

Each module performs a specific task instead of putting all functionality into one large file.

---

# Six-Stage Development Process

The project was developed in six stages.

## Stage 1 — Introduction

The first stage defined:

- Project title.
- Domain.
- Problem statement.
- Project objectives.
- Background.
- Expected outcome.

---

## Stage 2 — Requirements

The second stage identified:

- Functional requirements.
- Non-functional requirements.
- User inputs.
- System outputs.
- Energy calculations.
- Logging requirements.
- Testing requirements.

---

## Stage 3 — Design

The third stage defined the software architecture.

The system was divided into modules:

```text
PulseGenerator
DeviceDriver
PulseCounter
EnergyCalculator
AnalyticsEngine
DataLogger
```

The data flow and responsibilities of each module were also defined.

---

## Stage 4 — Prototype

The fourth stage implemented the working C++ prototype.

Implemented components include:

- PulseGenerator.
- DeviceDriver abstraction.
- PulseCounter.
- EnergyCalculator.
- AnalyticsEngine.
- DataLogger.
- Main application.
- Input validation.
- Bash build script.

---

## Stage 5 — Testing

The fifth stage focused on testing.

Individual tests were created for:

```text
PulseCounter
EnergyCalculator
AnalyticsEngine
DataLogger
```

The application was also tested with valid and invalid user inputs.

---

## Stage 6 — Final Report

The final stage documents:

- Completed implementation.
- System architecture.
- Module functionality.
- Testing results.
- Linux and C++ concepts.
- Limitations.
- Future improvements.
- Final conclusion.

---

# Limitations

The current implementation has some limitations.

### 1. Simulated Pulse Input

The project does not receive pulses from physical electricity-meter hardware.

### 2. User-Space Device Driver

The DeviceDriver is a software simulation and not a Linux kernel driver.

### 3. Assumed Conversion Factor

The project uses:

```text
0.001 kWh/pulse
```

as a simulated conversion factor.

A real meter would use its actual meter specification.

### 4. Assumed Electricity Tariff

The project uses:

```text
₹8/kWh
```

for cost estimation.

Actual electricity tariffs vary by provider, location, and consumption category.

### 5. Local Logging

The current system stores readings in a local text file instead of a database.

### 6. Basic Analytics

The AnalyticsEngine currently provides basic total and average energy calculations.

### 7. No Physical IoT Communication

The application does not communicate with external sensors, cloud platforms, or IoT devices.

---

# Future Improvements

The project can be extended in several ways.

## Hardware Integration

Connect the software to a real energy meter or pulse sensor.

## Real Device Driver

Develop a Linux kernel driver for communication with actual hardware.

## Database Storage

Replace the text log with a database such as SQLite or another storage system.

## Advanced Analytics

Add:

- Daily energy consumption.
- Weekly consumption.
- Monthly consumption.
- Peak usage detection.
- Historical comparisons.

## Real-Time Monitoring

Add continuous monitoring instead of one-time user input.

## Graphical Dashboard

Create a dashboard displaying:

```text
Energy Consumption
Average Power
Estimated Cost
Usage Status
Historical Readings
```

## IoT Integration

The system could eventually send energy readings to a remote server or cloud platform.

## Configurable Tariff

Allow the user to enter the electricity tariff instead of using a fixed value.

---

# Development Status

**Completed**

The current implementation successfully demonstrates:

- Simulated pulse generation.
- User-space device-driver abstraction.
- Pulse counting.
- Energy calculation.
- Average power calculation.
- Electricity cost estimation.
- Usage classification.
- Basic analytics.
- Data logging.
- Input validation.
- Module-level testing.
- Linux compilation.
- Bash build automation.
- Git version control.

---

# Repository

GitHub Repository:

**Smart Energy Smart-Meter Pulse Counter & Analytics Agent**

`https://github.com/N-Nischal/smart-meter-pulse-analytics`

---

# Author

## N. Nischal

**B.Tech Computer Science and Engineering**

**ITER, SOA University**

Project developed as part of Linux, C++, embedded systems, and system programming training.

---

# Conclusion

The **Smart Energy Smart-Meter Pulse Counter & Analytics Agent** successfully demonstrates the development of a modular smart-meter simulation using **C++11 and Linux**.

The system accepts simulated meter pulses and processes them through a structured software architecture consisting of the **PulseGenerator, DeviceDriver, PulseCounter, EnergyCalculator, AnalyticsEngine, and DataLogger**.

The application converts pulse readings into energy consumption, calculates average power, estimates electricity cost, determines the usage level, performs basic analytics, and stores readings in a local log file.

Input validation was implemented to prevent invalid pulse counts and measurement times. Separate tests were also created for the major modules, and all four module tests passed successfully.

The project also demonstrates practical Linux development concepts including terminal-based compilation, Bash scripting, file logging, executable generation, and Git/GitHub version control.

Although the current implementation is a software simulation and does not communicate with physical meter hardware or use a Linux kernel driver, the modular architecture provides a foundation that can be extended into a real embedded or IoT-based smart-energy monitoring system.

Overall, the project demonstrates how **C++ programming, Linux, modular architecture, testing, and basic IoT concepts** can be combined to create a practical smart-energy monitoring application.

---

## Final Project Summary

```text
                SMART ENERGY METER
                        |
                        v
                 PulseGenerator
                        |
                        v
                  DeviceDriver
                        |
                        v
                  PulseCounter
                        |
                        v
                EnergyCalculator
                        |
                        v
                 AnalyticsEngine
                        |
                        v
               Usage Classification
                        |
                        v
                   DataLogger
                        |
                        v
                  meter.log
```

**Technology:** C++11  
**Platform:** Ubuntu Linux  
**Compiler:** GNU g++  
**Build:** Bash  
**Testing:** C++ module-level tests  
**Version Control:** Git / GitHub  

**Project Status: Completed**
