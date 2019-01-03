int data;

void setup () { 
  Serial.begin (9600); 
  
  pinMode (7, OUTPUT); 
  digitalWrite(7, LOW);
}

void loop () { 
  if (Serial.available()>0) { 
    data= Serial.read(); 
    
    Serial.println (" Received data: "); 
    Serial.println (data==49);  
    if (data==49){
      Serial.println ("1");
      digitalWrite(7, HIGH); 
    } 
    else if (data == 48){
      Serial.println ("0");
      digitalWrite(7, LOW);
    } 
  }
}
