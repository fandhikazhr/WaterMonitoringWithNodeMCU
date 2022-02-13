
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID ""    // fill with your's project id templates
#define BLYNK_DEVICE_NAME ""    // fill with your's project name on blynk 

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"
BlynkTimer timer;
WidgetLED led1(V1);
#define buzzer D0
#define triggerPin D1
#define echoPin D2
long duration, jarak;

void kondisi()
{
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  jarak = (duration/2) / 29.1;
  Serial.print("Jarak Sensor : ");
  Serial.println(jarak);
  if(jarak < 10)
  {
    digitalWrite(buzzer, HIGH);
    led1.off();
    delay(10000);
    digitalWrite(buzzer, LOW);
  }
  else
  {
    digitalWrite(buzzer, LOW);
    delay(1000);
  } 
}

void setup()
{
  Serial.begin(9600);
  BlynkEdgent.begin();
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  timer.setInterval(10L, kondisi);
}

void loop() {
  BlynkEdgent.run();
  timer.run();
}
