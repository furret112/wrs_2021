/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp-now-many-to-one-esp8266-nodemcu/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <espnow.h>
//#include "ESP_MICRO.h" //Include the micro library 

SoftwareSerial NodeMCU(D2,D3);

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
    int id;
    //int data_receive;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// Create a structure to hold the readings from each board
struct_message board1;
struct_message board2;

// Create an array with all the structures
struct_message boardsStruct[2] = {board1,board2};

// Callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac_addr, uint8_t *incomingData, uint8_t len) 
{
  char macStr[18];

  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
           
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.printf("\nBoard ID %u", myData.id);
  NodeMCU.print(myData.id);
  //NodeMCU.println("\n");
  
  // Update the structures with the new incoming data
  //boardsStruct[myData.id-1].data_receive = myData.data_receive;
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Initialize tx rx
  NodeMCU.begin(4800);
  pinMode(D2,INPUT);
  pinMode(D3,OUTPUT);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
}

void loop(){
  // Access the variables for each board
}
