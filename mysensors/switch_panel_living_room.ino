/*
     Wall switches
     schema:

      GND   GND    GND   GND
     ----- -----  ----- -----
    |     |     ||     |     |
    |     |     ||     |     |
    | 2_2 | 2_1 || 1_2 | 1_1 |
     ----- -----  ----- -----
     PIN 4 PIN 5  PIN 6 PIN 7
    
*/

#include "OneButton.h"

//#define MY_DEBUG
#define MY_RADIO_RF24
#define MY_NODE_ID 202
#include <MySensors.h>

OneButton button_1_1(7, true);
OneButton button_1_2(6, true);
OneButton button_2_1(5, true);
OneButton button_2_2(4, true);

MyMessage msgS1(1, V_STATUS);
MyMessage msgS2(2, V_STATUS);
MyMessage msgS3(3, V_STATUS);
MyMessage msgS4(4, V_STATUS);
MyMessage msgS5(5, V_STATUS);
MyMessage msgS6(6, V_STATUS);
MyMessage msgS7(7, V_STATUS);
MyMessage msgS8(8, V_STATUS);
MyMessage msgS9(9, V_STATUS);
MyMessage msgS10(10, V_STATUS);
MyMessage msgS11(11, V_STATUS);
MyMessage msgS12(12, V_STATUS);

void setup()
{ 
  button_1_1.attachClick(click_action, 1);
  button_1_1.attachDoubleClick(click_action, 2);
  button_1_1.attachLongPressStop(click_action, 3);

  button_1_2.attachClick(click_action, 4);          
  button_1_2.attachDoubleClick(click_action, 5);  
  button_1_2.attachLongPressStop(click_action, 6);

  button_2_1.attachClick(click_action, 7);        
  button_2_1.attachDoubleClick(click_action, 8);    
  button_2_1.attachLongPressStop(click_action, 9);  

  button_2_2.attachClick(click_action, 10);        
  button_2_2.attachDoubleClick(click_action, 11);  
  button_2_2.attachLongPressStop(click_action, 12);
}

void presentation()  {
  sendSketchInfo("Panel Salon", "1.0");

  // 4 buttons * 3 functions = 12 children
  for (int i = 1; i <= 12; i++) {
    present(i, S_BINARY);
  }
}

void loop()
{
  button_1_1.tick();
  button_1_2.tick();
  button_2_1.tick();
  button_2_2.tick();
  delay(10);
}


void click_action(int btnId) {
  switch (btnId) {
    case 1:
        send(msgS1.set("1"));
        break;
    case 2:
        send(msgS2.set("1"));
        break;
    case 3:
        send(msgS3.set("1"));
        break;
    case 4:
        send(msgS4.set("1"));
        break;
    case 5:
        send(msgS5.set("1"));
        break;
    case 6:
        send(msgS6.set("1"));
        break;
    case 7:
        send(msgS7.set("1"));
        break;
    case 8:
        send(msgS8.set("1"));
        break;
    case 9:
        send(msgS9.set("1"));
        break;
    case 10:
        send(msgS10.set("1"));
        break;
    case 11:
        send(msgS11.set("1"));
        break;
    case 12:
        send(msgS12.set("1"));
        break;
  }
}