# ble-lid-monitor

Simple proof of concept project that reports if a lid is openened and reports status over bluetooth.

## Hardware
### Board
Adafruit feather 32u4 Bluefruit LE board
- ATMega 32u4 microcontroller
- Bluefruit BTLE module

### Wiring
GPIO pin 5 connected to 3.3V via a 10kOhm pull-up resistor and to ground via a circuit breaker (will add schematic)

## Compilation and flash

This code is made for the Adafruit feather 32u4 Bluefruit LE and the easiest way to get started is to compile and flash using Arduino sketch.

## External software

This code uses pre-made libraries from Adafruit.
