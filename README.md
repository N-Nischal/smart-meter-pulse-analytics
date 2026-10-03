# Smart Energy Smart-Meter Pulse Counter & Analytics Agent

A C++11-based smart-meter simulation that converts virtual meter pulses into energy consumption data, calculates average power and estimated electricity cost, classifies usage, and stores meter readings in a log file.

This project was developed as an individual Linux/C++ training project under the **IoT, Embedded & Virtual Sensors** domain.

---

## 📌 Project Overview

Traditional energy meters measure electricity consumption continuously. In this project, meter pulses are used as a **virtual sensor input** to simulate electricity consumption.

The system processes the pulse count and measurement time to generate useful energy analytics.

### Basic Flow

```text
Virtual Meter Pulse Input
          ↓
     Pulse Counter
          ↓
   Energy Calculator
          ↓
    Analytics Engine
       ↙        ↘
 Data Logger    Usage Analysis
       ↓
   Meter Results
```

The application runs completely in user space on Linux and demonstrates concepts related to:

- IoT and virtual sensors
- Embedded-system style data processing
- C++ modular programming
- Linux system development
- Data logging
- Software testing
- Git/GitHub-based development

---

## 🎯 Objectives

The main objectives of the project are:

- Simulate smart-meter pulse readings.
- Convert pulses into electrical energy consumption.
- Calculate average power consumption.
- Estimate electricity cost.
- Classify energy usage as `NORMAL` or `HIGH`.
- Store readings for later analysis.
- Develop the project using modular C++ components.
- Implement and test individual software modules.
- Maintain the project using Git and GitHub.

---

## ✨ Features

- Virtual pulse-based meter input
- Pulse counting and processing
- Energy calculation in kWh
- Average power calculation in watts
- Electricity cost estimation
- Usage-status classification
- Persistent meter logging
- Modular C++ architecture
- Unit testing for individual modules
- Integrated smart-meter application
- Linux command-line execution
- Automated build script
- Git/GitHub version control

---

## ⚙️ Energy Calculation

The project uses a conversion factor of:

```text
1 pulse = 0.001 kWh
```

Therefore:

```text
Energy (kWh) = Pulse Count × 0.001
```

Average power is calculated from energy and measurement time:

```text
Average Power (W) = (Energy (kWh) / Time (hours)) × 1000
```

The simulated electricity tariff used by the application is:

```text
₹8.00 per kWh
```

Estimated cost:

```text
Estimated Cost = Energy (kWh) × ₹8.00
```

---

## 🏗️ System Architecture

The application is divided into independent modules.

### 1. Pulse Counter

Responsible for receiving and processing the meter pulse count.

**Files:**

```text
include/pulse_counter.h
src/pulse_counter.cpp
```

### 2. Energy Calculator

Converts pulse readings into energy consumption.

**Files:**

```text
include/energy_calculator.h
src/energy_calculator.cpp
```

### 3. Analytics Engine

Stores energy readings and calculates analytical values such as total and average energy.

**Files:**

```text
include/analytics.h
src/analytics.cpp
```

### 4. Data Logger

Stores meter readings in a log file for persistence and later inspection.

**Files:**

```text
include/data_logger.h
src/data_logger.cpp
```

### 5. Main Application

Integrates all modules and provides the command-line interface.

**File:**

```text
src/main.cpp
```

---

## 📂 Project Structure

```text
smart-meter-pulse-analytics/
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
├── docs/
│   ├── stage1_introduction.md
│   ├── stage2_requirements.md
│   ├── stage3_design.md
│   ├── stage4_prototype.md
│   ├── stage5_testing.md
│   └── stage6_final_report.md
│
├── requirements/
│   └── functional_requirements.md
│
├── scripts/
│   └── run.sh
│
├── data/
├── logs/
├── PRD.md
├── architecture.md
├── development_plan.md
├── requirements.md
├── notes.md
├── README.md
└── .gitignore
```

---

## 🛠️ Technologies Used

| Technology | Purpose |
|---|---|
| C++11 | Application development |
| Linux/Ubuntu | Development and execution environment |
| GCC/G++ | Compilation |
| Bash | Build automation |
| Git | Version control |
| GitHub | Source-code hosting |
| CSV/Text Logging | Meter data storage |

---

## 💻 Requirements

To build and run the project, you need:

- Linux/Ubuntu
- GCC/G++
- C++11 support
- Git
- Terminal

Check the compiler:

```bash
g++ --version
```

---

## 🚀 Build the Project

Clone the repository:

```bash
git clone https://github.com/N-Nischal/smart-meter-pulse-analytics.git
```

Enter the project directory:

```bash
cd smart-meter-pulse-analytics
```

Make the build script executable:

```bash
chmod +x scripts/run.sh
```

Build all application and test executables:

```bash
./scripts/run.sh
```

A successful build displays:

```text
Build completed successfully.
```

---

## ▶️ Run the Smart Meter

After building:

```bash
./smart_meter
```

The program asks for:

```text
Enter pulse count:
Enter measurement time (hours):
```

It then displays the calculated energy consumption, average power, estimated cost, usage status, and logging status.

---

## 🧪 Testing

The project contains separate tests for the major modules.

### Pulse Counter

```bash
./pulse_counter_test
```

Expected result:

```text
PulseCounter test passed
```

### Energy Calculator

```bash
./energy_calculator_test
```

Expected result:

```text
EnergyCalculator test passed
```

### Analytics Engine

```bash
./analytics_test
```

Example result:

```text
Total Energy: 46
Average Energy: 15.3333
```

### Data Logger

```bash
./data_logger_test
```

Expected result:

```text
DataLogger test passed
```

---

## 📊 Example Execution

Example input:

```text
Enter pulse count: 300
Enter measurement time (hours): 2
```

Example output:

```text
========================================
          SMART ENERGY METER
========================================

Starting meter simulation...

        ENERGY METER ANALYTICS

Pulse Count       : 300
Energy Used       : 0.30 kWh
Time Measured     : 2.00 hour
Average Power     : 150.00 W
Rate              : ₹8.00 / kWh
Estimated Cost    : ₹2.40
Usage Status      : NORMAL

Log File          : logs/meter.log
Reading Status    : SAVED

Meter Status      : RUNNING
```

The corresponding logged reading is stored in:

```text
logs/meter.log
```

Example:

```text
300,0.3
```

---

## 📝 Data Logging

The Data Logger stores pulse and energy information in a log file.

Example:

```text
3000,3
900,0.9
600,0.6
300,0.3
```

This provides a simple persistent record of meter readings and can be used as input for future analytics.

---

## 🌐 IoT & Virtual Sensor Relevance

Although this project does not use physical meter hardware, it demonstrates the software-processing portion of a smart-meter system.

The pulse count acts as a **virtual sensor input**.

A real-world implementation could replace the simulated input with data received from:

- A physical energy meter
- Microcontroller GPIO input
- Pulse-output energy sensor
- Serial communication
- UART
- SPI/I²C-connected hardware
- Network or IoT communication

The existing processing pipeline could then be extended to handle real sensor data.

---

## 🐧 Linux & System Programming Concepts

The project is developed and executed on Linux and demonstrates practical use of:

- Linux terminal
- GCC/G++ compilation
- Bash scripting
- File handling
- Directory and file management
- Executable permissions
- Modular C++ compilation
- Test execution
- Git version control

The current implementation is a **user-space application** and does not contain a custom Linux kernel device driver.

---

## 🔄 Development Process

The project was developed incrementally through multiple stages.

### Stage 1 — Project Introduction

Defined:

- Problem statement
- Project objective
- Scope
- Expected outcome
- Application area

### Stage 2 — Requirements

Defined:

- Functional requirements
- Non-functional requirements
- Modules
- Features
- Development plan
- Project deliverables

### Stage 3 — Design & Architecture

Defined:

- System architecture
- Module responsibilities
- Data flow
- Data structures
- Development environment
- Implementation strategy

### Stage 4 — Prototype

Implemented:

- Pulse Counter
- Energy Calculator
- Analytics Engine
- Data Logger
- Main smart-meter application

### Stage 5 — Testing

Performed:

- Unit testing
- Module testing
- Integration testing
- Debugging
- Output verification

### Stage 6 — Final Implementation

Completed:

- Integrated application
- Testing documentation
- Final report
- Project repository
- Build script
- Final demonstration

---

## 📈 Current Project Status

The current implementation has been successfully built and tested.

### Verification

```text
Clean Build              PASS
Pulse Counter Test       PASS
Energy Calculator Test   PASS
Analytics Test           PASS
Data Logger Test         PASS
Full Application Demo    PASS
Data Logging             PASS
Git Repository           CLEAN
```

The project successfully accepts meter pulse input, calculates energy and power values, estimates cost, classifies usage, and stores the reading.

---

## ⚠️ Current Limitations

The current version has several limitations:

- Uses simulated pulse input instead of a physical energy meter.
- Uses a fixed energy-per-pulse conversion factor.
- Uses a fixed electricity tariff.
- Uses simple usage classification.
- Does not provide a graphical user interface.
- Does not transmit data to a cloud or remote IoT platform.
- Does not implement a physical sensor interface or kernel device driver.

---

## 🔮 Future Enhancements

Possible future improvements include:

- Integration with a physical energy meter
- Real-time pulse acquisition
- Configurable tariff rates
- Daily/monthly energy reports
- Historical data visualization
- Database-based storage
- IoT/cloud connectivity
- Remote monitoring
- Alert generation for abnormal consumption
- Microcontroller-based implementation
- Hardware sensor integration
- More advanced energy-consumption analytics

---

## 📚 Documentation

Detailed project documentation is available in the `docs/` directory:

```text
docs/
├── stage1_introduction.md
├── stage2_requirements.md
├── stage3_design.md
├── stage4_prototype.md
├── stage5_testing.md
└── stage6_final_report.md
```

Additional project documents:

```text
PRD.md
architecture.md
development_plan.md
requirements.md
requirements/functional_requirements.md
```

---

## 🔀 Git & Version Control

Git was used throughout the project to maintain development history.

The repository contains separate commits for major development stages, including:

- Initial project setup
- Requirements
- Analytics implementation
- Prototype integration
- Documentation
- Testing
- Final report
- Build-script restoration

The project is maintained on GitHub:

**Repository:**  
https://github.com/N-Nischal/smart-meter-pulse-analytics

---

## 👨‍💻 Author

**N. Nischal**

B.Tech Computer Science & Engineering

ITER, SOA University

---

## 📌 Project Summary

The **Smart Energy Smart-Meter Pulse Counter & Analytics Agent** demonstrates how meter pulse data can be processed using a modular C++ application on Linux.

The system converts virtual pulse readings into energy consumption, calculates power and estimated cost, analyzes usage, and records readings for future use.

The project combines concepts from:

**C++ + Linux + IoT + Virtual Sensors + Data Logging + Software Testing + Git/GitHub**

and provides a foundation that can later be extended from a software simulation into a hardware-connected smart-meter system.
