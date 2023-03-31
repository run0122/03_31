#include <TimerOne.h>

const int ledPin = 11;
const int analogPin = A0;
const int buzzerPin = 10;

void setup() {
  Serial.begin(9600);
  Timer1.initialize();
  Timer1.pwm(buzzerPin, 0);
  Timer1.setPwmDuty(buzzerPin, 100);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorInput = analogRead(analogPin);
  // sensorInput = map(sensorInput, 0, 1023, 0, 255);
  Serial.println((String) "sensorInput = " + sensorInput);

  //if (sensorInput > 80 && sensorInput < 100) {
  if (sensorInput > 100 && sensorInput < 300) {
    // analogWrite(ledPin, sensorInput);
    digitalWrite(ledPin, HIGH);
    // Timer1.setPwmDuty(buzzerPin, sensorInput);
    // Timer1.setPeriod(1000000/sensorInput);
    //analogWrite(buzzerPin, sensorInput);
    // delay(500);
    tone(buzzerPin, sensorInput);
  } else {
    digitalWrite(ledPin, LOW);
    // Timer1.setPwmDuty(buzzerPin, 0);
    tone(buzzerPin, 0);
  }
}
