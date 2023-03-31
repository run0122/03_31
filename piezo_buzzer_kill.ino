const int BUTTON_PIN = 2;
const int BUZZER_PIN = 10;

int onoff = 0;

const float songSpeed = 1.0;

#define NOTE_D3 147
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_D_black_5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 784
#define NOTE_A_black_5 830
#define NOTE_A5 880
#define NOTE_B5 988
#define NOTE_D6 1175

#define rest 10

int notes[] = {
  NOTE_D3, 0, NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, 0,
  0, NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, 0,
  NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, 0, NOTE_D_black_5, 0,
  NOTE_A5, 0, NOTE_D5, 0, NOTE_D_black_5, 0, NOTE_A5, 0,

  NOTE_D3, 0, NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, 0,
  0, NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, 0,
  NOTE_D5, 0, NOTE_D5, 0, NOTE_A5, 0, NOTE_A_black_5, 0,
  NOTE_D5, 0, NOTE_A5, 0, NOTE_A_black_5, 0, NOTE_D5, 0,

  NOTE_D3, 0, NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, 0,
  0, NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, 0,
  NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, 0, NOTE_D_black_5, 0,
  NOTE_A5, 0, NOTE_D5, 0, NOTE_D_black_5, 0, NOTE_A5, 0,

  NOTE_D3, 0, NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, 0,
  0, NOTE_D5, 0, NOTE_D5, 0, NOTE_D5, 0,
  NOTE_D5, 0, NOTE_D5, 0, NOTE_A5, 0, NOTE_A_black_5, 0,
  NOTE_D5, 0, NOTE_A5, 0, NOTE_A_black_5, 0, NOTE_D5,

  NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,
  NOTE_E5, 0, NOTE_E5, 0, NOTE_D5, 0,

  NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,
  NOTE_E5, 0, NOTE_E5, 0, NOTE_D5, 0,

  NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_D6, 0,

  NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_D6, 0,

  NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_D6, 0,

  NOTE_D5, 0, NOTE_E5, 0, NOTE_F5, 0, NOTE_F5, 0,
  NOTE_E5, 0, NOTE_E5, 0, NOTE_D5, 0,

  NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,
  NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0, NOTE_D5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_D5, 0, NOTE_F5, 0, NOTE_F5, 0,
  NOTE_D5, 0, NOTE_F5, 0,

  NOTE_D5, 0, NOTE_D5, 0, NOTE_E5, 0, NOTE_F5, 0,
  NOTE_D5, 0, NOTE_E5, 0, NOTE_F5, 0,
  NOTE_D5, 0,

  NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,

  NOTE_A5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,
  NOTE_A5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_F5, 0,

  NOTE_A5, 0, NOTE_F5, 0, NOTE_F5, 0, NOTE_D5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_D5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_D5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_D5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_D5, 0,

  NOTE_E5, 0, NOTE_E5, 0, NOTE_E5, 0,
  NOTE_F5, 0, NOTE_F5, 0, NOTE_D5, 0,
  NOTE_G5, 0, NOTE_G5, 0,
  NOTE_A5, 0,
  NOTE_F5, 0,

  //    NOTE_D5,0,NOTE_F5,0,NOTE_F5,0,


};
// Durations (in ms) of each music note of the song
// Quarter Note is 250 ms when songSpeed = 1.0
int durations[] = {
  200, 70, 100, 80, 100, 80, 400, rest,
  200, 100, 80, 100, 80, 400, 70,
  200, rest, 125, rest, 175, rest, 175, rest,
  175, rest, 175, rest, 175, rest, 50, 5,

  200, 70, 100, 80, 100, 80, 400, rest,
  200, 100, 80, 100, 80, 450, 70,
  200, rest, 125, rest, 175, rest, 175, rest,
  175, rest, 175, rest, 175, rest, 175, 5,

  200, 70, 100, 80, 100, 80, 400, rest,
  200, 100, 80, 100, 80, 400, 70,
  200, rest, 125, rest, 175, rest, 175, rest,
  175, rest, 175, rest, 175, rest, 50, 5,

  200, 70, 100, 80, 100, 80, 400, rest,
  200, 100, 80, 100, 80, 450, 70,
  200, rest, 125, rest, 175, rest, 175, rest,
  175, rest, 175, rest, 175, rest, 175,

  375, rest, 150, rest, 375, rest, 125, 50,
  450, rest, 375, rest, 125, rest, 375, rest, 125, rest,
  375, rest, 125, rest, 450, 50,

  375, rest, 125, rest, 375, rest, 125, 50,
  450, rest, 375, rest, 125, rest, 375, rest, 125, rest,
  375, rest, 125, rest, 450, 50,

  375, rest, 125, rest, 375, rest, 125, 50,
  375, rest, 125, rest, 450, rest,

  375, rest, 125, rest, 375, rest, 125, 50,
  375, rest, 125, rest, 450, rest,

  375, rest, 125, rest, 375, rest, 125, 50,
  375, rest, 125, rest, 450, rest,

  375, rest, 125, rest, 375, rest, 125, rest,
  375, rest, 125, rest, 450, 100,

  150, rest, 150, rest, 150, rest,
  150, rest, 150, rest, 150, rest,
  375, 150, 150, rest, 150, rest, 150, rest,
  150, rest, 150, rest, 150, rest, 375, 150,
  150, rest, 150, rest, 150, rest, 150, rest, 150, rest,
  150, rest, 450, 70,

  150, rest, 150, rest, 150, rest, 150, rest,
  150, rest, 150, rest, 150, rest,
  450, rest,

  150, rest, 150, rest, 150, rest,
  150, rest, 150, rest, 150, rest,
  150, rest, 150, rest, 150, rest,

  450, rest,
  150, rest, 150, rest, 150, rest,
  450, rest,
  150, rest, 150, rest, 150, rest, 150, rest,

  450, rest, 150, rest, 150, rest, 150, rest,
  150, rest, 150, rest, 150, rest,
  150, rest, 150, rest, 150, rest,
  150, rest, 150, rest, 150, rest,
  150, rest, 150, rest, 150, rest,

  150, rest, 150, rest, 150, rest,
  150, rest, 150, rest, 150, rest,
  150, rest, 150, rest,
  150, rest,
  150, rest,

  //    375,rest,100,rest,100,rest,


};
void setup() {
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);  // read new state

  if (buttonState == HIGH) {  // button is pressed
    onoff++;
    buzzer();
  }
}

void buzzer() {
  const int totalNotes = sizeof(notes) / sizeof(int);
  if (onoff % 2 == 1) {
      break;
  }
  for (int i = 0; i < totalNotes; i++) {
    const int currentNote = notes[i];
    float wait = durations[i] / songSpeed;
    // Play tone if currentNote is not 0 frequency, otherwise pause (noTone)
    if (currentNote != 0) {
      tone(BUZZER_PIN, notes[i], wait);  // tone(pin, frequency, duration)
    } else {
      noTone(BUZZER_PIN);
    }
    // delay is used to wait for tone to finish playing before moving to next loop
    delay(wait);
  }
}