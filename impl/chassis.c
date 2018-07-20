#include <stdio.h>
#include <stdbool.h>
#include <gpio.h>
#include <chassis.h>

Chassis* init_chassis () {
  AnalogLine* left_speed = export_analog(analog(), 5);
  AnalogLine* right_speed = export_analog(analog(), 6);
  DigitalLine* left_reverse = export_digital(digital(), 17);
  DigitalLine* right_reverse = export_digital(digital(), 18);

  set_period(left_speed, 10000000);
  set_period(right_speed, 10000000);

  set_duty(left_speed, 0);
  set_duty(right_speed, 0);

  set_output(left_reverse);
  set_output(right_reverse);

  set_high(left_reverse);
  set_low(right_reverse);

  return &(Chassis) {
    .left_speed = left_speed,
    .right_speed = right_speed,
    .left_reverse = left_reverse,
    .right_reverse = right_reverse
  };
}


void set_left_speed (Chassis* chassis, int speed) {
  set_duty(chassis->left_speed, speed);
}

void set_right_speed (Chassis* chassis, int speed) {
  set_duty(chassis->right_speed, speed);
}


void set_left_reverse (Chassis* chassis, bool reverse) {
  if (reverse) set_high(chassis->left_reverse);
  else set_low(chassis->left_reverse);
}

void set_right_reverse (Chassis* chassis, bool reverse) {
  if (reverse) set_high(chassis->right_reverse);
  else set_low(chassis->right_reverse);
}