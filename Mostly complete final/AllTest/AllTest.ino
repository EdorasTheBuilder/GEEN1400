// C++ code
//



//Defintions have to be global 

//sensors
#define SoilSensor A0
#define Rainwater A1
	//are we pulling from reserves or not?

//pumps, solonoid pins
#define Pump 12
#define Solenoid1 11 
#define Solenoid2 10  
#define PullStatus 9

//manual shutoff pins
#define Switch 2


//PIN ASSIGNMENTS SUBJECT TO CHANGE IN PCB. 
void setup()
{
  Serial.begin(9600);
  
  
  pinMode(Pump, OUTPUT);
  pinMode(Solenoid1, OUTPUT);
  pinMode(Solenoid2, OUTPUT);
  pinMode(PullStatus, OUTPUT);
  
  //Setting up soil sensors as inputs 
  
  
  pinMode(SoilSensor,INPUT);
  pinMode(Rainwater,INPUT); 
  
  
  //manual shutoff pins 
  pinMode(Switch, INPUT);
  
}


 




void loop() {
  int SwitchStatus = 0;
  
  int Moisture = analogRead(SoilSensor); // read the analog value from sensor
  int Rainwater_Status = analogRead(Rainwater); // read the analog value from sensor
  SwitchStatus = digitalRead(Switch);
  Serial.println("\n");
  Serial.print("Moisture: ");
  Serial.println(Moisture);
  Serial.print("Water level in tank:");
  Serial.println(Rainwater_Status);
  Serial.print("Switch Status (1 is bad, 0 is good):");
  Serial.println(SwitchStatus);
  
  
  
  waterflow(Solenoid1); 
  waterflow(Solenoid2);

}


void waterflow(int valve){
  //valve= either solenoid 1 or 2 
  digitalWrite(valve, HIGH);
    delay(2000);
    digitalWrite(Pump, HIGH);
    delay(500);

}

void wateroff(int valve){
  digitalWrite(valve, LOW);
  delay(2000);
}
