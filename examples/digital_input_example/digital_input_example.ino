/*
AUTHOR: Micah Black, A2D Electronics
DATE: Jan 22, 2021
PURPOSE: This example enables the device, then cycles
through all the pins printing them out to serial,
then disables the device.
*/

#include <MUX4067.h>

//Arduino Input Pin
//Connected to MUX Common
uint8_t common_pin = 3;

// Control Pins
uint8_t enable_pin = 4;
uint8_t s0_pin = 8;
uint8_t s1_pin = 5;
uint8_t s2_pin = 6;
uint8_t s3_pin = 7;

//enable_pin, s0_pin, s1_pin, s2_pin, s3_pin
MUX4067 mux(enable_pin, s0_pin, s1_pin, s2_pin, s3_pin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Starting MUX4067 Example");
}

void loop() {
  // put your main code here, to run repeatedly:

  //enable mux
  mux.MUX4067_enable();
  Serial.println("Mux Enabled");
  
  //read all pins on the mux
  Serial.print("Pin States: ");
  for(int i = 0; i<= MUX4067_PIN_COUNT; i++)
  {
    delay(250);
    Serial.print(digitalRead(common_pin));
  }
  
  //disable mux
  mux.MUX4067_disable();
  Serial.println("\nMux Disabled\n");
  
  //delay before reading again
  delay(2000);

}