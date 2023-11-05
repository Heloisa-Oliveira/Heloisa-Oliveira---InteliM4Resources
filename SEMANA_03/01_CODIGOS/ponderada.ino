/**
   Simon Game using ESP32
*/

/* Constants - define pin numbers for LEDs and buttons: */
const uint8_t ledPins[] = {33, 25, 26, 27};
const uint8_t buttonPins[] = {19, 18, 5, 17};
int but_reset = 16;

#define MAX_GAME_LENGTH 100

/* Global variables - store the game state */
uint8_t gameSequence[MAX_GAME_LENGTH] = {0};
uint8_t gameIndex = 0;

/**
   Set up the ESP32 and initialize Serial communication
*/
void setup() {
  Serial.begin(11500);
  for (byte i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(but_reset, INPUT_PULLUP);

  // The following line primes the random number generator.
  // It assumes pin 32 is floating (disconnected):
  randomSeed(analogRead(32));
}

/**
   Lights the given LED
*/
void lightLed(byte ledIndex) {
  digitalWrite(ledPins[ledIndex], HIGH);
  delay(300);
  digitalWrite(ledPins[ledIndex], LOW);
}


/**
   Plays the current sequence that the user has to repeat
*/
void playSequence() {
  for (int i = 0; i < gameIndex; i++) {
    byte currentLed = gameSequence[i];
    lightLed(currentLed);
    delay(50);
  }
}

/**
    Waits until the user pressed one of the buttons,
    and returns the index of that button
*/
byte readButtons() {
  while (true) {
    for (byte i = 0; i < 4; i++) {
      checkReset();
      byte buttonPin = buttonPins[i];
      if (digitalRead(buttonPin) == LOW) {
        return i;
      }
    }
    delay(1);
  }
}

/**
  Play the game over sequence, and report the game score
*/
void gameOver() {
  Serial.print("Game over! your score: ");
  Serial.println(gameIndex - 1);
  gameIndex = 0;
  delay(200);

}

/**
   Get the user's input and compare it with the expected sequence.
*/
bool checkUserSequence() {
  for (int i = 0; i < gameIndex; i++) {
    byte expectedButton = gameSequence[i];
    byte actualButton = readButtons();
    lightLed(actualButton);
    if (expectedButton != actualButton) {
      return false;
    }
  }

  return true;
}

/* Check if the reset button is pressed */
void checkReset(){
  if(digitalRead(but_reset) == 0){
    gameOver();
  }
}

/**
   The main game loop
*/
void loop() {

  // Add a random color to the end of the sequence
  gameSequence[gameIndex] = random(0, 4);
  gameIndex++;

  checkReset();

  if (gameIndex >= MAX_GAME_LENGTH) {
    gameIndex = MAX_GAME_LENGTH - 1;
  }

  checkReset();

  playSequence();
  if (!checkUserSequence()) {
    gameOver();
  }

  checkReset();

  delay(300);

  checkReset();
}
