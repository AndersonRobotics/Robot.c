#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <gpio.h>
#include <chassis.h>
#include <flipper.h>
#include <robot.h>

int main () {
  Robot* robot = init_robot();

  set_left_speed(robot->chassis, 1000);
  set_right_speed(robot->chassis, 1000);

  return sleep(10);
}