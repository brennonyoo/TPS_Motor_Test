#include <Arduino.h>
#include <IntervalTimer.h>

// pin definitions
constexpr uint8_t STEP_N_PIN = 2;
constexpr uint8_t DIR_N_PIN  = 3;
constexpr uint8_t EN_N_PIN   = 4;

constexpr uint8_t DM_OFF = HIGH;
constexpr uint8_t DM_ON  = LOW;

IntervalTimer stepTimer;

constexpr uint32_t STEP_PULSE_LOW_US = 5;

void stepISR() {

  digitalWriteFast(STEP_N_PIN, DM_ON);
  delayMicroseconds(STEP_PULSE_LOW_US);
  digitalWriteFast(STEP_N_PIN, DM_OFF);

}

void setSpeedSPS(float sps) {
  if (sps <= 0) {
    stepTimer.end();
    digitalWriteFast(STEP_N_PIN, DM_OFF);
    return;

  }

  float period_us = 1e6f / sps;
  stepTimer.begin(stepISR, period_us);
}

void enableDriver(bool enable) {
  digitalWriteFast(EN_N_PIN, enable ? DM_ON : DM_OFF);
}

void setDirection(bool forward) {
  digitalWriteFast(DIR_N_PIN, forward ? DM_ON : DM_OFF );
}

void setup() {
  pinMode(STEP_N_PIN, OUTPUT);
  pinMode(DIR_N_PIN, OUTPUT);
  pinMode(EN_N_PIN, OUTPUT);

  digitalWriteFast(STEP_N_PIN, DM_OFF);
  digitalWriteFast(DIR_N_PIN, DM_OFF);
  digitalWriteFast(EN_N_PIN, DM_OFF);

  Serial.begin(115200);
  delay(500);

  enableDriver(true);

}

void loop() {
  setDirection(true);
  setSpeedSPS(400);
  delay(3000);

  setSpeedSPS(0);
  delay(1000);

  setDirection(false);
  setSpeedSPS(400);
  delay(3000);

  setSpeedSPS(0);
  delay(2000);
  
}
