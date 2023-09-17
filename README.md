# Cube Goldberg Project 2019

## Description

This Arduino project controls various components of a Rube Goldberg machine, including a servo, sensors, and LEDs, to release a marble and trigger a photocell-based mechanism. It is designed to be part of an elaborate chain reaction, showcasing the fun and complexity of such projects.

## Author

- **Author:** Lauren Crist
- **Date:** March 14, 2019

## Table of Contents

- [Cube Goldberg Project 2019](#cube-goldberg-project-2019)
  - [Description](#description)
  - [Author](#author)
  - [Table of Contents](#table-of-contents)
  - [Components](#components)
  - [Installation](#installation)
  - [Usage](#usage)
  - [License](#license)

## Components

- Arduino board
- Servo motor
- Various sensors (marble catch, car bumper, photocell)
- LEDs (laser, L1, L2)
- Resistors
- Wires and connections

## Installation

1. Connect the hardware components.
2. Open the Arduino IDE.
3. Upload the provided Arduino sketch (`CubeGoldbergProject.ino`) to your Arduino board.

## Usage

1. After uploading the code to the Arduino board, follow these steps:
   - The project controls various components and sensors:
     - Marble catch sensor (`marbleCatch`) detects if a marble is in place.
     - Car bumper sensor (`carBumper`) detects if a car has reached a certain point.
     - Laser LED (`laser`) is used as part of the project.
     - Photocell (`photocell`) measures light levels.
   - The code monitors these sensors and controls a servo motor (`marbleRelease`) to release a marble at the right moment.
   - LEDs (`L1` and `L2`) are used for status and control.
   - The system interacts with these components to create a complex chain reaction.

2. Modify the code and hardware setup to fit your specific Rube Goldberg machine design and requirements.

## License

This project is open-source and available under the [MIT License](LICENSE). You are free to use, modify, and distribute this code for personal and educational purposes. See the [LICENSE](LICENSE) file for more details.
