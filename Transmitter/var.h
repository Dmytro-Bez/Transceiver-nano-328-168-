#ifndef var_h
#define var_h

#include"lib.h"

const uint64_t my_radio_pipe = 0xE8E8F0F0E1LL;                        //Пам'ятайте, що цей код повинен бути однаковим для приймача
RF24 radio(7, 8);                                                     //Встановіть шпильки CE та CSN

struct Data_to_be_sent{                                               //Розмір цієї структури не повинен перевищувати 32 байт
  byte ch1;
  byte ch2;
  byte ch3;
  byte ch4;
  byte ch5;
  byte ch6;
  byte ch7;
};
Data_to_be_sent sent_data;   

#endif
