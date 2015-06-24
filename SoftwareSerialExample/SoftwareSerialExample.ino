/*
  Software serial multple serial test
 
 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.
 
 The circuit: 
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)
 
 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts, 
 so only the following can be used for RX: 
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69
 
 Not all pins on the Leonardo support change interrupts, 
 so only the following can be used for RX: 
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).
 
 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example
 
 This example code is in the public domain.
 
 */

/***********************************************************
This code is made for one of the componants in ZZWY studio's exhibition work - ""
The main function of Arudino part is to use Xbee wirelessly tranmit 
stretch sensor's data to the target platform (Mac)

@harryhow June 2015
************************************************************/


#include <SoftwareSerial.h>

SoftwareSerial xbeeSerial(2, 5); // RX, TX
int SensorPin = A1;    // Sensor connected to analog pin A1

void setup()  
{

  // Open serial communications and wait for port to open:
  // harry: possible unstable if using higher rate
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  xbeeSerial.begin(9600);
  xbeeSerial.println("Hello, world?");
}

void loop() // run over and over
{
  int sensor = analogRead(SensorPin);
  
  // harry: smooth out
  // when using batter, resistence values differ from 190 - 420
  // when using usb power source, value from 135 - 290
  int output = map(sensor, 190, 420, 10, 100);
  
      
  // print out the result
  Serial.print("analog input: ");
  Serial.print(sensor,DEC);
  Serial.print(" -> output: ");
  Serial.println(output,DEC);
  xbeeSerial.write(output); // harry: be sure to use .write to eliminate buggy OSC data by Processing 
  
   // pause before taking the next reading
    delay(100); 
   
  // test bi-direction transfer
//  if (xbeeSerial.available())
//    Serial.write(xbeeSerial.read());
//  if (Serial.available())
//    xbeeSerial.write(Serial.read());
//    
    
}

