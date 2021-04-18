#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

void setup_input_dev();
void sent_dev();

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
Data_to_be_sent sent_data;                                            //Створіть змінну з наведеною вище структурою та назвіть її sent_data

void setup(){
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(my_radio_pipe);
  
  sent_dev();
}
void loop(){
  setup_input_dev();
  radio.write(&sent_data, sizeof(Data_to_be_sent));                   //Починаємо передачу
}

void setup_input_dev(){
  /*Якщо ваш канал перевернутий, просто поміняйте місцями 0 на 255 на 255 на 0 нижче
   ПРИКЛАД:
  Normal:    data.ch1 = map( analogRead(A0), 0, 1024, 0, 255);
  Reversed:  data.ch1 = map( analogRead(A0), 0, 1024, 255, 0);  */
  sent_data.ch1 = map( analogRead(A0), 0, 1024, 0, 255);              //Описуємо ресичтори чи тумблери для керування
  sent_data.ch2 = map( analogRead(A1), 0, 1024, 0, 255);
  sent_data.ch3 = map( analogRead(A2), 0, 1024, 0, 255);
  sent_data.ch4 = map( analogRead(A3), 0, 1024, 0, 255);
  sent_data.ch5 = digitalRead(2);                                     //Використання кнопок чи тумблерів
  sent_data.ch6 = digitalRead(3);
  sent_data.ch1 = map( analogRead(A4), 0, 1024, 0, 255);              //Для прикладу роботи я використав змін. резистор
}

void sent_dev(){
  sent_data.ch1 = 0;                                                  //Скиньте значення кожного каналу
//  sent_data.ch2 = 127;                                              //Встановлення середніх значень для кнопок або змінних резисторів
//  sent_data.ch3 = 127;
//  sent_data.ch4 = 127;
//  sent_data.ch5 = 0;
//  sent_data.ch6 = 0;
//  sent_data.ch7 = 0;
}
