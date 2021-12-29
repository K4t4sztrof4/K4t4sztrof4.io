/*
NAME OF THE PROJECT : SIGN LANGUAGE TRANSLATOR
MADE BY - MANMOHAN GUPTA
THIS PROJECT READS SENSOR VALUE AND TRY TO UNDERSTAND SYMBOLS GENERATED FROM AMERICAN SIGN LANGUAGE (ASL) CHART
AND DISPLAY ON A SMARTPHONE.
-------PIN CONFIGURATION----------------
A0-A4 : FLEX SENSOR
D4&D5 : FOR BLUETOOTH RX AND TX
A5&A6 : XPIN AND YPIN FOR ACCELROMETER
*/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(5,4);

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
mySerial.begin(9600);
Serial.begin(9600);
Serial.println("starting");
while (!Serial) 
{
; // wait for serial port to connect. Needed for native USB port only
Serial.println("upsz");
}
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
Serial.println(index);
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

if(((angle1>=70)&&(angle1<=82))&&((angle2>=77)&&(angle2<=95))&&((angle3>=70)&&(angle3<=86))&&((angle4>=73)&&(angle4<=85))&&((angle5>=0)&&(angle5<=45)))
{printfun('D'); Serial.println("D");}
if(((angle1>=70)&&(angle1<=82))&&((angle2>=77)&&(angle2<=95))&&((angle3>=70)&&(angle3<=86))&&((angle4>=73)&&(angle4<=85))&&((angle5>=0)&&(angle5<=45)))
{printfun('R'); Serial.println("R");}
if(((angle1>=70)&&(angle1<=82))&&((angle2>=77)&&(angle2<=95))&&((angle3>=70)&&(angle3<=86))&&((angle4>=73)&&(angle4<=85))&&((angle5>=0)&&(angle5<=45)))
{printfun('M'); Serial.println("M");}
if(((angle1>=70)&&(angle1<=82))&&((angle2>=77)&&(angle2<=95))&&((angle3>=70)&&(angle3<=86))&&((angle4>=73)&&(angle4<=85))&&((angle5>=0)&&(angle5<=45)))
{printfun('F'); Serial.println("F");}
if(((angle1>=70)&&(angle1<=82))&&((angle2>=77)&&(angle2<=95))&&((angle3>=70)&&(angle3<=86))&&((angle4>=73)&&(angle4<=85))&&((angle5>=0)&&(angle5<=45)))
{printfun('S'); Serial.println("S");}
if(((angle1>=70)&&(angle1<=82))&&((angle2>=77)&&(angle2<=95))&&((angle3>=70)&&(angle3<=86))&&((angle4>=73)&&(angle4<=85))&&((angle5>=0)&&(angle5<=45)))
{printfun('L'); Serial.println("L");}
if(((angle1>=70)&&(angle1<=82))&&((angle2>=77)&&(angle2<=95))&&((angle3>=70)&&(angle3<=86))&&((angle4>=73)&&(angle4<=85))&&((angle5>=0)&&(angle5<=45)))
{printfun('T'); Serial.println("T");}
if(((angle1>=70)&&(angle1<=82))&&((angle2>=77)&&(angle2<=95))&&((angle3>=70)&&(angle3<=86))&&((angle4>=73)&&(angle4<=85))&&((angle5>=0)&&(angle5<=45)))
{printfun('d'); Serial.println("d");}

index++;
delay(4000);
//increased delay from 200 to 4000 for testing purposes

}
//----------------------END-----------------------------
