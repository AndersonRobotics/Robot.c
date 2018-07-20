#pragma once

struct Chassis {
  AnalogLine* left_speed;
  AnalogLine* right_speed;
  DigitalLine* left_reverse;
  DigitalLine* right_reverse;
};


struct Chassis* init_chassis ();

void set_left_speed (struct Chassis*, int);
void set_right_speed (struct Chassis*, int);

void set_left_reverse (struct Chassis*, bool);
void set_right_reverse (struct Chassis*, bool);


typedef struct Chassis Chassis;