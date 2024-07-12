// #include <serial.h>
// #include <Arduino.h>

#include <SoftwareSerial.h> 

// add the Rx to  D2 und Tx to  D3
SoftwareSerial mySerial(2, 3);   

// set pin for Aktivation button  D4 
#define aktivation_pin  4
// set the led pin to  13  witch  equals the build in led  
#define led_pin 13 
uint8_t max_threshold = 100;
uint8_t aktivation_threshold = 80; 
uint8_t inner_threshold;
uint8_t bus_hop_reduction=25;
uint8_t line_groth = 5;

// Trigger send on interrupt 
void Activation(){
  if ((inner_threshold>=aktivation_threshold )&&(inner_threshold+line_groth<max_threshold)){
     inner_threshold += line_groth;  
  }
  else{
   inner_threshold = aktivation_threshold; 
  }
  sendnetsteck(bus_hop_reduction); 
}

// send  reduced number.  
void sendnetsteck(int8_t livx){
  if (aktivation_threshold-livx > 0){
    mySerial.write(aktivation_threshold-livx);
    Serial.print("Msg Send:");
    Serial.println(aktivation_threshold-livx); 
  }

}
void setup() {
// forces the bus to  be not syncrone. 
  delay(random(0, 20));  

  // init the status led 
  pinMode(led_pin,OUTPUT);

  // init  sensor pin for that.  
  pinMode(aktivation_pin,INPUT);
  attachInterrupt(digitalPinToInterrupt(aktivation_pin), Activation, RISING);
  
  // start debugging serial 
  Serial.begin(9600);

  // start comm bus for this projekt. 
  mySerial.begin(38400);
}


void loop() {

// slow system down to make it capable to see what happends. 

delay(100);

// time based Reduction of  aktivation_threshold 

  if (aktivation_threshold) aktivation_threshold--; 
  
  // show the signals on build in  
  analogWrite(led_pin,aktivation_threshold);
  
     
  while (mySerial.available()){
   uint8_t msg = mySerial.read();
   Serial.print("recived msg:");
   Serial.println(msg);    
   if (msg <= max_threshold){
      if  ( msg  >=  aktivation_threshold ){
        aktivation_threshold= msg;
        sendnetsteck(bus_hop_reduction); 
      }
   }
  } 
}