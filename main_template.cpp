#include <Arduino.h>
#include "avr8-stub.h"
#include "app_api.h"

// Put your setup code here, to run once:
void setup() {
  debug_init();

  // Test example
  pinMode(LED_BUILTIN, OUTPUT);
}

// Put your main code here, to run repeatedly:
void loop() {
  
  // Test example
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
