# Stage 5 – Testing

## 1. Testing Overview

Testing was performed to verify that the Smart Energy Smart-Meter Pulse Counter & Analytics Agent works correctly and handles invalid input safely.

The project was compiled using **C++11** with:

```text
-Wall -Wextra
```

---

## 2. Unit Testing

The individual project modules were tested using separate test programs.

| Test | Result |
|---|---|
| PulseCounter | PASS |
| EnergyCalculator | PASS |
| AnalyticsEngine | PASS |
| DataLogger | PASS |

### Test Commands

```bash
./pulse_counter_test
./energy_calculator_test
./analytics_test
./data_logger_test
```

The tests completed successfully.

---

## 3. Valid Input Testing

A valid meter reading was tested using:

```text
Pulse Count = 300
Measurement Time = 3 hours
```

Expected calculations:

```text
Energy = 300 × 0.001
       = 0.30 kWh

Average Power = (0.30 / 3) × 1000
              = 100 W

Estimated Cost = 0.30 × ₹8
               = ₹2.40
```

The application produced the expected results:

```text
Energy Used       : 0.30 kWh
Average Power     : 100.00 W
Estimated Cost    : ₹2.40
Usage Status      : NORMAL
Reading Status    : SAVED
```

**Result: PASS**

---

## 4. Invalid Input Testing

### Negative Pulse Count

Input:

```text
-100
```

Output:

```text
Invalid pulse count.
```

**Result: PASS**

### Zero Measurement Time

Input:

```text
Pulse Count = 200
Measurement Time = 0
```

Output:

```text
Invalid measurement time.
```

**Result: PASS**

---

## 5. Build Testing

The complete project was built using:

```bash
./scripts/run.sh
```

The build completed successfully without compilation errors.

The project uses:

```text
C++11
-Wall
-Wextra
```

**Result: PASS**

---

## 6. Log File Testing

After a successful reading, the application stores the result in:

```text
logs/meter.log
```

Example entry:

```text
300,0.3
```

The log file was verified after execution.

**Result: PASS**

---

## 7. Testing Summary

All major functional tests completed successfully.

```text
+---------------------------+--------+
| Test                      | Result |
+---------------------------+--------+
| PulseCounter              | PASS   |
| EnergyCalculator          | PASS   |
| AnalyticsEngine           | PASS   |
| DataLogger                | PASS   |
| Valid Input               | PASS   |
| Invalid Pulse Input       | PASS   |
| Invalid Time Input        | PASS   |
| Build Verification        | PASS   |
| Log File Verification     | PASS   |
+---------------------------+--------+
```

The testing stage confirms that the current prototype performs the required calculations, validates user input and stores meter readings correctly.
