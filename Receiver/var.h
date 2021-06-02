#ifndef var_h
#define var_h

#include"lib.h"

Servo channel_1;
Servo channel_2;
Servo channel_3;
Servo channel_4;
Servo channel_5;
Servo channel_6;
Servo channel_7;

int ch1_value = 0;
int ch2_value = 0;
int ch3_value = 0;
int ch4_value = 0;
int ch5_value = 0;
int ch6_value = 0;
int ch7_value = 0;

struct Received_data {
  byte ch1;
  byte ch2;
  byte ch3;
  byte ch4;
  byte ch5;
  byte ch6;
  byte ch7;
};

Received_data received_data;

const uint64_t pipeIn = 0xE8E8F0F0E1LL;
unsigned long lastRecvTime = 0;
RF24 radio(7, 8);

#endif
