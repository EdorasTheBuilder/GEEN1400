// C++ code
//



//Defintions have to be global 

//sensors
#define SoilSensor A0
#define Rainwater d3

// Pumps and solenoid pins
#define Pump d8
#define Solenoid1 d9
#define Solenoid2 d10
#define PullStatus d2

// Manual shutoff pins
#define Switch d1


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


 




void loop()
{
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
  delay(2000);


  if(SwitchStatus == 0){
    
    if(Moisture > 400){
      //ensures that only one valve is open at a time 
      digitalWrite(Pump, HIGH);



      if(Rainwater_Status < 300){
        digitalWrite(Solenoid2, LOW);
        digitalWrite(Solenoid1, HIGH);

      }else{
        digitalWrite(Solenoid1, LOW);
        digitalWrite(Solenoid2, HIGH);
      }
    }else{
      //ensures that only one valve is open a time 
      digitalWrite(Pump, LOW);
      digitalWrite(Solenoid1, LOW);
      digitalWrite(Solenoid2, LOW);
      
  

    }
  }else{
  Serial.println("Off Switch enganged. No water will be pumped until fault is rectified");
  delay(2000);
  }
    
    
    
    
    
    
}//end of void loop
    

  

        
        
        
        
        
        
        
        
        
        
    
