#include <clCmd.h>

// Needed for neopixels - even though completely handled in clPix.
#include <Adafruit_NeoPixel.h>
#include <clPix.h>

uint32_t tick; // global timer - pointers used later...

ClCmd clCmd = ClCmd();
ClPix clPix = ClPix(&tick, 5, 5); // 5's are also defined in ClPix - could be cleaner.

void setup() {
  clCmd.init(9600);
  clPix.init();
}



void loop() {

  
  // get a command from Serial.
  Command c = clCmd.getCmd();

  // set states below.
  if (c.name != "none") {
    // set new states
    Serial.println("Execute cmd: " + c.name);
    Serial.println("Arg1 " + c.arg1 + " Arg2 " + c.arg2 +" Arg3 " + c.arg3);

    clPix.update(c);
    // clServo.update(c);
  }

  // start counter loop again.
  tick = millis();
  
  // do stuff
  clPix.operate();
  // clServo.operate();

}
