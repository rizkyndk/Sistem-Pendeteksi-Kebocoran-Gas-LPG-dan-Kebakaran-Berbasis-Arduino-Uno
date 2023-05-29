const int Relay1 = 8;
const int Relay2 = 9;
int relayON = LOW;
int relayOFF = HIGH;
int FlameD = 7;
int Flame = HIGH;
int SensorMq2 = A0;
int Gas;

void setup() 
{
  Serial.begin(115200); 
  pinMode(Relay1, OUTPUT); 
  pinMode(Relay2, OUTPUT);
  pinMode(SensorMq2, INPUT);
  pinMode(FlameD, INPUT);
}

void loop() {
Gas = analogRead(SensorMq2);
Flame = digitalRead(FlameD);

if (Flame== LOW)
{
digitalWrite(Relay1, relayON);
digitalWrite(Relay2, relayON);
Serial.println("FLAME, FLAME, FLAME");
delay(5000);
}
else
{
digitalWrite(Relay1, relayOFF);
digitalWrite(Relay2, relayOFF);
}

{
if (Gas>10 ){
digitalWrite(Relay1, relayON);
Serial.println(Gas);
Serial.print("");
Serial.println("WARNING..!!");
}
else if (Gas<100 ) {
digitalWrite(Relay1, relayOFF);
delay(2000);
}
}
}
