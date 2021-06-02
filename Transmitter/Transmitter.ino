#include"main.h"

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
