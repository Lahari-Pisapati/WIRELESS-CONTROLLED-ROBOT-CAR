#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>

#define m11 6
#define m12 9 
#define m21 10
#define m22 11
#define ESP8266_BAUD 9600

BlynkTimer timer;
char auth[]="";
char ssid[]="xyz";
char pass[]="xyz";
int xv1=128;
int yv1=128;
int xv10=128;
int yv10=128;

SoftwareSerial EspSerial(2,4);
ESP8266 wifi(&EspSerial);

void myTimerEvent()
{
  Blynk.virtualWrite(V5, millis()/1000);
}

void setup() {
  Serial.begin(9600);
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  Blynk.begin(auth, wifi, ssid, pass);
  timer.setInterval(1000L, myTimerEvent); 
}

void loop() {
  Blynk.run();
  //timer.run();
  Serial.println(xv1);
  Serial.println(yv1);
  Serial.println(xv10);
  Serial.println(yv10);
  delay(1);
  if(yv1>220&&yv10>220)
  {forward();
    Serial.println("forward");
    }
  else if(yv1<35&&yv10<35)
  { backward();
    Serial.println("backward");
  }
    
  else if(yv1>220&&yv10<35)
  {right();
  Serial.println("right");
  }
  else if(yv1<35&&yv10>220)
  {left();
  Serial.println("left");}
  else 
  {Stop();
    Serial.println("stop");
    }

}

BLYNK_WRITE(V1)
{
  xv1 = param[0].asInt();
  yv1 = param[1].asInt();
 
}

BLYNK_WRITE(V10)
{
  xv10 = param[0].asInt();
  yv10 = param[1].asInt();
   
}

void forward()
{
  digitalWrite(m11, HIGH);
  digitalWrite(m12,LOW);
  digitalWrite(m21,HIGH);
  digitalWrite(m22,LOW);
}

void backward()
{
  digitalWrite(m11, LOW);
  digitalWrite(m12,HIGH);
  digitalWrite(m21,LOW);
  digitalWrite(m22,HIGH);
}

void right()
{
  digitalWrite(m11, HIGH);
  digitalWrite(m12,LOW);
  digitalWrite(m21,LOW);
  digitalWrite(m22,HIGH);
}

void left()
{
  digitalWrite(m11, LOW);
  digitalWrite(m12,HIGH);
  digitalWrite(m21,HIGH);
  digitalWrite(m22,LOW);
}

void Stop()
{
  digitalWrite(m11, LOW);
  digitalWrite(m12,LOW);
  digitalWrite(m21,LOW);
  digitalWrite(m22,LOW);
}
