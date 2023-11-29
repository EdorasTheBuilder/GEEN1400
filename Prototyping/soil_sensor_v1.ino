/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-soil-moisture-sensor
 */

#define AOUT_PIN A0 // Arduino pin that connects to AOUT pin of moisture sensor
#define PUMP 2

void setup() {
  Serial.begin(9600);
  pinMode(PUMP,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  //checks to see if everything is configured correctly
  digitalWrite(PUMP, HIGH);
  delay(500);
  digitalWrite(PUMP, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.print("Setup complete \n");


}
z
void loop() {
  int value = analogRead(AOUT_PIN); // read the analog value from sensor

  Serial.print("Moisture: ");
  Serial.println(value);
  delay(500);

  if(value > 400){
    digitalWrite(PUMP, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(5000);
  

  }
  else{
    digitalWrite(PUMP, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(5000);
    
  }

}
