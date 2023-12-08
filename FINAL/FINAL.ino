// Sensors
#define SoilSensor A0
#define Rainwater A1

// Pumps and solenoid pins
#define Pump 8
#define Solenoid1 9
#define Solenoid2 10

// Manual shutoff pins
#define Switch 4


// distanse sensor
const int trigPin = 12;   
const int echoPin = 13; 


//led pins 
#define EmptyTank 3
#define FullTank 2


void setup() {
  Serial.begin(9600);

  pinMode(Pump, OUTPUT);
  pinMode(Solenoid1, OUTPUT);
  pinMode(Solenoid2, OUTPUT);

  // Setting up soil sensors as inputs
  pinMode(SoilSensor, INPUT);
  pinMode(Rainwater, INPUT);

  // Manual shutoff pins
  pinMode(Switch, INPUT);

  //input
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  

  //LED pins
  pinMode(EmptyTank, OUTPUT);
  pinMode(FullTank, OUTPUT); 





  /////// POST 

  delay(500);
  digitalWrite(EmptyTank, HIGH); 
  delay(500);
  digitalWrite(FullTank, HIGH); 
  delay(2000);



  delay(500);
  digitalWrite(EmptyTank, LOW); 
  delay(500);
  digitalWrite(FullTank, LOW); 
  delay(500);



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


  //switch
  int SwitchStatus = digitalRead(Switch);
  Serial.print("Switch Status (1 is bad, 0 is good): ");
  Serial.println(SwitchStatus);



  //sesnor
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);

  int duration = pulseIn(echoPin, HIGH);
  int distance = (duration*.0343)/2;

  Serial.print("Distance: ");  
	Serial.println(distance);  
	delay(100);  



// LOGIC 
if(SwitchStatus == 0){
    
    if(Moisture > 450){
      //ensures that only one valve is open at a time 
      digitalWrite(Pump, HIGH); 
    

      if(Rainwater_Status > 300){ //rainwater tank is empty 
        digitalWrite(Solenoid2, LOW);
        digitalWrite(Solenoid1, HIGH);  
        digitalWrite(EmptyTank, HIGH); 
        digitalWrite(FullTank, LOW); 


      }else{
        digitalWrite(Solenoid1, LOW);
        digitalWrite(Solenoid2, HIGH);
        digitalWrite(FullTank, HIGH); 
        digitalWrite(EmptyTank, LOW); 
      }

    }else{
      //ensures that only one valve is open a time 
      AllOff();
      
  

    }
  }else{
  Serial.println("Off Switch enganged. No water will be pumped until fault is rectified");
  delay(2000); 
  AllOff();

  }
    
    
    
    
    

}



void AllOff(){
  digitalWrite(Pump, LOW);
  digitalWrite(Solenoid1, LOW);
  digitalWrite(Solenoid2, LOW); 
  
}

