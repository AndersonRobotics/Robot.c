#pragma once

struct DigitalChip {
  FILE* export_handle;
  FILE* remove_handle;
};

struct AnalogChip {
  FILE* export_handle;
  FILE* remove_handle;
};

struct DigitalLine {
  FILE* value_handle;
  FILE* direc_handle; 
};

struct AnalogLine {
  FILE* period_handle;
  FILE* dCycle_handle;
};


struct DigitalLine* export_digital (struct DigitalChip*, int);
struct AnalogLine* export_analog (struct AnalogChip*, int);

void remove_digital (int);
void remove_analog (int);

void set_high (struct DigitalLine*);
void set_low (struct DigitalLine*);
void set_input (struct DigitalLine*);
void set_output (struct DigitalLine*);

void set_duty (struct AnalogLine*, int);
void set_period (struct AnalogLine*, int);


struct DigitalChip* digitalChip;
struct AnalogChip* analogChip;


typedef struct DigitalChip DigitalChip;
typedef struct AnalogChip AnalogChip;
typedef struct DigitalLine DigitalLine;
typedef struct AnalogLine AnalogLine;