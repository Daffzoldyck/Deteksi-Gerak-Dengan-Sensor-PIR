#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_DEVICE_NAME "Security Alert"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

#define PIRPIN 27

int pirState = LOW;
int val = 0;

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    Blynk.logEvent("motion_detected", "Gerakan terdeteksi di ruangan!");
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(PIRPIN, INPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  val = digitalRead(PIRPIN);
  if (val == HIGH) {
    if (pirState == LOW) {
      Serial.println("Gerakan terdeteksi!");
      Blynk.logEvent("motion_detected", "Gerakan terdeteksi di ruangan!");
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH) {
      Serial.println("Tidak ada gerakan.");
      pirState = LOW;
    }
  }
  Blynk.run();
}