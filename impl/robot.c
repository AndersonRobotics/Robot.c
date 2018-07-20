#include <stdio.h>
#include <stdbool.h>
#include <gpio.h>
#include <chassis.h>
#include <flipper.h>
#include <robot.h>

Robot* init_robot () {
  return &(Robot) {
    .chassis = init_chassis(),
    .flipper = init_flipper()
  };
}