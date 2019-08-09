
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
#define threshold 15
 
void loop()
{
  
  //int lightLevel = (analogRead(2)); // Read the light level from analog pin 2
  float solar = analogRead(12);
  float solar2 = analogRead(13);
  delay(1000); // delay for 1 millisecond for smoothness
  // adjust the value 0 to max resolution to span 0 to 255
  solar = map(solar, 0, 850, 0, 255);
  solar = constrain(solar, 0, 255); // constrain values between 0-255;
  solar2 = map(solar2, 0, 850, 0, 255);
  solar2 = constrain(solar2, 0, 255); // constrain values between 0-255;
  if (solar2 - solar > threshold) 
  {
    analogWrite(19,255); // Write the PWM value to the LED   
  }
  else if(solar - solar2 > threshold)
  {
        analogWrite(19,0); // Write the PWM value to the LED   
  }
  else
  {
    analogWrite(19,50);
  }
    Serial.println();
    Serial.println(solar); // Print the analog value to Serial
    Serial.println(solar2);
}
