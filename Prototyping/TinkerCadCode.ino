// C++ code
//



//Defintions have to be global 

//sensors
#define SoilSensor A0
#define Rainwater A1
	//are we pulling from reserves or not?

//pumps, solonoid pins
#define Pump 13
#define Solenoid1 12 
#define Solenoid2 11  
#define PullStatus 10 

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


 




void loop()
{
  int SwitchStatus = 0;
  
  int Moisture = analogRead(SoilSensor); // read the analog value from sensor
  int Rainwater_Status = analogRead(Rainwater); // read the analog value from sensor
  SwitchStatus = digitalRead(Switch);
  
  Serial.print("Moisture: ");
  Serial.println(Moisture);
  Serial.print("Water level in tank:");
  Serial.println(Rainwater_Status);
  Serial.print("Switch Status (1 is bad, 0 is good):");
  Serial.println(SwitchStatus);
  
  if(SwitchStatus == 0){
    
    if(Rainwater_Status > 200){
      //ensures that only one valve is open at a time 
      digitalWrite(PullStatus, LOW);
      wateroff(Solenoid2);
      
      
      if(Moisture > 400){
        waterflow(Solenoid1);


      }else{
        wateroff(Solenoid1);
      }
    }else{
      //ensures that only one valve is open a time 
      wateroff(Solenoid1);
      digitalWrite(PullStatus, HIGH);
      
      if(Moisture > 400){
        waterflow(Solenoid2);



      }else{
        wateroff(Solenoid2);


      }
    }
  }else{
  Serial.println("Off Switch enganged. No water will be pumped until fault is rectified");
  delay(2000);
  }
    
    
    
    
    
    
}//end of void loop
    

  
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
  digitalWrite(Pump, LOW);
  delay(500);
}

        
        
        
        
        
        
        
        
        
        
    
