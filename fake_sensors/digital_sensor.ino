#include <TimerOne.h>

int outputPin = 10;

void setup() {
  Serial.begin(115200);
  pinMode(outputPin, OUTPUT);
  int period = hertzToPeriod(50);
  Timer1.initialize(period);
  Timer1.attachInterrupt(callback);
}

void callback()
{
  digitalWrite(outputPin, digitalRead(outputPin) ^ 1);
}

void loop() {
  uint32_t i;
  for (i=50; i<150; i++) {
    int period = hertzToPeriod(i);
    int dc = dutyCycle(5, period);
    Timer1.pwm(outputPin, dc, period);
    long endTime = millis() + 2000;
    while(endTime >= millis()){
    //Serial.println(digitalRead(outputPin));
    }
  }
}

// in microseconds
int hertzToPeriod(int hertz) {
  return 1000000/hertz;
}

// pulseWidth in milliseconds
int dutyCycle(int pulseWidth, int period) {
  return (pulseWidth*1000L*1024L)/period;
  
}
