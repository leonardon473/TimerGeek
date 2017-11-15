#include <TimerGeek.h>
TimerGeek Timer;

void blink() {
  Serial.println("Fin");
}

char c = 'A';

void setup() {
  Serial.begin(9600);
  Timer.funtion(4000, blink, false);
  pinMode(13, OUTPUT);
}

void loop() {
  while (Serial.available()) {
    delay(10);
    if (Serial.available()) {
      c = Serial.read();
    }
  }
  if (c == 'I') {
    c = 'A';
    //Serial.println(respuestaPD0);
    Serial.println("Inicio");
    Timer.trigger();
  }
  if (c == 'M') {
    c = 'A';
    Serial.println("Medio");
  }  

  Timer.timerFuntionOnce();
}