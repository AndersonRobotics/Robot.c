#include <stdio.h>
#include <gpio.h>

DigitalChip* init_digital () {
  return &(DigitalChip) {
    .export_handle = fopen("/sys/class/gpio/export", O_WRONLY),
    .remove_handle = fopen("/sys/class/gpio/unexport", O_WRONLY)
  };
}

AnalogChip* init_analog () {
  return &(AnalogChip) {
    .export_handle = fopen("/sys/class/pwm/pwmchip0/export", O_WRONLY),
    .remove_handle = fopen("/sys/class/pwm/pwmchip0/unexport", O_WRONLY)
  };
}


DigitalLine* export_digital (DigitalChip* chip, int line) {
  fprintf(chip->export_handle, "%d", line);
  char value_path[30];
  char direc_path[35];

  snprintf(value_path, 30, "/sys/class/gpio/gpio%d/value", line);
  snprintf(direc_path, 35, "/sys/class/gpio/gpio%d/direction", line);

  return &(DigitalLine) {
    .value_handle = fopen(value_path, O_WRONLY),
    .direc_handle = fopen(direc_path, O_WRONLY)
  };
}

AnalogLine* export_analog (AnalogChip* chip, int line) {
  fprintf(chip->export_handle, "%d", line);
  char period_path[40];
  char dCycle_path[45];

  snprintf(period_path, 40, "/sys/class/pwm/pwmchip0/pwm%d/period", line);
  snprintf(dCycle_path, 45, "/sys/class/pwm/pwmchip0/pwm%d/duty_cycle", line);

  return &(AnalogLine) {
    .period_handle = fopen(period_path, O_WRONLY),
    .dCycle_handle = fopen(dCycle_path, O_WRONLY)
  };
}


void remove_digital (DigitalChip* chip, int line) {
  fprintf(chip->remove_handle, "%d", line);
}

void remove_analog (AnalogChip* chip, int line) {
  fprintf(chip->remove_handle, "%d", line);
}


void set_low (DigitalLine* line) {
}

void set_high (DigitalLine* line) {
}

void set_input (DigitalLine* line) {
}

void set_output (DigitalLine* line) {
}


void set_duty (AnalogLine* line) {
}

void set_period (AnalogLine* line) {
}


DigitalChip* digitalChip = init_digital();
AnalogChip* analogChip = init_analog();