# Arduino-External-Interrupt-Mechanism

In this assignment, asked to develop C/C++ code for an Arduino microcontroller. The program should implement an pin (external) interrupt mechanism. The code should wait for digital pin 2 to be driven high by an external source and, upon the pin transition, trigger an internal interrupt that calls a specific function named read_value.

The read_value function should read data from digital pins 3 - 10 and perform data processing. The data should be divided into two 4-bit words, and the first 4-bit word (pin 3 - 6), representing an 'address', should be stored in a variable called address, while the second 4-bit word (pin 7 - 10), representing 'value', should be stored in a variable named value. Both data words are LSB (3) to MSB (6) and LSB (7) to MSB (10).

Once the reading of the data is complete, the Arduino should perform the following actions:
     Raise digital pin 11 to a high state.
     Wait until digital pin 2 is set to a low state again, (hint use the same interrupt function).
     Set digital pin 11 to a low state.
     Start waiting for digital pin 2 to be set high externally again and the interrupt is triggered again.

Requirements:
     Utilize external interrupts to detect an edge/signal change of digital pin 2.
     Implement the read_value function to correctly read and split data from digital pins 3 - 10.
     Ensure that address and value are correctly updated with the data.
     Raise and lower digital pin 11 as described in the instructions.
     
