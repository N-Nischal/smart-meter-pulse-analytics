# Functional Requirements

## FR-01 – Pulse Input

The system shall accept simulated smart-meter pulses as input.

## FR-02 – Pulse Counting

The system shall count each valid incoming pulse and maintain the total pulse count.

## FR-03 – Energy Conversion

The system shall convert the pulse count into electrical energy using a configurable pulse-to-energy conversion factor.

## FR-04 – Data Logging

The system shall record meter readings including timestamp, pulse count, and calculated energy.

## FR-05 – Data Storage

The system shall store collected meter readings in a persistent file for later analysis.

## FR-06 – Energy Analytics

The system shall calculate basic statistics such as total energy consumption, average consumption, and peak consumption.

## FR-07 – Data Display

The system shall display relevant meter and energy information through the terminal interface.

## FR-08 – Input Validation

The system shall validate input data and handle invalid values without terminating unexpectedly.

## FR-09 – File Error Handling

The system shall detect and report errors when meter data cannot be read from or written to the required file.

## FR-10 – System Control

The system shall provide a controlled method to start and stop the monitoring process.
