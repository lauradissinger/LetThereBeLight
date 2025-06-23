#include <Servo.h>
#include <time.h>

const int PIN_SERVO = 5;
const unsigned long KEEP_ALIVE_IN_MS = 25 * 60 * 1000;

Servo lightSwitcher;
int   lightSwitcherPos = 0;
unsigned long lastKeepAliveStartTime = 0;

void setup() {
  // put your setup code here, to run once:
  lightSwitcher.attach(PIN_SERVO);

  // Set to the mid point to block the sensor and delay briefly, then we'll move out of the way again
  lightSwitcher.write(90);
  delay(3000);

  lightSwitcher.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long currentTime = millis();
  if (currentTime >= lastKeepAliveStartTime + KEEP_ALIVE_IN_MS) {
    // Handle rollover
    lastKeepAliveStartTime = currentTime;

    // Set to the mid point to block the sensor and delay briefly, then we'll move out of the way again
    lightSwitcher.write(90);
    delay(3000);

    lightSwitcherPos = (lightSwitcherPos + 180) % 360;
    lightSwitcher.write(lightSwitcherPos);
  }

}
