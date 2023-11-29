// C++ code

// Definitions have to be global


// Pumps and solenoid pins

void setup() {
  Serial.begin(9600);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
 
}

void loop() {
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  
}