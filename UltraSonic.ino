 #define TRIG 2
 #define ECHO 3
 #define LED 4

 //#define enA 9
// #define M1 
// #define M2
 
 #define enB 10
 #define M3 9
 #define M4 8
 
 double duration, distanceCm;

 void setup() 
 {
  Serial.begin(9600);
  
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  
  pinMode(enB, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);  

  analogWrite(enB, 255);
}

void loop() {
   
  digitalWrite(TRIG, LOW); // Set TRIG low for 5 microseconds
  delayMicroseconds(5);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  
  duration = pulseIn(ECHO, HIGH);

  distanceCm = (duration/2) * 0.0343;

  if(distanceCm <= 50)
  {
    digitalWrite(LED, HIGH);
    digitalWrite(M3, LOW);
    digitalWrite(M4, LOW);
  }
  else
  {
    digitalWrite(LED, LOW); // Set LED low
    digitalWrite(M3, HIGH);
    digitalWrite(M4, LOW);
  }
   delay(50); 
   Serial.println(distanceCm);
}
