#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

void sent_dev();
void pwm_send();
void receive_the_data();
void init_channel();

const uint64_t pipeIn = 0xE8E8F0F0E1LL;
unsigned long lastRecvTime = 0;
RF24 radio(7, 8);

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

void reset_the_Data() {
  received_data.ch1 = 0;      
//  received_data.ch2 = 127;
//  received_data.ch3 = 127;
//  received_data.ch4 = 127;
//  received_data.ch5 = 0;
//  received_data.ch6 = 0;
//  received_data.ch7 = 0;
}

void setup(){
  init_channel();
  reset_the_Data();

  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);  
  radio.openReadingPipe(1,pipeIn);
  radio.startListening();
}

void loop(){
  receive_the_data();
  unsigned long now = millis();
  if(now - lastRecvTime > 1000){
    reset_the_Data();
  }
  sent_dev();
}

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
//  channel_2.writeMicroseconds(ch2_value);  
//  channel_3.writeMicroseconds(ch3_value);  
//  channel_4.writeMicroseconds(ch4_value);  
//  channel_5.writeMicroseconds(ch5_value);  
//  channel_6.writeMicroseconds(ch6_value);  
//  channel_7.writeMicroseconds(ch7_value);
}

void receive_the_data(){
  while(radio.available()) {
    radio.read(&received_data, sizeof(Received_data));
    lastRecvTime = millis();                              //Тут ми отримуємо дані
  }
}

void init_channel(){
  channel_1.attach(2);
//  channel_2.attach(3);
//  channel_3.attach(4);
//  channel_4.attach(5);
//  channel_5.attach(6);
//  channel_6.attach(7);
//  channel_7.attach(8);
}
