// Sensors
#define SoilSensor A0
#define Rainwater A1

// Pumps and solenoid pins
#define Pump 8
#define Solenoid1 9
#define Solenoid2 10
#define PullStatus 2

// Manual shutoff pins
#define Switch 1

int SwitchStatus = 0;



void setup() {
  Serial.begin(9600);

  pinMode(Pump, OUTPUT);
  pinMode(Solenoid1, OUTPUT);
  pinMode(Solenoid2, OUTPUT);
  pinMode(PullStatus, OUTPUT);

  // Setting up soil sensors as inputs
  pinMode(SoilSensor, INPUT);
  pinMode(Rainwater, INPUT);

  // Manual shutoff pins
  pinMode(Switch, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //soil sensor read
  int Moisture = analogRead(SoilSensor);
  Serial.println("\n");
  Serial.print("Moisture: ");
  Serial.println(Moisture);

  //water level in tank
  int Rainwater_Status = analogRead(Rainwater); // Read the analog value from the rainwater sensor
  Serial.print("Water level in tank: ");
  Serial.println(Rainwater_Status);
  Serial.print("Switch Status (1 is bad, 0 is good): ");
  Serial.println(SwitchStatus);


  //switch
  Serial.print("Switch Status (1 is bad, 0 is good): ");
  Serial.println(SwitchStatus);
}