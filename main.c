#include <stdio.h>
#include <stdbool.h>
#include <gpio.h>
#include <chassis.h>
#include <flipper.h>
#include <robot.h>

int main () {
  Robot* robot = init_robot();
  return 0;
}