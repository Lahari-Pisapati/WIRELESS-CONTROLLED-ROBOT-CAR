#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
int mr1=2;
int mr2=3;
int ml1=4;
int ml2=5;
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pinMode(mr1,OUTPUT);
  pinMode(mr2,OUTPUT);
  pinMode(ml1,OUTPUT);
  pinMode(ml2,OUTPUT);
}
void loop() {
  char text;
  if (radio.available()) {
    
    radio.read(&text, sizeof(text));
    Serial.println(text);
   
  }
   if(text == 's')
    {Serial.println("stop");
    wait();}
    else if(text=='f')
    {Serial.println("forward");
    forward();}
    else if(text == 'l')
    {Serial.println("left");
    left();}
    else if(text == 'r')
    {Serial.println("right");
    right();}
    else
    Serial.println("no data");
}
void forward()
{
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,HIGH);
  digitalWrite(ml2,LOW);
  if(radio.available()==0){}
} 

void wait()
{
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,LOW);
  if(radio.available()==0){}
  }

void right()
{
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,HIGH);
  if(radio.available()==0){}
  }
void left()
{
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,HIGH);
  digitalWrite(ml1,HIGH);
  digitalWrite(ml2,LOW);
  if(radio.available()==0){}
  }
