/* Author: SolsticeVibe Instruments
 * Date: 2/27/2021
 * 
 * Analog Input using Feedback Ammeter Circuit 
 * 
 * This code demonstrates how the current can be read into 
 * the microcontroller using the A0 anolog input pin.
 * 
 * 
 * This example is public domain.
 */

//Initial/Global Values
int AnalogPin = A0;
int reading = 0;
float current = 0;
boolean LED = true;


void setup() {
  //The Console is set with a baud rate of 9600
  Serial.begin(9600);
  Serial.println("This program will read the current in ampson pin A0.");

  //Set LED Pin
  pinMode(13, OUTPUT);
}

void loop() {
  
  //Reads Analog Pin
  reading = analogRead(AnalogPin);
  current = (float)reading * (5.0/1023.0);
  
  //Prints current to console
  Serial.print("The current is ");
  Serial.print(current);
  Serial.println(" A.");
  delay(1000);

  //Continue Blinking the LED
  if(LED == true) {
    //LED on Pin 13 is turned on
    digitalWrite(13, HIGH);
    LED = false;
  }
  else {
    digitalWrite(13, LOW); //LED is turned off
    LED = true;
  }
  
}
