#include <Arduino.h>
#include <DS1307RTC.h>
#include <TimeLib.h>

void print2digits(int number);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("RTC Read Test");

  // built-in LED
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  tmElements_t tm;

  // print the current time
  if (!RTC.read(tm)) {
    if (RTC.chipPresent()) {
        Serial.println("The DS1307 is stopped.  Please run the SetTime");
        Serial.println("example to initialize the time and begin running.");
        Serial.println();
      } else {
        Serial.println("DS1307 read error!  Please check the circuitry.");
        Serial.println();
      }
      delay(9000);
  }
  
  if (tm.Hour == 7 && tm.Minute == 0 && tm.Second == 0) {
    // turn on LED
    // print the time:
    Serial.write(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    Serial.println();
    Serial.println("Start Servo Motor");
    delay(5000);
    Serial.write(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    Serial.println();
    Serial.println("Stop Servo Motor");
  }
  delay(1000);
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}
