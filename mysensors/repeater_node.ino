// Enable debug prints
//#define MY_DEBUG

// Enable repeater mode
#define MY_REPEATER_FEATURE

// Fixed Node ID
#define MY_NODE_ID 100

// Enable and select radio type attached
#define MY_RADIO_RF24
//#define MY_RADIO_NRF5_ESB
//#define MY_RADIO_RFM69
//#define MY_RADIO_RFM95

#include <MySensors.h>

void setup()
{
  Serial.begin(9600);
}

void presentation()
{
  // Send the sketch version information to the gateway and Controller
  sendSketchInfo("Repeater Node", "1.0");
}

void loop()
{
}