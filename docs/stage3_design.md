# Stage 3 – System Design

## 1. System Architecture

The Smart Energy Smart-Meter Pulse Counter & Analytics Agent follows a modular architecture.

```text
+----------------------+
|     User Input       |
| Pulse Count + Time   |
+----------+-----------+
           |
           v
+----------------------+
|   Pulse Generator    |
+----------+-----------+
           |
           v
+----------------------+
| Device Driver        |
|   Abstraction        |
+----------+-----------+
           |
           v
+----------------------+
|    Pulse Counter     |
+----------+-----------+
           |
           v
+----------------------+
|  Energy Calculator   |
+----------+-----------+
           |
           v
+----------------------+
|   Analytics Engine   |
+----------+-----------+
           |
           +---------> Usage Status
           |
           v
+----------------------+
|     Data Logger      |
+----------+-----------+
           |
           v
     logs/meter.log
```

---

## 2. Module Design

### Pulse Generator

Responsible for generating the required number of virtual pulses.

```text
PulseGenerator
      |
      +-- generatePulses()
```

### Device Driver

Provides a simple user-space abstraction for receiving and counting generated pulses.

```text
DeviceDriver
      |
      +-- handlePulse()
      +-- readPulseCount()
      +-- reset()
```

This is not a Linux kernel driver.

### Pulse Counter

Processes the pulse count received from the device layer.

```text
PulseCounter
      |
      +-- addPulse()
      +-- getPulseCount()
      +-- reset()
```

### Energy Calculator

Converts pulses into energy consumption.

```text
Energy = Pulses × 0.001 kWh
```

### Analytics Engine

Stores energy readings and calculates basic statistics such as total and average energy.

### Data Logger

Stores the processed readings in:

```text
logs/meter.log
```

---

## 3. Data Flow

The complete data flow is:

```text
User enters pulse count
          |
          v
Input validation
          |
          v
Virtual pulse generation
          |
          v
DeviceDriver receives pulses
          |
          v
PulseCounter processes pulses
          |
          v
Energy calculation
          |
          v
Power and cost calculation
          |
          v
Usage classification
          |
          v
Analytics
          |
          v
Data logging
          |
          v
Display result
```

---

## 4. Main Calculations

### Energy

```text
Energy (kWh) = Pulse Count × 0.001
```

### Average Power

```text
Average Power (W) =
(Energy / Measurement Time) × 1000
```

### Estimated Cost

```text
Cost = Energy × ₹8.00
```

### Usage Status

```text
Below 500 W       → NORMAL
500–1000 W        → HIGH
Above 1000 W      → VERY HIGH
```

---

## 5. Project Structure

```text
smart_meter_pulse_analytics/
|
├── include/
│   ├── analytics.h
│   ├── data_logger.h
│   ├── device_driver.h
│   ├── energy_calculator.h
│   ├── pulse_counter.h
│   └── pulse_generator.h
|
├── src/
│   ├── analytics.cpp
│   ├── data_logger.cpp
│   ├── device_driver.cpp
│   ├── energy_calculator.cpp
│   ├── main.cpp
│   ├── pulse_counter.cpp
│   └── pulse_generator.cpp
|
├── tests/
│   ├── test_analytics.cpp
│   ├── test_data_logger.cpp
│   ├── test_energy_calculator.cpp
│   └── test_pulse_counter.cpp
|
├── data/
├── docs/
├── logs/
├── scripts/
└── README.md
```

---

## 6. Design Approach

The project uses a modular object-oriented design.

Each major function is separated into its own class and source file. Header files contain class declarations, while source files contain their implementations.

This approach makes the project:

- Easier to understand.
- Easier to test.
- Easier to maintain.
- Easier to extend.

The application is implemented using **C++11** and follows a Linux-based development approach.
