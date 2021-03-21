/* Author: SolsticeVibe Instruments
 * Date: 2/27/2021
 * 
 * Analog Input using Feedback Ammeter Circuit 
 * 
 * This code demonstrates how the current can be read into 
 * the microcontroller using the A0 anolog input pin.
 * 
 * ****ATMEGA Controller**** 
 * Divet On Top         
 * *********(_)*********
 * **RESET  ***   A5 / SCL
 * **RX     ***   A4 / SDA
 * **TX     ***   A3
 * **Pin 2  ***   A2
 * **Pin 3  ***   A1
 * **Pin 4  ***   A0
 * **VCC    ***   GND
 * **GND    ***   AREF
 * **CRYS   ***   AVCC
 * **CRYS   ***   Pin 13
 * **Pin 5  ***   Pin 12
 * **Pin 6  ***   Pin 11
 * **Pin 7  ***   Pin 10
 * **Pin 8  ***   Pin 9
 * *********************
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

  //Set LED Pin | Pin 13
  pinMode(13, OUTPUT);
  pinMode(A1, OUTPUT);
}

void loop() {

  analogWrite(A1, 1000);
  delay(1000);

  //Reads Analog Pin
  reading = analogRead(AnalogPin); //Pin A0 = AnalogPin
  current = (float)reading * (5.0/1023.0);
  
  //Prints current to console
  Serial.print("The current is ");
  Serial.print(current);
  Serial.println(" A.");
  delay(1000);



  //Continue Blinking the LED on Pin 13
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
