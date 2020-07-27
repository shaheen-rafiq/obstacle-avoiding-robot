//Arduino Bluetooth Controlled Car

// Pin Definitions
#define BTHC05_TX  11
#define BTHC05_RX  10
#define ENABLE1  5
#define ENABLE2  6
#define m11 2 
#define m12 3 
#define m21 4
#define m22 7 

void setup()
{
Serial.begin(9600);
pinMode(ENABLE1, OUTPUT);
pinMode(ENABLE2, OUTPUT);
pinMode(m11, OUTPUT);
pinMode(m12, OUTPUT);
pinMode(m21, OUTPUT);
pinMode(m22, OUTPUT);

digitalWrite(ENABLE1, HIGH);
digitalWrite(ENABLE2, HIGH);
}

void loop(){
  char command; 
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command);
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    }
  } 
}
void forward()
{
digitalWrite(m11, HIGH);
digitalWrite(m12, LOW);
digitalWrite(m21, HIGH);
digitalWrite(m22, LOW);
}
void left()
{
digitalWrite(m11, LOW);
digitalWrite(m12, HIGH);
digitalWrite(m21, HIGH);
digitalWrite(m22, LOW);
}
void backward()
{
digitalWrite(m11, LOW);
digitalWrite(m12, HIGH);
digitalWrite(m21, LOW);
digitalWrite(m22, HIGH);
}
void right()
{
digitalWrite(m11, HIGH);
digitalWrite(m12, LOW);
digitalWrite(m21, LOW);
digitalWrite(m22, HIGH);
}
void Stop()
{
digitalWrite(m11, LOW);
digitalWrite(m12, LOW);
digitalWrite(m21, LOW);
digitalWrite(m22, LOW);
}
