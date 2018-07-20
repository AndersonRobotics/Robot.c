#pragma once

struct Flipper {
  DigitalLine* open;
  DigitalLine* close;
};


struct Flipper* init_flipper ();

void launch (struct Flipper*);
void retract (struct Flipper*);


typedef struct Flipper Flipper;