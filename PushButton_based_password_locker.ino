//Defining the libraries
#include<Servo.h>
#include<LiquidCrystal.h>

//Buzzer Alarm for theft situation
int buzzP = 13;

//Defining the keys 0 to 9
int key0 = A0;
int key1 = A1;
int key2 = A2;
int key3 = A3;
int key4 = A4;
int key5 = A5;
int key6 =  2;
int key7 =  3;
int key8 =  4;
int key9 =  5;

//Defining the LCD display pins and object
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
LiquidCrystal lcd (rs,en,d4,d5,d6,d7);

//Defining the servo pins and object
int servoP = 6;
int servoPos = 90;
Servo servoPass;

String origPass = "4714367";               //Original password

//Function for taking the password and comparing it with actual password
bool enterPassword()
{
  String userPass = "";                  //This string holds password entered by the user
  int count = 0;                      //Keeps the track of the number of characters entered
  while(count != 7){
    if (digitalRead(key0) == 0){
      userPass += "0";
      lcd.write("*");
      count += 1;
    }
    else if (digitalRead(key1) == 0){
      userPass += "1";
      lcd.write("*");
      count += 1;
    }
    else if (digitalRead(key2) == 0){
      userPass += "2";
      lcd.write("*");
      count += 1;
    }
    else if (digitalRead(key3) == 0){
      userPass += "3";
      lcd.write("*");
      count += 1;
    }
    else if (digitalRead(key4) == 0){
      userPass += "4";
      lcd.write("*");
      count += 1;
    }
    else if (digitalRead(key5) == 0){
      userPass += "5";
      lcd.write("*");
      count += 1;
    }
    else if (digitalRead(key6) == 0){
      userPass += "6";
      lcd.write("*");
      count += 1;
    }
    else if (digitalRead(key7) == 0){
      userPass += "7";
      lcd.write("*");
      count += 1;
    }
    else if (digitalRead(key8) == 0){
      userPass += "8";
      lcd.write("*");
      count += 1;
    }
    else if (digitalRead(key9) == 0){
      userPass += "9";
      lcd.write("*");
      count += 1;
    }
    delay(1500);
  }
  if (userPass == origPass)
    return true;
  else
    return false;
}

void setup() {
  
  lcd.begin(16,2);                     //Starting the lcd display
  Serial.begin(9600);                 //Starting the serial monitor

  //Configuring buttons as output
  pinMode(key0,OUTPUT);
  pinMode(key1,OUTPUT);
  pinMode(key2,OUTPUT);
  pinMode(key3,OUTPUT);
  pinMode(key4,OUTPUT);
  pinMode(key5,OUTPUT);
  pinMode(key6,OUTPUT);
  pinMode(key7,OUTPUT);
  pinMode(key8,OUTPUT);
  pinMode(key9,OUTPUT);

  //Default mode is high for each pin
  digitalWrite(key0,HIGH);
  digitalWrite(key1,HIGH);
  digitalWrite(key2,HIGH);
  digitalWrite(key3,HIGH);
  digitalWrite(key4,HIGH);
  digitalWrite(key5,HIGH);
  digitalWrite(key6,HIGH);
  digitalWrite(key7,HIGH);
  digitalWrite(key8,HIGH);
  digitalWrite(key9,HIGH);
  
  servoPass.attach(servoP);          //Servo pin attached to the object servoPass

  pinMode(buzzP,OUTPUT);             //The buzzer pin is set as output pin
}

void loop() {
    lcd.display();
    lcd.setCursor(0,0);
    lcd.print("Welcome");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Enter password");
    lcd.display();
    lcd.setCursor(0,1);

    bool permit = enterPassword();       //function call
    
    //Checking whether the user entered password matches the original password or not
    if(permit == true){
      lcd.clear();
      lcd.setCursor(0,0);
      servoPass.write(servoPos - 90);
      lcd.print("Your password");
      lcd.display();
      lcd.setCursor(0,1);
      lcd.print("is correct");
      delay(1000);
    }

    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.write("Wrong Password");
      digitalWrite(buzzP,HIGH);
    }
    delay(1000);
    lcd.clear();
    if (digitalRead(buzzP) == 0){
      lcd.setCursor(0,0);
      lcd.print("Having done with");
      lcd.setCursor(0,1);
      lcd.print("the work press 0");
      while(digitalRead(key0) != 0){
      
      }
      if (digitalRead(key0) == 0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Thank you");
        delay(1500);
        lcd.setCursor(0,1);
        lcd.print("Visit Again");
        delay(3000);
        lcd.clear();
        servoPass.write(servoPos);
      }
    }
   else{
    lcd.setCursor(0,0);
    lcd.write("Wrong Password");
    while(digitalRead(key9) != 0){
      
    }
    digitalWrite(buzzP,LOW);
   }
   lcd.clear();
   delay(2000);
}
