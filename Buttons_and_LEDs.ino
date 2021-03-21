/* Author: SolsticeVibe Instruments
 * Date: 3/20/2021
 * 
 * Buttons and LEDs
 * 
 * This code demonstrates how to utilie Buttons along with LEDs
 * in order to demonstrate the functionality of the microcontroller.
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

//Conditions
boolean LED = true;

//Time keeper
long int timeNum = 0, lastTime = millis();

//Input Variable
int button;

void setup() {
  //The Console is set with a baud rate of 9600
  Serial.begin(9600);
  Serial.println("This program demonstrate how to use a button.");

  //Set LED Pin | Pin 13 & Pin 9
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(2, INPUT_PULLUP);
}

void loop() {
  
   timeNum = millis();
   if(lastTime + 1000 < timeNum) {

      //Time Keeper Variable
      Serial.println("The number of milliseconds passed is the following:"); 
      Serial.println(timeNum); 

      //Button Test
      button = digitalRead(2); //value for button
      Serial.println("Button Press:"); 
      Serial.println(button); 

      if(!button) {
        digitalWrite(9, HIGH);
      }
      else {
        digitalWrite(9, LOW);
      }

      lastTime = millis(); //Reset


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



  
}
