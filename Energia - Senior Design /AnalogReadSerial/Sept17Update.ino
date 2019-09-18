
/* In the setup function we initialize serial communication and set
 * the external LED on PWM pin 19 as OUTPUT. You can use a different
 * LED if you prefer. Connect the photoresistor to pin 2.
 */
void setup()
{
  Serial.begin(115200); // initialize serial communication
  pinMode(19, OUTPUT); // sets the LED on pin 19 to output
 // sets the LED on pin 19 to output

  
}

/* In the loop section we will read the photoresistor analog value
 * then we will use the map() and constrain() functions to adjust the
 * range for PWM. When the photoresistor is dark the LED will turn on,
 * you can cover the photoresistor with your hand to block out light.
 */
#define threshold 50
 
void loop()
{
  
  //int lightLevel = (analogRead(2)); // Read the light level from analog pin 2
  float north = analogRead(12);
  float west = analogRead(13);
  float east = analogRead(29);
  float south = analogRead(30);
  float sum;
 delay(1000); // delay for 1 millisecond for smoothness
  // adjust the value 0 to max resolution to span 0 to 255
  north = map(north, 0, 850, 0, 255);
  north = constrain(north, 0, 255); // constrain values between 0-255;
  west = map(west, 0, 850, 0, 255);
  west = constrain(west, 0, 255); // constrain values between 0-255;
  east = map(east, 0, 850, 0, 255);
  east = constrain(east, 0, 255);
  south = map(south, 0, 850, 0, 255);
  south = constrain(south, 0, 255);
  
  sum = south + north + west + east;
  if(north/sum > .3)
  {
    if(north - west > 15)
    {
      Serial.println("POINTING NORTH");
    }
    else if(west - north > 15)
    {
      Serial.println("POINTING WEST");
    }
    else if(north - west < 15 || west - north < 15)
    {
      Serial.println("POINTING NORTHWEST");
    }
    
  }
    Serial.println();
    Serial.print("north = ");
    Serial.println(north); // Print the analog value to Serial
    Serial.print("west = ");
    Serial.println(west);
    Serial.print("east = ");
    Serial.println(east); // Print the analog value to Serial
    Serial.print("south = ");
    Serial.println(south);
}
