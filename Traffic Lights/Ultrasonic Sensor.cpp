// C++ code
// Traffic lights
int red = 2;
int yellow = 3;
int green = 4;

const int trigPin = 10;
const int echoPin = 9;

float duration, distance;

void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  Serial.println("setup is complete");
  
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  
  
} 

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  
  Serial.println(distance);
  delay(100);
  
  //green light
  if ( distance > 150 ){
   digitalWrite(green, HIGH);
  } else{
    digitalWrite(green, LOW);
  }
  //yellow light
  if ( (distance > 50) && (distance < 150) ){
   digitalWrite(yellow, HIGH);
  } else{
    digitalWrite(yellow, LOW);
  }
  //red light
  if ( distance < 50 ){
   digitalWrite(red, HIGH);
  } else{
    digitalWrite(red, LOW);
  }
  
  
  }