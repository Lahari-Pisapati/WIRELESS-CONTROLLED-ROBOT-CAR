#define BLYNK_PRINT Serial
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
    
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>
#include <Servo.h>

char auth[] = "238bbb73b89846cfb6cf9ac4bc6a3b9d";
SoftwareSerial SerialBLE(10, 11); // RX, TX
#define m11 4
#define m12 5
#define m21 6
#define m22 7
Servo s1;
int xv1=128;
int yv1=128;
int xv10=128;
int yv10=128;

void setup()
{
  // Debug console
  Serial.begin(9600);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");
  s1.attach(9);
  s1.write(0); 
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
   else if(xv1>220)
  {s1.write(90);
  Serial.println("servo 90");
  }  
     else if(xv1<35)
  {s1.write(0);
  Serial.println("servo 0");
  } 
  else if(yv1>220&&yv10<35)
  {left();
  Serial.println("right");
  }
  else if(yv1<35&&yv10>220)
  {right();
  Serial.println("left");}
  else if(yv1>120&&yv1<140&&xv1<140&&xv1>120&&yv10>120&&yv10<140&&xv10<140&&xv10>120)
  {Stop();
    Serial.println("stop");
    }

}


BLYNK_WRITE(V1) 
{
  xv1 = param[0].asInt();
  yv1 = param[1].asInt();
  //Serial.println(xv1);
  //Serial.println(yv1);
}
BLYNK_WRITE(V10) 
{
  xv10 = param[0].asInt();
  yv10 = param[1].asInt();
  //Serial.println(xv1);
  //Serial.println(yv1);
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
