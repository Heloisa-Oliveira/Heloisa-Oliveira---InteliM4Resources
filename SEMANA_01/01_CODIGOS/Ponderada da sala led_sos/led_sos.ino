// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(115200);
  pinMode(15, OUTPUT);
}

// obs: one unit is 0.3 seconds

// the loop routine runs over and over again forever:
void loop() 
{
  // letter S 
  digitalWrite(15, HIGH);
  delay(300);
  digitalWrite(15, LOW);
  delay(300);
  digitalWrite(15, HIGH);
  delay(300);
  digitalWrite(15, LOW);
  delay(300);
  digitalWrite(15, HIGH);
  delay(300);
  
  // space between letters
  digitalWrite(15, LOW);
  delay(900);

  // letter O
  digitalWrite(15, HIGH);
  delay(900);
  digitalWrite(15, LOW);
  delay(300);
  digitalWrite(15, HIGH);
  delay(900);
  digitalWrite(15, LOW);
  delay(300);
  digitalWrite(15, HIGH);
  delay(900);
  
  // space between letters
  digitalWrite(15, LOW);
  delay(900);

  // letter S 
  digitalWrite(15, HIGH);
  delay(300);
  digitalWrite(15, LOW);
  delay(300);
  digitalWrite(15, HIGH);
  delay(300);
  digitalWrite(15, LOW);
  delay(300);
  digitalWrite(15, HIGH);
  delay(300);
  
  // space between words
  digitalWrite(15, LOW);
  delay(2100);
}