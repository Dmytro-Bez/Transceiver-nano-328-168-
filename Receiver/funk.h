#ifndef funk_h
#define funk_h

#include"var.h"

void sent_dev();
void pwm_send();
void receive_the_data();
void init_channel();

void sent_dev(){
  ch1_value = map(received_data.ch1,0,255,1000,2000);     //Використання змін.резисторів
  ch2_value = map(received_data.ch2,0,255,1000,2000);
  ch3_value = map(received_data.ch3,0,255,1000,2000);
  ch4_value = map(received_data.ch4,0,255,1000,2000);
  ch5_value = map(received_data.ch5,0,1,1000,2000);       //Використання кнопок
  ch6_value = map(received_data.ch6,0,1,1000,2000);
  ch7_value = map(received_data.ch7,0,255,1000,2000);
  pwm_send();
}

void pwm_send(){
  channel_1.writeMicroseconds(ch1_value);                 //Створіть ШІМ-сигнали
}

void receive_the_data(){
  while(radio.available()) {
    radio.read(&received_data, sizeof(Received_data));
    lastRecvTime = millis();                              //Тут ми отримуємо дані
  }
}

void init_channel(){
  channel_1.attach(2);
}

#endif
