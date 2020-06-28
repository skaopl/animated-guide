/*
     Wall switches
     schema:

      GND   GND    GND   GND
     ----- -----  ----- -----
    |     |     ||     |     |
    |     |     ||     |     |
    |  4  |  3  ||  2  |  1  |
     ----- -----  ----- -----
     PIN 4 PIN 5  PIN 6 PIN 7
    
*/

#include "OneButton.h"

#define MY_DEBUG
#define MY_RADIO_RF24
#define MY_NODE_ID 202
#include <MySensors.h>

OneButton button_1(7, true);
OneButton button_2(6, true);
OneButton button_3(5, true);
OneButton button_4(4, true);

MyMessage msgS1(1, V_TRIPPED);
MyMessage msgS2(2, V_TRIPPED);
MyMessage msgS3(3, V_TRIPPED);
MyMessage msgS4(4, V_TRIPPED);
MyMessage msgS5(5, V_TRIPPED);
MyMessage msgS6(6, V_TRIPPED);
MyMessage msgS7(7, V_TRIPPED);
MyMessage msgS8(8, V_TRIPPED);
MyMessage msgS9(9, V_TRIPPED);
MyMessage msgS10(10, V_TRIPPED);
MyMessage msgS11(11, V_TRIPPED);
MyMessage msgS12(12, V_TRIPPED);

void setup()
{ 
  button_1.attachClick(click_action, 1);
  button_1.attachDoubleClick(click_action, 2);
  button_1.attachLongPressStop(click_action, 3);

  button_2.attachClick(click_action, 4);          
  button_2.attachDoubleClick(click_action, 5);  
  button_2.attachLongPressStop(click_action, 6);

  button_3.attachClick(click_action, 7);        
  button_3.attachDoubleClick(click_action, 8);    
  button_3.attachLongPressStop(click_action, 9);  

  button_4.attachClick(click_action, 10);        
  button_4.attachDoubleClick(click_action, 11);  
  button_4.attachLongPressStop(click_action, 12);
}

void presentation()  {
  sendSketchInfo("Panel Salon", "1.1");

  // 4 buttons * 3 functions = 12 children
  for (int i = 1; i <= 12; i++) {
    present(i, S_MOTION);
  }
}

void loop()
{
  button_1.tick();
  button_2.tick();
  button_3.tick();
  button_4.tick();
  delay(10);
}


void click_action(int btnId) {
  switch (btnId) {
    case 1:
        send(msgS1.set("1"), true);
        delay(250);
        send(msgS1.set("0"), true);
        break;
    case 2:
        send(msgS2.set("1"), true);
        delay(250);
        send(msgS2.set("0"), true);
        break;
    case 3:
        send(msgS3.set("1"), true);
        delay(250);
        send(msgS3.set("0"), true);
        break;
    case 4:
        send(msgS4.set("1"), true);
        delay(250);
        send(msgS4.set("0"), true);
        break;
    case 5:
        send(msgS5.set("1"), true);
        delay(250);
        send(msgS5.set("0"), true);
        break;
    case 6:
        send(msgS6.set("1"), true);
        delay(250);
        send(msgS6.set("0"), true);
        break;
    case 7:
        send(msgS7.set("1"), true);
        delay(250);
        send(msgS7.set("0"), true);
        break;
    case 8:
        send(msgS8.set("1"), true);
        delay(250);
        send(msgS8.set("0"), true);
        break;
    case 9:
        send(msgS9.set("1"), true);
        delay(250);
        send(msgS9.set("0"), true);
        break;
    case 10:
        send(msgS10.set("1"), true);
        delay(250);
        send(msgS10.set("0"), true);
        break;
    case 11:
        send(msgS11.set("1"), true);
        delay(250);
        send(msgS11.set("0"), true);
        break;
    case 12:
        send(msgS12.set("1"), true);
        delay(250);
        send(msgS12.set("0"), true);
        break;
  }
}