#include"main.h"

void reset_the_Data() {
  received_data.ch1 = 0;      
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
