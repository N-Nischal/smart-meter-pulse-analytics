# Stage 3 – System Design and Architecture

## 1. Stage Objective

The objective of Stage 3 is to define the architecture, modules, data flow, and implementation structure of the Smart Energy Smart-Meter Pulse Counter & Analytics Agent.

The design will provide a clear structure for implementing and testing the system in Stage 4.

## 2. Overall System Architecture

The system will use a modular architecture.

The planned data flow is:

Simulated Smart Meter / Pulse Generator  
↓  
Pulse Counter  
↓  
Energy Calculator  
↓  
Data Logger  
↓  
Analytics Engine  
↓  
Terminal Interface

The simulated smart meter will provide pulse data to the application. The pulse counter will maintain the total number of pulses. The energy calculator will convert pulses into energy consumption. The data logger will store readings, while the analytics engine will calculate useful consumption statistics. The terminal interface will display the results to the user.

## 3. System Modules

### 3.1 Pulse Input / Generator

**Responsibility:**

- Generate or accept simulated smart-meter pulses.
- Provide pulse input to the pulse counter.
- Validate basic pulse input values.

This module represents the virtual meter input because the initial project will not use a physical electricity meter.

### 3.2 Pulse Counter

**Responsibility:**

- Receive valid pulses.
- Maintain the total pulse count.
- Provide the current pulse count to other modules.

### 3.3 Energy Calculator

**Responsibility:**

- Convert pulse count into energy consumption.
- Use a configurable pulse-to-energy conversion factor.
- Provide calculated energy values.

For the initial prototype, the conversion factor will be configurable so that it can be changed without redesigning the complete system.

### 3.4 Data Logger

**Responsibility:**

- Record meter readings.
- Store timestamp, pulse count, and energy information.
- Write readings to a persistent data file.
- Report file-access errors.

### 3.5 Analytics Engine

**Responsibility:**

- Read stored meter data.
- Calculate basic consumption statistics.
- Determine total, average, and peak consumption.
- Provide results to the terminal interface.

### 3.6 Terminal Interface

**Responsibility:**

- Provide a simple user interface through the Linux terminal.
- Display pulse count and energy information.
- Display analytics results.
- Provide controlled start and stop operations.

## 4. Data Flow

The system will process meter information in the following sequence:

1. The simulated meter generates a pulse.
2. The pulse counter receives the pulse.
3. The pulse counter updates the total pulse count.
4. The energy calculator converts the pulse count into energy.
5. The data logger stores the meter reading.
6. The analytics engine processes stored readings.
7. The terminal interface displays the results.

## 5. Main Data Structure

The system will use a meter-reading data structure to represent one recorded reading.

The planned structure will contain:

- Timestamp
- Pulse count
- Energy in Wh

A collection of meter readings will be used for analytics and data processing.

## 6. Module Relationships

The planned relationships between modules are:

- The Pulse Input provides data to the Pulse Counter.
- The Pulse Counter provides pulse information to the Energy Calculator.
- The Energy Calculator provides calculated energy information to the Data Logger.
- The Data Logger stores meter readings.
- The Analytics Engine processes stored readings.
-
## 14. UML Class Diagram

The planned class structure of the system consists of four main classes:

```text
+----------------------+
|     PulseCounter     |
+----------------------+
| - pulseCount         |
+----------------------+
| + addPulse()         |
| + getPulseCount()    |
+----------+-----------+
           |
           v
+----------------------+
|   EnergyCalculator   |
+----------------------+
| - conversionFactor  |
+----------------------+
| + calculateEnergy()  |
+----------+-----------+
           |
           v
+----------------------+
|      DataLogger      |
+----------------------+
| - filename           |
+----------------------+
| + logReading()       |
+----------+-----------+
           |
           v
+----------------------+
|   AnalyticsEngine    |
+----------------------+
|                     |
+----------------------+
| + calculateTotal()   |
| + calculateAverage() |
| + calculatePeak()    |
+----------------------+

```

### PulseCounter

Stores and updates the total number of pulses received from the simulated meter.

### EnergyCalculator

Uses the configured conversion factor to convert pulse information into energy consumption.

### DataLogger

Stores timestamp, pulse count, and calculated energy in the meter-reading data file.

### AnalyticsEngine

Processes stored readings and calculates basic consumption statistics.

The class design will be implemented and tested during Stage 4 and Stage 5.

## 15. UML Sequence Diagram

The planned sequence of interaction is:

```text
User
 |
 | Start monitoring
 v
Terminal Interface
 |
 | Generate/receive pulse
 v
Pulse Counter
 |
 | Pulse count
 v
Energy Calculator
 |
 | Energy value
 v
Data Logger
 |
 | Store reading
 v
Meter Data File
 |
 | Read stored data
 v
Analytics Engine
 |
 | Analysis results
 v
Terminal Interface
 |
 | Display results
 v
User
```

This sequence represents the normal flow of information through the system.

## 16. UML State Machine

The monitoring process will use the following logical states:

```text
+-------+
| Start |
+---+---+
    |
    v
+----------------+
| Initialization |
+-------+--------+
        |
        v
+----------------+
| Waiting for    |
| Pulse          |
+-------+--------+
        |
        v
+----------------+
| Count Pulse    |
+-------+--------+
        |
        v
+----------------+
| Calculate      |
| Energy         |
+-------+--------+
        |
        v
+----------------+
| Log Reading    |
+-------+--------+
        |
        v
+----------------+
| Display Data   |
+-------+--------+
        |
        +-------> Waiting for Pulse
        |
        v
+-------+
| Stop  |
+-------+
```

The state machine describes the planned operational behavior of the monitoring application.
