/*
  Switch
  Hold switch to change the state of the LED and the relay
*/

// Variables
int trigger = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(0, INPUT);    // switch
  pinMode(12, OUTPUT);  // relay
  pinMode(13, OUTPUT);  // LED
}

// the loop function runs over and over again forever
void loop() {
  trigger = digitalRead(0);
  if(trigger){
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(12, HIGH);
    delay(1000);              // wait for a second
  } else {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    delay(1000);
  }  
}
