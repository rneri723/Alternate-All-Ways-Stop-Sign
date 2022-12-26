long duration;
int distance;
void setup() {
#define trigpin 13
#define echopin 12
#define rpin 7
#define gpin 6
#define bpin 5
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(rpin, OUTPUT);
pinMode(gpin, OUTPUT);
pinMode(bpin, OUTPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(trigpin, LOW);
delayMicroseconds(2);

digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);

duration = pulseIn(echopin, HIGH);
distance = duration * 0.034 / 2;

Serial.print("Distance: ");
Serial.print(distance);
//digitalWrite(ledpin, HIGH);
if (distance > 6){
digitalWrite(gpin, LOW);
digitalWrite(rpin, HIGH);
}
if(distance <= 6){
digitalWrite(rpin, LOW);
digitalWrite(gpin, HIGH);
}
}
