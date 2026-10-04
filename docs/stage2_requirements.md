# Stage 2 – Requirements

## 1. Introduction

This stage defines the main functional and non-functional requirements of the **Smart Energy Smart-Meter Pulse Counter & Analytics Agent**.

The system is a Linux-based C++11 application that simulates smart-meter pulse processing and energy analysis.

---

## 2. Functional Requirements

The system shall:

- Accept pulse count and measurement time from the user.
- Validate user input.
- Generate virtual meter pulses.
- Process pulses using a user-space `DeviceDriver` abstraction.
- Count the generated pulses.
- Convert pulses into energy consumption.
- Calculate average power.
- Estimate electricity cost.
- Determine electricity usage status.
- Store readings in `logs/meter.log`.
- Display the processed meter information.
- Support testing of individual modules.

### Energy Calculation

The project uses the simulated conversion:

```text
1 pulse = 0.001 kWh
```

Therefore:

```text
Energy = Pulse Count × 0.001
```

### Average Power

```text
Average Power (W) =
(Energy / Time) × 1000
```

### Cost Calculation

The assumed electricity rate is:

```text
₹8.00/kWh
```

Therefore:

```text
Estimated Cost = Energy × ₹8.00
```

---

## 3. Input Requirements

The application requires two main inputs:

| Input | Type | Validation |
|---|---|---|
| Pulse Count | Integer | Must be 0 or greater |
| Measurement Time | Decimal | Must be greater than 0 |

Example:

```text
Enter pulse count: 300
Enter measurement time (hours): 3
```

Invalid inputs such as negative pulse counts or zero/negative measurement time must be rejected.

---

## 4. Output Requirements

For valid input, the application should display:

```text
Pulse Count
Energy Used
Time Measured
Average Power
Rate
Estimated Cost
Usage Status
Log File
Reading Status
Meter Status
```

Example:

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

## 5. Non-Functional Requirements

### Platform
- Ubuntu/Linux environment.

### Programming Language
- C++11.

### Compiler
- `g++`

### Build
- Bash build script using `-Wall -Wextra`.

### Maintainability
- Modular header and source files.
- Separate test files for major components.

### Reliability
- Invalid input should be handled without crashing the application.

---

## 6. Project Constraints

The project has the following constraints:

- The electricity meter is simulated using software.
- No physical electricity meter or sensor is connected.
- The `DeviceDriver` is a user-space abstraction, not a Linux kernel driver.
- The pulse conversion factor is an assumed project value.
- The electricity tariff is an assumed value.
- The application currently uses a command-line interface.

---

## 7. Acceptance Criteria

The requirements are considered satisfied when:

- The program compiles successfully using C++11.
- Valid inputs produce correct calculations.
- Invalid inputs are rejected.
- Virtual pulses are generated and processed.
- Energy, power and cost are calculated correctly.
- Usage status is displayed.
- Readings are stored in the log file.
- Individual modules pass their tests.
