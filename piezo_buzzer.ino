#include <TimerOne.h>

const int BUZZER = 10;

const int melody[] = {
  262, 294, 330, 249, 393, 440, 494, 523
};

void setup() {
  Timer1.initialize();
  Timer1.pwm(BUZZER, 0);

  // Timer1.setPwmDuty(BUZZER, 512);

  Timer1.setPwmDuty(BUZZER, 100);

  // Timer1.setPeriod(1000000/262);

  // for(int cnt=0; cnt<=2;cnt++){
  //   Timer1.setPeriod(1000000/262);
  //   delay(1000);
  //   Timer1.setPeriod(1000000/294);
  //   delay(1000);
  // }

  for (int note = 0; note < 8; note++) {
    Timer1.setPeriod(1000000 / melody[note]);
    delay(500);
  }

  // delay(3000);

  Timer1.setPwmDuty(BUZZER, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
}
