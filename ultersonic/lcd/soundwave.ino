/*
  Code By : Mohammed Alhazmi
  Elctronic Design By : Mohammed Alhazmi 
  all of the detils in the PDF
  this code under MIT Licnse
  date = 11/11/2016
*/
#include <LiquidCrystal_I2C.h>

int echo_pin = 8;
int traq_pin = 9;
int sda_pin = 10;
int scl_pin = 11;
int buzzer_pin = 12;

LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3,POSITIVE); // Create The Opejct Preamter For The LCD
void ultersonic(){
  long duration;
  long distanse;

  digitalWrite(traq_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(traq_pin, HIGH);

  duration = pulseIn(echo_pin, HIGH);

  distanse = duration * 0.034/2;
  Serial.println(distanse);
  if (distanse < 45){
    print_lcd("[!!] STEP AWAY", "FROM THE DEVISE");
    buzzer(1);
    } else{
      print_lcd("Welcome To ", "Mohammed World");
      buzzer(0 );
      }
  
  
  }
void print_lcd(const char *string1, const char *string2){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(string1);
  lcd.setCursor(0,1);
  lcd.print(string2);
  
  }
void buzzer(int num){
  /*
    This simple function take one argument True or False
    if True Buzzer will go on else b
    
  */
  if (num){
    digitalWrite(buzzer_pin, HIGH);
    }else{
      digitalWrite(buzzer_pin, LOW);
      }
  }
void setup() {
  // put your setup code here, to run once:
  pinMode(echo_pin, INPUT);
  pinMode(traq_pin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ultersonic();
  

}
