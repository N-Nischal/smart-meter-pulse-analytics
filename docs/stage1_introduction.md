# Stage 1 – Introduction

## 1. Project Title

**Smart Energy Smart-Meter Pulse Counter & Analytics Agent**

---

## 2. Domain

**IoT, Embedded Systems, Virtual Sensors, Linux and System Programming**

This project is a Linux-based C++11 application that simulates the basic operation of a smart electricity meter using virtual pulse readings.

The system is designed to demonstrate how pulse-based energy measurements can be processed, converted into energy consumption, analyzed and stored using C++ on a Linux platform.

---

## 3. Project Overview

A smart electricity meter continuously measures electricity consumption and records the amount of energy used.

In this project, a real electricity meter is replaced by a software-based simulation. The user provides a pulse count and measurement time. The application processes these values and generates an energy consumption report.

The system performs the following operations:

1. Generates virtual meter pulses.
2. Processes the pulses using a user-space device-driver abstraction.
3. Counts the generated pulses.
4. Converts pulses into energy consumption.
5. Calculates average power.
6. Estimates electricity cost.
7. Determines the usage status.
8. Stores the reading in a log file.
9. Validates invalid user input.
10. Provides a Linux-based command-line interface.

The project is implemented using **C++11** and developed on **Ubuntu Linux**.

---

## 4. Problem Statement

Traditional electricity meters measure energy consumption using physical hardware. Understanding how such a system works internally requires knowledge of sensors, pulse generation, data processing, embedded software and system-level programming.

The objective of this project is to create a simplified software simulation of a smart energy meter so that the complete measurement and processing flow can be demonstrated without requiring physical meter hardware.

The system should accept virtual pulse measurements, calculate energy consumption, analyze the result and store the data for future reference.

---

## 5. Objectives

The main objectives of the project are:

- To develop a smart-meter simulation using C++.
- To work with C++ on the Linux operating system.
- To simulate meter pulses using software.
- To demonstrate a simple user-space device-driver abstraction.
- To count and process meter pulses.
- To convert pulse readings into energy consumption.
- To calculate average power.
- To estimate electricity cost using an assumed tariff.
- To classify electricity usage.
- To validate user input.
- To store meter readings in a log file.
- To demonstrate modular C++ programming.
- To apply object-oriented programming concepts.
- To demonstrate Linux compilation, execution and shell scripting.
- To perform unit testing of individual modules.
- To maintain the project using Git and GitHub.

---

## 6. System Concept

The basic working concept of the system is:

```text
User Input
    |
    v
Pulse Generator
    |
    v
Device Driver Abstraction
    |
    v
Pulse Counter
    |
    v
Energy Calculator
    |
    v
Analytics Engine
    |
    +----> Usage Status
    |
    v
Data Logger
    |
    v
Log File
```

The user enters the number of pulses and the measurement time.

The Pulse Generator creates the corresponding virtual pulses. The Device Driver abstraction receives these pulses and maintains a pulse count.

The Pulse Counter then processes the generated pulse count. The Energy Calculator converts the pulse count into energy consumption.

The Analytics Engine stores and analyzes energy readings. The system also calculates average power and estimated cost.

Finally, the Data Logger stores the reading in:

```text
logs/meter.log
```

---

## 7. Virtual Pulse Concept

A real electricity meter may produce electrical pulses corresponding to energy consumption.

For this project, the physical pulse signal is simulated using software.

The project uses the following assumed conversion:

```text
1 pulse = 0.001 kWh
```

Therefore:

```text
Energy = Pulse Count × 0.001
```

For example:

```text
300 pulses × 0.001
= 0.300 kWh
```

This conversion factor is a project simulation assumption and does not represent a universal physical meter specification.

---

## 8. Energy and Power Calculation

The system calculates energy consumption using:

```text
Energy (kWh) = Pulse Count × Conversion Factor
```

where:

```text
Conversion Factor = 0.001 kWh/pulse
```

Average power is calculated using:

```text
Average Power (W) =
(Energy (kWh) / Time (hours)) × 1000
```

For example, if the meter records:

```text
Pulse Count = 300
Time = 3 hours
```

Then:

```text
Energy = 300 × 0.001
       = 0.30 kWh

Average Power = (0.30 / 3) × 1000
              = 100 W
```

---

## 9. Electricity Cost

The project uses an assumed electricity tariff of:

```text
₹8.00 per kWh
```

The estimated cost is calculated as:

```text
Estimated Cost = Energy × Electricity Rate
```

For example:

```text
Energy = 0.30 kWh
Rate = ₹8.00/kWh

Cost = 0.30 × 8
     = ₹2.40
```

The tariff is used only for simulation and demonstration.

---

## 10. Usage Classification

The system determines the usage status based on average power.

The current classification is:

```text
Average Power < 500 W
        |
        +---- NORMAL

500 W to 1000 W
        |
        +---- HIGH

Above 1000 W
        |
        +---- VERY HIGH
```

This classification is a project-defined rule for demonstration.

---

## 11. Main Modules

### 11.1 Pulse Generator

The `PulseGenerator` class creates virtual meter pulses.

File:

```text
include/pulse_generator.h
src/pulse_generator.cpp
```

It repeatedly sends pulses to the Device Driver abstraction.

---

### 11.2 Device Driver Abstraction

The `DeviceDriver` class represents a simplified user-space interface between the virtual pulse source and the application.

File:

```text
include/device_driver.h
src/device_driver.cpp
```

It provides functions to:

- Receive a pulse.
- Maintain the pulse count.
- Read the pulse count.
- Reset the pulse count.

This is **not a Linux kernel device driver**. It is a simple user-space abstraction created to demonstrate the concept of a device interface.

---

### 11.3 Pulse Counter

The `PulseCounter` class manages the pulse count used by the application.

Files:

```text
include/pulse_counter.h
src/pulse_counter.cpp
```

---

### 11.4 Energy Calculator

The `EnergyCalculator` class converts pulse readings into energy consumption.

Files:

```text
include/energy_calculator.h
src/energy_calculator.cpp
```

---

### 11.5 Analytics Engine

The `AnalyticsEngine` stores energy readings and provides basic analytics such as total and average energy.

Files:

```text
include/analytics.h
src/analytics.cpp
```

---

### 11.6 Data Logger

The `DataLogger` stores meter readings in a log file.

Files:

```text
include/data_logger.h
src/data_logger.cpp
```

Log location:

```text
logs/meter.log
```

---

## 12. Technologies Used

| Technology | Purpose |
|---|---|
| C++11 | Main programming language |
| Ubuntu Linux | Development and execution platform |
| g++ | C++ compiler |
| Bash | Build/run automation |
| Git | Version control |
| GitHub | Source-code repository |
| File I/O | Meter data logging |
| C++ Classes | Modular software design |

---

## 13. Linux Concepts Demonstrated

The project demonstrates several Linux concepts:

- Working with the Linux terminal.
- Directory and file management.
- Compiling C++ programs using `g++`.
- Executing Linux binaries.
- Bash scripting.
- File permissions.
- File-based logging.
- Git version control.
- Building multiple source files.
- Using compiler warning options.

The build process uses:

```text
-Wall
-Wextra
-std=c++11
```

---

## 14. C++ Concepts Demonstrated

The project demonstrates:

- Classes and objects.
- Constructors.
- Private and public members.
- Function declarations and definitions.
- Header files.
- Source files.
- Encapsulation.
- Modular programming.
- `std::vector`.
- File handling.
- Input validation.
- Conditional statements.
- Loops.
- Arithmetic calculations.
- Unit testing.

---

## 15. Project Scope

The project focuses on software simulation rather than physical hardware implementation.

The current scope includes:

- Virtual pulse generation.
- Pulse counting.
- Energy calculation.
- Power calculation.
- Cost estimation.
- Usage classification.
- Basic analytics.
- Data logging.
- Input validation.
- Unit testing.
- Linux-based development.

The project does not currently include:

- A physical electricity meter.
- A physical energy sensor.
- A microcontroller.
- A real Linux kernel device driver.
- Real-time electrical measurement.
- Actual electricity-board tariff integration.
- Cloud connectivity.

---

## 16. Expected Outcome

At the end of the project, the application should provide a complete simulated smart-meter workflow.

For example:

```text
Input:
Pulse Count = 300
Measurement Time = 3 hours

Output:
Energy Used = 0.30 kWh
Average Power = 100 W
Estimated Cost = ₹2.40
Usage Status = NORMAL
Reading Status = SAVED
Meter Status = RUNNING
```

The corresponding reading is also stored in the meter log.

---

## 17. Development Approach

The project is developed in six stages:

```text
Stage 1 → Introduction
Stage 2 → Requirements
Stage 3 → System Design
Stage 4 → Prototype / Implementation
Stage 5 → Testing
Stage 6 → Final Report
```

Each stage documents a different part of the development process.

---

## 18. Conclusion

Stage 1 establishes the purpose and scope of the Smart Energy Smart-Meter Pulse Counter & Analytics Agent.

The project provides a software-based simulation of a smart electricity meter using C++11 on Linux. It combines virtual pulse generation, pulse processing, energy calculation, analytics, cost estimation and file-based logging.

The project also provides practical experience with Linux system programming concepts, modular C++ development, Bash scripting, testing and Git-based project management.

The following stages will define the detailed requirements, architecture, implementation, testing process and final results of the system.

---

**Author:** N. Nischal  
**Course:** B.Tech Computer Science and Engineering  
**Institute:** ITER, SOA University  
**Project:** Smart Energy Smart-Meter Pulse Counter & Analytics Agent
