
#include <SoftwareSerial.h>

int data;
String pinCode = "";


void setup () { 
  SoftwareSerial Serial2(0,1);
  Serial2.begin(38400);
  Serial.begin (9600); 
  pinMode (7, OUTPUT); 
  digitalWrite(7, LOW);
}

String intToString(int c){
  String car;
  switch(c){
    case 48:
      car = "0";
      break;
    case 49:
      car = "1";
      break;
    case 50:
      car = "2";
      break;
    case 51:
      car = "3";
      break;
    case 52:
      car = "4";
      break;
    case 53:
      car = "5";
      break;
    case 54:
      car = "6";
      break;
    case 55:
      car = "7";
      break;
    case 56:
      car = "8";
      break;
    case 57:
      car = "9";
      break;
  }
  return car;
}

void loop () { 
  if (Serial.available()>0) { 
    data= Serial.read(); 
    Serial.println (" Received data: "); 
    Serial.println (data);  
    if (data==97){
      Serial.println ("1");
      digitalWrite(7, HIGH); 
    } 
    else if (data == 98){
      Serial.println ("0");
      digitalWrite(7, LOW);
    }
    else{
      if(pinCode.length()<4){
        Serial.println("new letter: " + intToString(data));
        pinCode += intToString(data);
      }
      else{
        pinCode = "";
      }
    }
    if(pinCode.length()==4){
      Serial2.print("AT+PSWD"+ pinCode);
    }
  }
}
