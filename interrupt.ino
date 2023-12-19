/**
 * @file bics.ino
 * This file contains the code for the assignment of implement an pin (external) interrupt mechanism for Arduino microcontroller.
 *
 * @author Gayani Liyanage
 * @date 2023-10-22
 */

uint8_t address = 0;  // Variable to store the address (4-bit)
uint8_t value = 0;    // Variable to store the value (4-bit)
#define inputPin 2
#define outputPin 11

bool printNow = 0;
void setup() {
  Serial.begin(9600);

  // Configure digital pins 3-10 as inputs with the pull-up resistor enabled
  for (byte i = 3; i <= 10; i++) {
    pinMode(i, INPUT_PULLUP);
  }

  pinMode(inputPin, INPUT);  // Set digital pin 2 as an input
  pinMode(outputPin, OUTPUT); // Set digital pin 11 as an output
  attachInterrupt(digitalPinToInterrupt(inputPin), read_value, RISING); // Attach the interrupt to pin 2 (rising edge)
}

void loop() {

  if (printNow) {
    printNow = 0;

    Serial.print("address: ");
    Serial.print(address, BIN);
    Serial.print("  value: ");
    Serial.println(value, BIN);
  }
}

void read_value() {

  // Disable ISR 
  detachInterrupt(digitalPinToInterrupt(inputPin)) ;
  // Read the 4-bit 'address' from pins 3 to 6
  address = 0;
  for (byte i = 3; i <= 6; i++) {
    address |= digitalRead(i) << (i - 3);
  }

  // Read the 4-bit 'value' from pins 7 to 10
  value = 0;
  for (byte i = 7; i <= 10; i++) {
    value |= digitalRead(i) << (i - 7);
  }
  
   // Raise digital pin 11 to a high state
  digitalWrite(11, HIGH);

  // Wait until digital pin 2 is set to a low state (falling edge)
  while (digitalRead(2) == HIGH) {
  // Wait for the falling edge on pin 2
  }

  //set digital pin 11 to a low state
  digitalWrite(11, LOW);
  
  //re enable ISR
  attachInterrupt(digitalPinToInterrupt(inputPin), read_value, RISING); // Attach the interrupt to pin 2 (rising edge)
  printNow = 1;
}
