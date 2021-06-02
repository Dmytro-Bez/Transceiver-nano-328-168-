#ifndef funk_h
#define funk_h

#include"var.h"

void setup_input_dev();
void sent_dev();

void setup_input_dev(){
  /*Якщо ваш канал перевернутий, просто поміняйте місцями 0 на 255 на 255 на 0 нижче
   ПРИКЛАД:
  Normal:    data.ch1 = map( analogRead(A0), 0, 1024, 0, 255);
  Reversed:  data.ch1 = map( analogRead(A0), 0, 1024, 255, 0);  */
  sent_data.ch1 = map(analogRead(A0), 0, 1024, 0, 255);                 //Описуємо резистори чи тумблери для керування
}

void sent_dev(){
  sent_data.ch1 = 0;                                                  //Скиньте значення кожного каналу
}

#endif
