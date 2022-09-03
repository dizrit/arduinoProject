#include <LiquidCrystal.h>
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

int pinIn = A0;
int keyValue =0;
int acpValue =0;
int sensorPin = A5;

int reading =0;
float voltage =0;
float temperatureC =0;

void setup() {
  pinMode (pinIn, INPUT);
  lcd.begin (16, 2);
  Serial.begin (9600);
  
  
}

  void loop() {
    pushButton();
    
    delay (200);
    switch (keyValue) {
      case 1:
          
          lcd.print ("Hi!");
          delay(3000);
          lcd.clear();
        break;   
      case 2:
           
           lcd.setCursor(0, 0);
           lcd.print("Temp: ");
           lcd.setCursor(6, 0);
           reading = analogRead(sensorPin);
           voltage = reading * 5.0;
           voltage /= 1024.0;
           temperatureC = (voltage - 0.5) * 100;
           lcd.print(temperatureC);
           Serial.println(temperatureC);
           delay(3000);
           
           
        break;
      case 3:
        	lcd.clear();
            lcd.print("Time");
            delay(2000);
            lcd.setCursor(0, 0);
            for(int h=0;h<=23;h++){
              for(int m=0;m<=59;m++){
                for(int s=0;s<=59;s++){
                  showtimer(h,m,s); 
                  delay(1000);
                  
                  }  
                }
            }  
      		
        break;
      case 4:
        break;
      case 5:
        
        break;
      }
  
  }

  
  void pushButton(){
    acpValue = analogRead (pinIn);
    if (acpValue >=910) {
      keyValue = 1;
      delay(50);
      
    }
    if (acpValue >=700 && acpValue <= 900) {
      keyValue = 2;
      delay(50);
    }
    if (acpValue >=500 && acpValue <= 600) {
      keyValue = 3;
      delay(50);
    }
    if (acpValue >=200 && acpValue <=300) {
      keyValue = 4;
      delay(50);
    }
    if (acpValue >=110 && acpValue <= 190) {
      keyValue = 5;
      delay(50);
    }
  }

  void showtimer(int hh,int mm,int ss){
  String hour;
  String min;
  String sec;
  if (hh<9){
  hour="0"+String(hh);
  }else{
   hour=String(hh);
  }
  if(mm<9){
  min="0" + String(mm);
  }else{
  min=String(mm);
  }
  if (ss<9){
  sec="0" + String(ss);
  }else {
   sec=String(ss); 
  }
   lcd.setCursor(4, 1);
  lcd.print(hour + ":" + min + ":" + sec);  
}