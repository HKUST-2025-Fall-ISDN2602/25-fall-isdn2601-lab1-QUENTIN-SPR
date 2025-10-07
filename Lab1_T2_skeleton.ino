#include "Arduino.h"

#define Vin 12   //*** Define the GPIO pin 12 as Vin ***
#define Vout 27  //*** Define the GPIO pin 27 as Vout ***
#define Cal 14   //*** Define the GPIO pin 14 as the node for current calcultion ***

float R = 22000;  //*** Resistance in Ohms ***

float x;
float y;
float c1;
float c2;

void setup() {

  Serial.begin(115200);   //*** Define the data rate as 115200 ***
  pinMode(Vin, OUTPUT);   //*** Set Vin as OUTPUT ***
  pinMode(Vout, INPUT);  //*** Set Vout as INPUT ***
  pinMode(Cal, INPUT);   //*** Set Test as INPUT ***

  delay(100);  //*** Set 100 ms delay ***
  //This task only needs to be done once, thus it is placed in setup().
  Serial.println("Vout (mV), I (uA)");  // display Vout (mV), I (uA) for Task 2 3 4
  for (int onPeriod = 0; onPeriod < 256; onPeriod++) {
    analogWrite(Vin, onPeriod);                 // Output PWM at Vin
    int Vout_value = analogRead(Vout);          // read the voltage level at Vout 0-3.3 V and convert it to 12 bit binary number
    float duty_Cycle = float(onPeriod) / 2.55;  //Duty Cycle in Percent
    int c_value = analogRead(Cal);              // read the voltage level at pin D14 0-3.3 V and convert it to 12 bit binary number
    c1 = float(Vout_value) * 3.3 / 4095;        // convert 12 bit binary number of Voltage level at Vout back to 0-3.3 V
    c2 = float(c_value) * 3.3 / 4095;           // convert 12 bit binary number of Voltage level at D14 back to 0-3.3 V
    //x =                                      // calculate the voltage at Vout in mV
    y = float(c2 - c1) / R;             // calculate current in uA for Task 2 3 4
    Serial.print(-1*c1);                             // print the voltage at Vout in mV negativ sign for backwards testing
    Serial.print(",");            
    Serial.println(y*-1e6);  // print the current in uA negativ sign for backwards testing
  }

  // Press reset button for a new sweep
}

void loop() {
  // Code for continuous operation can be added here
  
}