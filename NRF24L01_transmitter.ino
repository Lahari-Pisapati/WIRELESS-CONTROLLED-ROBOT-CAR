#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
char msg = 's';
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}
void loop() {
  int x = analogRead(A0);
  int y = analogRead(A1);
  Serial.println(x);
  Serial.println(y);
  
  if(x<400&&y<500)
  msg='s';
  else if(x>500&&y>550)
  msg= 'f';
  else if(x>450&&y<500)
  msg = 'l';
  else if(x<400&&y>550)
  msg = 'r';
  Serial.println(msg);
  radio.write(&msg, sizeof(msg));
  //delay(1000);
}
