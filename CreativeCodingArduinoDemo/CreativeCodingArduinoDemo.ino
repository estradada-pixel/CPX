//Diego, Eric, AJ, Leo, Raiziah, Robyn, jun, Leticia Altamiranda

#include <Adafruit_CircuitPlayground.h>

int value1; //declaring value for the sound sensor
int value2; //declaring value for the light sensor

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
 //Declaring value of the sound level = value 1
  value1 = CircuitPlayground.mic.soundPressureLevel(10);
  
  Serial.print("Sound Sensor SPL: "); //print string to serial console
  Serial.println(value1);

  delay(90);

  value2 = CircuitPlayground.lightSensor(); // senses the light detect levels
  
  Serial.print("Light Sensor: ");  // print string to serial console
  Serial.println(value2);
  
  delay(0.5); //time between next value output

  if (value1 >= 70){ //depending pn the volume detected the color changes
     CircuitPlayground.setPixelColor(1, 128, 128,   0);
  }
  else { //makes it so the pixel light isn't constantly on
    CircuitPlayground.clearPixels(); //turns off all pixel lights
}

  if (value2 <= 20){ //tells circuit to play tone whenever light reaches a value of 20 or below
    CircuitPlayground.playTone(500, 100);
  delay(0.5);
  } //doesn't need an else statement

}