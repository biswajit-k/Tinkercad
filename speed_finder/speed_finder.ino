const int trigPin = 5;
const int echoPin = 6;


long duration;		// time duration between sending and received pulse
int FirstDistance;	
int SecondDistance;
double speed;
int distance;		
float Time = 1.0;		// time delay in seconds between first and second distance
float delayedtime = 1000*Time;	

void setup()
{
  Serial.begin(9600); 		// establish serial connection
pinMode(trigPin, OUTPUT); 	// triggerPin will be used as output to send pulse
pinMode(echoPin, INPUT); 	// echoPin will be used as input to receive reflected pulse

}


void loop()
{
GetSpeed();

}

float GetDistance()
{
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

//calculating distance
distance= duration*0.034/2;	

// Prints the distance on the Serial Monitor
Serial.print("Distance in cm : ");
    
Serial.println(distance);

return distance;
}
void GetSpeed(){
 	
   FirstDistance = GetDistance(); //get the first distance
   delay(delayedtime); //waits 1 seconds depending on the time declared above , you can change time depending resolution of your sensor 
   
   SecondDistance = GetDistance(); //gets the second distance
     
 
speed = (FirstDistance - SecondDistance)/Time; 
      // now calculating the difference 
   
//printing the speed on the serial monitor
  Serial.print("the speed (cm/s) is  :  ");
  Serial.println(speed);
 
}