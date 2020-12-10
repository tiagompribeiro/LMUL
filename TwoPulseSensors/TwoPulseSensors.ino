
//  Variables
int PulseSensorPurplePin_0 = 0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED_0 = 11;   //  The on-board Arduion LED
int PulseSensorPurplePin_1 = 2;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED_1 = 10;   //  The on-board Arduion LED




int Signal_0;                // holds the incoming raw data. Signal value can range from 0-1024
int Signal_1;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold_0 = 510;            // Determine which Signal to "count as a beat", and which to ingore.
int Threshold_1 = 513;            // low sign
// val_x tension
int val_0 = 0;
int val_1 = 0;
int x_0 = 0;
int x_1 = 1;
// ground
//  0 508
//  1 508

// The SetUp Function:
void setup() {
  //pinMode(LED13,OUTPUT);         // pin that will blink to your heartbeat!
  //pinMode(LED12,OUTPUT);         // pin that will blink to your heartbeat!
  Serial.begin(9600);         // Set's up Serial Communication at certain speed.

}

// The Main Loop Function
void loop() {

  Signal_0 = analogRead(PulseSensorPurplePin_0);  // Read the PulseSensor's value.
                                              // Assign this value to the "Signal" variable.
  Signal_1 = analogRead(PulseSensorPurplePin_1);  // Read the PulseSensor's value.
                                              // Assign this value to the "Signal" variable.

   Serial.println(String(Signal_0)+","+String(Signal_1));                    // Send the Signal value to Serial Plotter.


   if(Signal_0 > Threshold_0){                          // If the signal is above "550", then "turn-on" Arduino's on-Board LED.
     //digitalWrite(LED13,HIGH);
     x_0 = 255;
     analogWrite(LED_0, x_0);
   } else {
     //digitalWrite(LED13,LOW);                //  Else, the sigal must be below "550", so "turn-off" this LED.
     x_0 -= 5; 
     analogWrite(LED_0, x_0);
   }

    if(Signal_1 > Threshold_1){                          // If the signal is above "550", then "turn-on" Arduino's on-Board LED.
     //digitalWrite(LED13,HIGH);
     x_1 = 255;
     analogWrite(LED_1, x_1);
   } else {
     //digitalWrite(LED13,LOW);                //  Else, the sigal must be below "550", so "turn-off" this LED.
     x_1 -= 5; 
     analogWrite(LED_1, x_1);
   }

delay(50);


}
