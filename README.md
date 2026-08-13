# SAPS — Smart Agriculture with Pest Control System Using AI

A smart agriculture prototype that combines robotics, IoT, obstacle avoidance, soil-moisture monitoring, and pest detection to support real-time crop and field monitoring.

## Overview

SAPS (Smart Agriculture with Pest Control System Using AI) is a mobile agricultural system designed to help monitor field conditions and detect potential crop problems.

The system uses a mobile four-wheel platform with sensors and an ESP32-CAM to collect environmental and visual information while moving through the field.

## Main Features

- Obstacle detection and avoidance
- Soil-moisture monitoring
- Crop image capture using ESP32-CAM
- AI-based pest detection
- Remote alerts through Telegram
- Mobile robotic platform for field monitoring

## How It Works

1. The car starts moving forward.
2. The ultrasonic sensor checks for obstacles.
3. When an obstacle is detected, the car stops and scans the surrounding direction using the servo-mounted sensor.
4. The car selects a suitable direction and continues moving.
5. The soil-moisture sensor collects readings from the field.
6. The ESP32-CAM captures crop images.
7. The images are used for pest detection.
8. Relevant alerts are sent to the user through Telegram.

## Obstacle Avoidance

The obstacle-avoidance system uses an HC-SR04 ultrasonic sensor mounted on a servo motor.
The sensor checks the distance in front of the car and scans the left and right sides when an obstacle is detected. Based on the measured distances, the car changes direction or moves backward when both sides are blocked.
The documented implementation uses a 15 cm decision threshold for the obstacle-avoidance logic.

## Soil-Moisture Monitoring

A capacitive soil-moisture sensor is connected to an ESP32 to measure soil conditions.
When the moisture level falls below the set threshold, the system sends a notification through Telegram so that the farmer can take appropriate action.

## Pest Detection

The ESP32-CAM is used to capture images of crops.
These images are processed using the project's AI-based pest-detection system to identify possible pest presence. The system is intended to support early detection and monitoring.

## Remote Alerts

The ESP32 uses Wi-Fi connectivity and the Telegram Bot API to send alerts to the farmer.

Alerts can be used for conditions such as: Low soil moisture, Detected pests

## Project Results

### The project was tested for:

1. Obstacle detection and avoidance
2. Soil-moisture sensing
3. ESP32-CAM image capture
4. Pest detection
5. Telegram notifications

## Limitations

Performance can be affected by factors such as lighting conditions, sensor positioning, and the size or location of obstacles.

## Future Improvements

Possible future improvements include:

1. GPS-based navigation
2. Improved field path planning
3. More advanced crop and pest detection
4. Weather-based decision support
5. Remote mobile control
6. Automated agricultural actions

## Academic Project

Smart Agriculture with Pest Control System Using AI (SAPS)

Developed as an academic team project at MVJ College of Engineering.
