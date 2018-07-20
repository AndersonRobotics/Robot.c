#include <stdio.h>
#include <gpio.h>

DigitalChip* init_digital () {
}

AnalogChip* init_analog () {
}


DigitalLine* export_digital (DigitalChip* chip, int line) {
}

AnalogLine* export_analog (AnalogChip* chip, int line) {
}


void remove_digital (DigitalChip* chip, int line) {
}

void remove_analog (AnalogChip* chip, int line) {
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