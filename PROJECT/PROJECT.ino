/*
NAME OF THE PROJECT : SINGING GLOVE
MADE BY - JAKAB-GYIK SAROLTA, KISS BORBÁLA, SIMON KATA, VERES NOÉMI - TECHNICAL UNIVERSITY OF CLUJ-NAPOCA
THIS PROJECT READS SENSOR VALUE AND TRY TO UNDERSTAND SYMBOLS GENERATED FROM MUSICAL NOTES(AN OCTET)
AND DISPLAY ON A SMARTPHONE.
-------PIN CONFIGURATION----------------
A0-A4 : FLEX SENSOR
D8&D9 : FOR BLUETOOTH RX AND TX
A5&A6 : XPIN AND YPIN FOR ACCELROMETER
*/

#include <SoftwareSerial.h>

const byte rxPin = 8;
const byte txPin = 9;
SoftwareSerial mySerial(rxPin, txPin);

char temp = '0';

//variable initializtion
int xpin = A5;
int xadc = 0;
int xmax = 0;
int xmin = 1023;

int ypin = A6;
int yadc = 0;
int ymax = 0;
int ymin = 1023;

int FLEX_PIN1 = A0; 
int flexADC1 = 0; 
int sensorMin1 = 1023; 
int sensorMax1 = 0;

int FLEX_PIN2 = A1; 
int flexADC2 = 0; 
int sensorMin2 = 1023; 
int sensorMax2 = 0;

int FLEX_PIN3 = A2; 
int flexADC3 = 0; 
int sensorMin3 = 1023; 
int sensorMax3 = 0;

int FLEX_PIN4 = A3; 
int flexADC4 = 0; 
int sensorMin4 = 1023; 
int sensorMax4 = 0;

int FLEX_PIN5 = A4; 
int flexADC5 = 0; 
int sensorMin5 = 1023; 
int sensorMax5 = 0;

int index=1;

void setup() 
{
   pinMode(9, OUTPUT);
  pinMode(8, INPUT);
mySerial.begin(9600);
//mySerial.print(true);
Serial.begin(9600);
//Serial.println("starting");
while (!Serial) 
{
; // wait for serial port to connect. Needed for native USB port only
//Serial.println("upsz");
}
while (!mySerial) 
{
; // wait for bluetooth to connect. Needed for native USB port only

}
//KI LEHET KOMMENTELNI
Serial.println("bluetoth available");
mySerial.write("bluetoth available");
// callibrating the sensors for adaptivity with different bends
while(millis()<15000)
{
if(digitalRead(7)==HIGH)
{
float flexADC1 = analogRead(FLEX_PIN1);
float flexADC2 = analogRead(FLEX_PIN2);
float flexADC3 = analogRead(FLEX_PIN3);
float flexADC4 = analogRead(FLEX_PIN4);
float flexADC5 = analogRead(FLEX_PIN5);

if(flexADC1<sensorMin1)
{
sensorMin1=flexADC1;
}
if(flexADC1>sensorMax1)
{
sensorMax1=flexADC1;
}

if(flexADC2<sensorMin2)
{
sensorMin2=flexADC2;
}
if(flexADC2>sensorMax2)
{
sensorMax2=flexADC2;
}

if(flexADC3<sensorMin3)
{
sensorMin3=flexADC3;
}
if(flexADC3>sensorMax3)
{
sensorMax4=flexADC4;
}

if(flexADC5<sensorMin5)
{
sensorMin5=flexADC5;
}
if(flexADC5>sensorMax5)
{
sensorMax5=flexADC5;
}

if(flexADC4<sensorMin4)
{
sensorMin4=flexADC4;
}
if(flexADC4>sensorMax4)
{
sensorMax4=flexADC4;
}
}
}
}


void printfun(char cp) //to avoid printing repeating symbols
{
if(cp!=temp)
{
mySerial.print(cp);
temp=cp;
}
}

void loop() 
{
  mySerial.println("ok");

// reading sensor value
float flexADC1 = analogRead(FLEX_PIN1);
float flexADC2 = analogRead(FLEX_PIN2);
float flexADC3 = analogRead(FLEX_PIN3);
float flexADC4 = analogRead(FLEX_PIN4);
float flexADC5 = analogRead(FLEX_PIN5);


//Serial.println(flexADC1);
//Serial.println(flexADC2);
//Serial.println(flexADC3);
//Serial.println(flexADC4);
//Serial.println(flexADC5);

//flexADC1 = constrain(flexADC1,sensorMin1, sensorMax1);
//flexADC2 = constrain(flexADC2,sensorMin2, sensorMax2);
//flexADC3 = constrain(flexADC3,sensorMin3, sensorMax3);
//flexADC4 = constrain(flexADC4,sensorMin4, sensorMax4);
//flexADC5 = constrain(flexADC5,sensorMin5, sensorMax5);
//mindegyik constraint min vagy max volt.(0/1023)

float angle1= map(flexADC1, sensorMin1, sensorMax1, 0, 90);
float angle2= map(flexADC2, sensorMin2, sensorMax2, 0, 90);
float angle3= map(flexADC3, sensorMin3, sensorMax3, 0, 90);
float angle4= map(flexADC4, sensorMin4, sensorMax4, 0, 90);
float angle5= map(flexADC5, sensorMin5, sensorMax5, 0, 90);
//testing 
/*Serial.println(index);
xadc = analogRead(xpin);
yadc = analogRead(ypin);
Serial.print("x: ");
Serial.println(xadc);
Serial.print("y: ");
Serial.println(yadc);
Serial.print("ADC1: ");
//Serial.println(flexADC1);
Serial.println(angle1);
Serial.print("ADC2: ");
//Serial.println(flexADC2);
Serial.println(angle2);
Serial.print("ADC3: ");
//Serial.println(flexADC3);
Serial.println(angle3);
Serial.print("ADC4: ");
//Serial.println(flexADC4);
Serial.println(angle4);
Serial.print("ADC5: ");
//Serial.println(flexADC5);
Serial.println(angle5);
Serial.println("---");
*/
if(((angle1>=12)&&(angle1<=18))&&((angle2>=21)&&(angle2<=22))&&((angle3>=18)&&(angle3<=20))&&((angle4>=20)&&(angle4<=22))&&((angle5>=18)&&(angle5<=22)))
{Serial.println("DO"); mySerial.write('7');}
if(((angle1>=11)&&(angle1<=15))&&((angle2>=24)&&(angle2<=25))&&((angle3>=23)&&(angle3<=24))&&((angle4>=23)&&(angle4<=23))&&((angle5>=22)&&(angle5<=24)))
{Serial.println("RE");mySerial.write('6');}
if(((angle1>=16)&&(angle1<=20))&&((angle2>=24)&&(angle2<=25))&&((angle3>=23)&&(angle3<=24))&&((angle4>=23)&&(angle4<=23))&&((angle5>=22)&&(angle5<=24)))
{Serial.println("MI");mySerial.write('5');}
if(((angle1>=23)&&(angle1<=23))&&((angle2>=21)&&(angle2<=22))&&((angle3>=18)&&(angle3<=20))&&((angle4>=20)&&(angle4<=22))&&((angle5>=18)&&(angle5<=22)))
{Serial.println("FA");mySerial.write('4');}
if(((angle1>=21)&&(angle1<=23))&&((angle2>=24)&&(angle2<=26))&&((angle3>=23)&&(angle3<=24))&&((angle4>=23)&&(angle4<=23))&&((angle5>=22)&&(angle5<=24)))
{Serial.println("SOL");mySerial.write('2');}
if(((angle1>=19)&&(angle1<=21))&&((angle2>=23)&&(angle2<=24))&&((angle3>=21)&&(angle3<=23))&&((angle4>=21)&&(angle4<=23))&&((angle5>=20)&&(angle5<=23)))
{Serial.println("LA");mySerial.write('1');}
if(((angle1>=22)&&(angle1<=23))&&((angle2>=25)&&(angle2<=25))&&((angle3>=19)&&(angle3<=22))&&((angle4>=20)&&(angle4<=23))&&((angle5>=20)&&(angle5<=23)))
{Serial.println("TI"); mySerial.write('8');}
//LEHET A DELAYT KI KENE VENNI
//index++;
delay(2000);
//increased delay from 200 to 4000 for testing purposes

}
//----------------------END-----------------------------
