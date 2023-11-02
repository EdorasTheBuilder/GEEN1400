// C++ code

// Definitions have to be global

// Sensors
#define SoilSensor A0
#define Rainwater A1

// Pumps and solenoid pins
#define Pump 12
#define Solenoid1 11
#define Solenoid2 10
#define PullStatus 9

// Manual shutoff pins
#define Switch 2

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

// Function to turn on the pump and the appropriate solenoid valve
void turnOnPumpAndValve(int valvePin1, int valvePin2) {
  digitalWrite(Pump, HIGH);
  digitalWrite(valvePin1, HIGH);
  digitalWrite(valvePin2, LOW);
}

// Function to turn off the pump and all solenoid valves
void turnOffPumpAndValves() {
  digitalWrite(Pump, LOW);
  digitalWrite(Solenoid1, LOW);
  digitalWrite(Solenoid2, LOW);
}

void loop() {
  int Moisture = analogRead(SoilSensor); // Read the analog value from the soil moisture sensor
  int Rainwater_Status = analogRead(Rainwater); // Read the analog value from the rainwater sensor
  SwitchStatus = digitalRead(Switch);

  Serial.println("\n");
  Serial.print("Moisture: ");
  Serial.println(Moisture);
  Serial.print("Water level in tank: ");
  Serial.println(Rainwater_Status);
  Serial.print("Switch Status (1 is bad, 0 is good): ");
  Serial.println(SwitchStatus);

  if (SwitchStatus == 0) {
    if (Moisture > 400) {
      if (Rainwater_Status < 300) {
        turnOnPumpAndValve(Solenoid1, Solenoid2);
      } else {
        turnOnPumpAndValve(Solenoid2, Solenoid1);
      }
    } else {
      turnOffPumpAndValves();
    }
  } else {
    Serial.println("Off Switch engaged. No water will be pumped until the fault is rectified");
    turnOffPumpAndValves();
  }

  delay(2000); // Delay after each loop iteration to avoid reading the sensors too frequently
}
