//Summer project
#include <LiquidCrystal.h> 
// Include the library to use a LCD display
#define tempSensor 0 // Define the A0 pin as “sensor”
int Vin; 
int pBuzz=5;
int tc;
int led=13;
float TC; // Variable that receives the converted voltage value to ºCtemperature
float TF; // Variable to receive the converted value from ºC to º
LiquidCrystal lcd (7, 8, 9, 10, 11, 12);/* The function above declares which Arduino’s pins will be used for controlling the LCD */
void setup(){   
lcd.begin(16, 2); // It tells the Arduino that the display is a 16x2 type 
lcd.print("-Temperature-"); 
pinMode(led,OUTPUT);
// Send the text to the screen of the display.
}
void loop(){ 
  Vin = analogRead (tempSensor); 
  TC=(500.0*Vin)/1023.0; 
  tc=TC;
/* Converts the voltage value into temperature and stores it into the “TC” variable (in ºC)*/ 
TF = ((9.0*TC)/5.0)+32.0; 
// Converts ºC to ºF   
lcd.setCursor(0, 1);
// Moves the cursor of the display to the next line
lcd.print(TF); // Exhibits the value of the temperature on the display
lcd.print((char)223);
//degree symbol  
lcd.print("F ");
// Writes “F” to indicate that it is in Fahrenheit scale. 
lcd.print (TC);  
lcd.print((char)223);// degree symbol
lcd.print("C"); 
if(tc>30)
{
  tone(pBuzz,3599,2000);
  digitalWrite(led,HIGH);
  delay(100);  
  digitalWrite(led,LOW);
}//
// Writes “C” to indicate that it is in Centigrade scale.
delay(2000); // Waits for one second to read the sensor pin again

}

