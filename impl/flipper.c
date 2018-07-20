#include <stdio.h>
#include <stdbool.h>
#include <gpio.h>
#include <flipper.h>

Flipper* init_flipper () {
  DigitalLine* launch = export_digital(digital(), 19);
  DigitalLine* retract = export_digital(digital(), 20);

  set_output(launch);
  set_output(retract);

  set_low(launch);
  set_low(retract);

  return &(Flipper) {
    .lanch = launch,
    .retract = retract
  };
}


void launch (Flipper* flipper) {
  set_low(flipper->retract);
  set_high(flipper->launch);
}

void retract (Flipper* flipper) {
  set_low(flipper->launch);
  set_high(flipper->retract);
}