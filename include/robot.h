#pragma once

struct Robot {
  Chassis* chassis;
  Flipper* flipper;
};


struct Robot* init_robot ();


typedef struct Robot Robot;