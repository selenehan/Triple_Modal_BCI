# Neurotech Projects Divison '25-'26: Team 6 Project

**A Triple-Modal Brain-Computer Interface (SSVEP, Alpha Rhythm, EMG) for Real-Time Multi-Class Control of an RC Car**  
Developed at Neurotech@Davis, University of California, Davis.

---

## Overview

Our team, Wheelatronic, developed and implemented a real-time Brain-Computer Interface (BCI) that integrates three signal modalities:

- **SSVEP (Steady-State Visual Evoked Potentials)**: To select directional commands via gaze fixation
- **Alpha Rhythms**: To detect eye closure or neutral/resting state
- **EMG (Electromyography)**: To detect jaw clenching as a stop command

The system enables intuitive, multi-class robotic control using a wearable EEG headset and muscle sensors, interfaced with an Arduino-powered RC car.

---

## System Architecture

### Input Modalities
| Signal | Function | Detection |
|--------|----------|-----------|
| SSVEP  | Directional control (Fwd, Back, Left, Right) | FFT peak classification of 7–13 Hz flickering |
| Alpha  | Neutral/rest state | Mean amplitude in 8–12 Hz |
| EMG    | Emergency stop | Amplitude threshold crossing (jaw clench) |

### Processing Pipeline
1. Signal acquisition via OpenBCI
2. Real-time filtering, FFT, and feature extraction in OpenViBE
3. Command classification in MATLAB
4. Serial communication with Arduino Uno
5. Actuation of RC car via switch-case motor logic

---

## Hardware

- **EEG**: OpenBCI Cyton board, dry electrodes
- **Robot**: ELEGOO Smart Car V4.0
- **Microcontroller**: Arduino Uno R3
- **Software**: MATLAB, OpenVIBE, OpenBCI GUI
- **Serial Comm**: USB interface between MATLAB and Arduino

---

## Performance

- **SSVEP Classifier Accuracy**: 83% (within 0.3 Hz window, 2s window)
- **Alpha Detection Accuracy**: 99%
- **EMG Stop Accuracy**: 100%
- **Overall system accuracy**: 75–80%
- **System latency**: ~2 seconds post-stimulus

---

## Requirements

Software:
1. MATLAB R2022a or Later
2. OpenVIBE 3.6.0
3. Arduino IDE


---

## How to Run

1. Launch OpenBCI GUI and stream data to OpenVIBE
2. Use OpenVIBE to route data to MATLAB (via Scripting Box or external connection)
3. In MATLAB:
   - Run the classifier pipeline
   - Send decoded commands to Arduino via serial
4. Upload the Arduino sketch to the Uno (from `/hardware/`)
5. Control the RC car using gaze, rest, and jaw clenching.

---

## References

- Zhou, C. (2023). *SSVEP-based BCI Wheelchair Control System*.  
  [arXiv:2307.08703](https://arxiv.org/abs/2307.08703)
- OpenVIBE Documentation:  
  https://openvibe.inria.fr/documentation/3.6.0/Doc_BoxAlgorithm_MatlabScripting.html

---

## Authors

Selene Han, Carolyn Espinosa, Andy Vo, Nithmi Jayasundara

## Contributors

Viktor Rodriguez  
Aneesh Bhardwaj  
Grace Pei  
Arnav Salu  

**Affiliation**: Neurotech@Davis, UC Davis

---

## License

This project is licensed under the MIT License. See `LICENSE` for details.


