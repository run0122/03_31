# 03.31
 
<hr/>

## 1. Piezo Buzzer

PWM을 이용해서 LED와 서보모터를 제어하는 법에 이어서 피에조 부저를 제어하는 법도 배웠습니다. Timer1.setPeriod()함수를 통해 주파수에 따른 주기를 변경하여 음의 높낮이를 변경할 수 있습니다. 예를 들어, 262는 '4옥타브 도'음의 주파수 이며, 294는 '4옥타브 레'의 주파수입니다. Timer1.setPeriod(1000000/262)를 할 경우 부저에서 도 라는 음이 출력되고, Timer1.setPeriod(1000000/294)를 할 경우 레가 출력됩니다.

버튼을 이용해서 피에조 부저를 제어하려고 했으나 소스코드가 작동은 하지만 채터링 현상으로 인해 원하는 구현이 완벽히 되지는 않았습니다. 버튼을 다시 눌렀을 때는 멜로디가 해제되도록 구현하려고 했으나, for문 안의 브레이크 구간이 제대로 작동하지 않았습니다.

<hr/>

## 2. map 함수

map(value, fromLow, fromHigh, toLow, toHigh)

value : 매핑할 값.
value의 fromLow에서 fromHigh 사이의 값을 toLow에서 toHigh 사이의 값으로 매핑해줍니다.

y = map(x, 1, 50, 50, 1);
이런 식으로 숫자 범위를 뒤집을 수도 있습니다.

예를 들어

```
void loop() {
  int val = analogRead(0);
  val = map(val, 0, 1023, 0, 255);
  analogWrite(9, val);
}
```

이런식으로 사용하면 0에서 1023의 값이 0에서 255로 매핑 됩니다.

<hr/>

## 3. ADC

아날로그 신호를 디지털 신호로 변환하는 법을 배웠습니다. A0~A5가 아날로그 신호에 이용되는 핀이며, 가변저항의 값을 통해서 LED의 밝기를 제어할 수 있었습니다.

|함수|기능|설명|
|------|:---:|---|
|const int analogPin = A0;|A0에 핀 설정||
|analogRead()|아날로그 신호 읽기|sensorInput = analogRead(analogPin);|
|analogWrite()|아날로그 신호 쓰기|analogWrite(ledPin, sensorInput);|

<hr/>
