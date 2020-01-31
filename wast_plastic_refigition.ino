/*
 *
 * Project Name:   reformation of waste plastic into useful structure
 * Author List:    Sanjay Bisht,Abdul ahad, Rachna
 * Filename:     wast_plastic_refigition.c
 * Functions:    setup(),loop()
 * Global Variables: S1,S2,S3,S4,Pump,Mixer_motor,rack_pinion_motor_clock,rack_pinion_motor_anticlock
 *
*/


#include <Wire.h>  
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo Servo1;
Servo Servo2;
Servo Servo3;
#define S1 A0
#define S2 A1
#define S3 A2
#define S4 A3
#define Pump 5
#define Mixer_motor 6
#define rack_pinion_motor_clock 7
#define rack_pinion_motor_anticlock 8



 /*
                            *
                            * Function Name:setup()
                            * Input:  S1,S2,S3,S4,Pump,Mixer_motor,rack_pinion_motor_clock,rack_pinion_motor_anticlock
                            * Output:    lcd.print();
                            * Logic: this funxtion defined all the inputs and output of the controller;
  * Example Call: none
  *
 */
void setup()
{        
lcd.begin();
  lcd.backlight();
  Servo1.attach(9);
  Servo2.attach(10);
  Servo3.attach(11);
  pinMode(S1, INPUT_PULLUP);
  pinMode(S2, INPUT_PULLUP);
  pinMode(S3, INPUT_PULLUP);
  pinMode(S4, INPUT_PULLUP);
  pinMode(Pump, OUTPUT);
  digitalWrite(Pump, HIGH);
  pinMode(Mixer_motor, OUTPUT);
  digitalWrite(Mixer_motor, HIGH);
  pinMode(rack_pinion_motor_clock, OUTPUT);
  digitalWrite(rack_pinion_motor_clock, HIGH);
  pinMode(rack_pinion_motor_anticlock, OUTPUT);
  digitalWrite(rack_pinion_motor_anticlock, HIGH);
 

  lcd.print(" Automatic WAST ");
  lcd.setCursor(0, 1);
  lcd.print("plastic recycle ");
  delay(3000);

}


 /*
                            *
                            * Function Name:loop()
                            * Input: S1-->switch for input,
                            *        S2-->,S3,S4,Pump,Mixer_motor,rack_pinion_motor_clock,rack_pinion_motor_anticlock
                            * Output:    lcd.print();digital write();
                            * Logic: this funxtion defined all the inputs and output of the controller;
  * Example Call: none
  *
 */
void loop()
{
    lcd.clear();
  lcd.print("Button Press to ");
  lcd.setCursor(0, 1);
  lcd.print("START Machine");
 delay(500);
 
  if (digitalRead(S4) == LOW)
{
  
  lcd.clear();
  lcd.print("Plastic Filling.");
  Servo1.write(0);
  delay(5000);
  Servo1.write(90);
  delay(500);

  lcd.clear();
  lcd.print("Cemant Felling..");
  Servo2.write(0);
  delay(5000);
  Servo2.write(90);
  delay(500);

  lcd.clear();
  lcd.print("Sant Felling....");
  Servo3.write(0);
  delay(5000);
  Servo3.write(90);
  delay(500);



  lcd.clear();
  lcd.print("Rack motot C_W..");
  digitalWrite(rack_pinion_motor_clock, LOW);
  delay(1000);

}

  if (digitalRead(S1) == LOW)
{
  lcd.clear();
  lcd.print("Rack motot C_W..");
  digitalWrite(rack_pinion_motor_clock, HIGH);
  delay(1000);
    lcd.clear();
  lcd.print("Water Filling...");
  digitalWrite(Pump, LOW);
  delay(3000);
  digitalWrite(Pump, HIGH);
  delay(500);
    lcd.clear();
  lcd.print("Mixer motor ON");
  digitalWrite(Mixer_motor, LOW);
  delay(5000);
  digitalWrite(Mixer_motor, HIGH);
  delay(1000);
  lcd.clear();
  lcd.print("Rack motot A_W..");
  digitalWrite(rack_pinion_motor_anticlock, LOW);
  delay(1000);
}

  if (digitalRead(S2) == LOW)
{
  lcd.clear();
  lcd.print("Rack motot A_W..");
  digitalWrite(rack_pinion_motor_anticlock, HIGH);
  delay(1000);

  
}

  if (digitalRead(S3) == LOW)
{
  lcd.clear();
  lcd.print("Rack motot C_W..");
  digitalWrite(rack_pinion_motor_clock, LOW);

}



}
