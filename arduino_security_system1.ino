#define trigPin 7
#define echoPin 6
#define ledRed 9
#define  ledYellow 10
#define ledGreen 11
#define soundbuzzer 3

int sound  = 500;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin,  OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow,  OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(soundbuzzer, OUTPUT);
}

void  loop() {
  long durationindigit, distanceincm;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceincm = (durationindigit/5) / 29.1;
 
  if (distanceincm < 50) {
      digitalWrite(ledGreen, HIGH);
  }
  else {
      digitalWrite(ledGreen,  LOW);
  }
  
  if (distanceincm < 20) {
    digitalWrite(ledYellow, HIGH);
  }
  else {
    digitalWrite(ledYellow, LOW);
  }
  
  if (distanceincm  < 5) {
    digitalWrite(ledRed, HIGH);
    sound = 1000;
  }
  else  {
    digitalWrite(ledRed, LOW);
  }
 
  if (distanceincm > 5 || distanceincm <= 0){
    Serial.println("Outside the permissible range of distances");
    noTone(soundbuzzer);
  }
  else {
    Serial.print(distanceincm);
    Serial.println("  cm");
    tone(soundbuzzer, sound);
  }
  
  delay(300);
}