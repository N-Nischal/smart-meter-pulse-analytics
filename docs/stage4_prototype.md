# Stage 4 – Prototype / Implementation

## 1. Implementation Overview

The Smart Energy Smart-Meter Pulse Counter & Analytics Agent was implemented as a modular **C++11 application on Ubuntu Linux**.

The prototype consists of separate classes for pulse generation, device abstraction, pulse counting, energy calculation, analytics and data logging.

---

## 2. Implemented Modules

### PulseGenerator

Generates the required number of virtual pulses.

```text
src/pulse_generator.cpp
include/pulse_generator.h
```

### DeviceDriver

Receives the generated pulses and maintains an internal pulse count.

```text
src/device_driver.cpp
include/device_driver.h
```

The DeviceDriver is a user-space simulation and not a Linux kernel driver.

### PulseCounter

Processes and maintains the meter pulse count.

```text
src/pulse_counter.cpp
include/pulse_counter.h
```

### EnergyCalculator

Converts the pulse count into energy consumption.

```text
src/energy_calculator.cpp
include/energy_calculator.h
```

### AnalyticsEngine

Stores energy readings and provides basic calculations such as total and average energy.

```text
src/analytics.cpp
include/analytics.h
```

### DataLogger

Stores meter readings in the log file.

```text
src/data_logger.cpp
include/data_logger.h
```

---

## 3. Main Program Flow

The main program follows this sequence:

```text
User Input
    ↓
Input Validation
    ↓
Pulse Generation
    ↓
DeviceDriver
    ↓
Pulse Counter
    ↓
Energy Calculation
    ↓
Power & Cost Calculation
    ↓
Usage Status
    ↓
Analytics
    ↓
Data Logger
    ↓
Console Output
```

---

## 4. Input Validation

The prototype checks user input before processing it.

Negative pulse counts are rejected:

```text
Invalid pulse count.
```

Zero or negative measurement time is rejected:

```text
Invalid measurement time.
```

This prevents invalid values from being used in the calculations.

---

## 5. Build Process

The project can be built using the provided Bash script:

```bash
./scripts/run.sh
```

The script compiles the application and individual test programs using:

```text
-Wall
-Wextra
-std=c++11
```

A successful build produces the required executable files.

---

## 6. Sample Prototype Execution

Example input:

```text
Enter pulse count: 300
Enter measurement time (hours): 3
```

Example output:

```text
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

## 7. Data Logging

After processing a valid reading, the system stores the pulse and energy values in:

```text
logs/meter.log
```

Example:

```text
300,0.3
```

This provides a simple record of the meter readings.

---

## 8. Prototype Status

The prototype successfully implements:

- Virtual pulse generation.
- User-space device abstraction.
- Pulse counting.
- Energy calculation.
- Average power calculation.
- Cost estimation.
- Usage classification.
- Input validation.
- Basic analytics.
- Data logging.
- Modular C++11 implementation.
- Linux build and execution.
- Unit-test programs.
