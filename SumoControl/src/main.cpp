#include <Arduino.h>
#include <VirtualWire.h>

const int dataPin = 9;

void setup(){
    Serial.begin(9600);
    vw_setup(2000);
    vw_set_tx_pin(dataPin);
}

void loop(){
    while (Serial.avaible() > 0){
        char data[1];
        data[0] = Serial.read();
        vw_send((uiny8_t*)data,sizeof(data));
        vw_wait_tx();
    }
    delay(200);
}