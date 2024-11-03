# Robotic Car with Bluetooth Control and Servo Arm

This project is a Bluetooth-controlled robotic car with an electronic braking system and a front light feature. The car can move in multiple directions, adjust its speed, and control a servo arm using commands sent via Bluetooth. It uses an **Arduino Uno** as the main controller, an **HC-05 Bluetooth module** for communication, and an **L298N motor driver** for motor control.

## Table of Contents

- [Parts List](#parts-list)
- [Wiring Connections](#wiring-connections)
- [Code Overview](#code-overview)
- [Features](#features)
- [Bluetooth Commands](#bluetooth-commands)
- [Future Improvements](#future-improvements)
- [How to Use](#how-to-use)

## Parts List

1. **Arduino Uno** - Microcontroller to control the motors, lights, and servo.
2. **L298N Motor Driver** - Dual H-Bridge motor driver to control the motors' speed and direction.
3. **HC-05 Bluetooth Module** - Bluetooth module to receive commands wirelessly.
4. **12V 1.5A Battery** - Power supply for the motors and the motor driver.
5. **Four DC Motors** - For forward, backward, and turning movements.
6. **Servo Motor (SG90 or similar)** - To control a small arm or actuator.
7. **LED (with resistor)** - Front light to indicate when the car is moving forward.

## Wiring Connections

| Arduino Pin | Connected Component      |
|-------------|--------------------------|
| 5           | L298N IN1                |
| 6           | L298N IN2                |
| 10          | L298N IN3                |
| 11          | L298N IN4                |
| 9           | Servo (SERVO_PIN)        |
| 13          | LED                      |
| 5V, GND     | L298N VCC, GND           |
| RX, TX      | HC-05 TX, RX             |

**Power Connections:**  
Connect the 12V battery to the **L298N Motor Driver's** power input.  
Make sure to connect the grounds of the battery, Arduino, and L298N motor driver.

## Code Overview

- **Motor Control**: Uses the `L298N` motor driver to control two DC motors.
- **Servo Arm Control**: Controls a servo motor to simulate an arm, which can move up and down.
- **Front Light Control**: Turns an LED on or off to simulate headlights.
- **Electronic Braking System**: When braking is enabled, it briefly applies reverse current to stop the motors.

## Features

- **Directional Movement**: Forward, backward, left, and right turns.
- **Variable Speed Control**: Adjust the speed from low to high.
- **Front Light**: Toggle an LED on or off.
- **Electronic Brake**: Stops the car by applying reverse current to motors.
- **Servo Arm Control**: Move an attached servo arm up or down.

## Bluetooth Commands

| Command | Description                       |
|---------|-----------------------------------|
| F       | Move Forward                      |
| B       | Move Backward                     |
| L       | Turn Left                         |
| R       | Turn Right                        |
| G       | Forward with Left Turn            |
| I       | Forward with Right Turn           |
| H       | Backward with Left Turn           |
| J       | Backward with Right Turn          |
| 0-9, q  | Set Speed (0 = lowest, q = max)   |
| W       | Turn on front light and lower arm |
| w       | Turn off front light and raise arm|
| S       | Activate brake                    |

## Future Improvements

- **Obstacle Avoidance**: Integrate sensors for autonomous obstacle detection.
- **Battery Level Indicator**: Display the battery level on the app.
- **Enhanced Braking**: Implement a more advanced braking system with smoother deceleration.

## How to Use

1. **Setup**: Connect all components according to the wiring connections.
2. **Upload Code**: Upload the Arduino code to your Uno board.
3. **Bluetooth Pairing**: Pair your HC-05 Bluetooth module with your smartphone or remote device.
4. **Control the Bot**: Use a Bluetooth terminal app to send commands and control the bot.
