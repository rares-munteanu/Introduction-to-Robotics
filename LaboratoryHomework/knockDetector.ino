const int pBuzzerPin = A1;
const int aBuzzerPin = 11;
const int minKnockValue = 2;
const int buttonPin = 2;
const int pressed = 0;
const unsigned melodyInterval = 5000; // 5 seconds after knock we start the melody

int knockValue = 0; // Readed from pBuzzerPin
unsigned long currentTime = 0;
unsigned long lastTime = 0;
int buttonState = 1;
int startedCounting = 0;
int singMelodyValue = 0;
bool firstTime = true;

#define NOTE_C4 261
#define NOTE_G3 196
#define NOTE_A3 220
#define NOTE_B3 247

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
   4, 8, 8, 4, 4, 4, 4, 4
};

void singMelody()
{
  int current = millis(), last = millis();
  
  //Longer Pause between each time melody starts again
  int noteDuration = 250;
  int pauseBetweenNotes = 1000;
  if(firstTime == true) {
      pauseBetweenNotes = 0; //No pause if is the first time singing the melody
      firstTime = false;
    }
  
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    buttonState = digitalRead(buttonPin);
    if (buttonState == pressed) {
      noTone(aBuzzerPin);
      singMelodyValue = 0;
      firstTime = true; // Next time the melody with start with no pause
      return;
  }
    
    current = millis();
    if(current - last < pauseBetweenNotes) 
      thisNote--; 
    else { 
      tone(aBuzzerPin, melody[thisNote], noteDuration);
      last = millis();
   }   
   if(thisNote >= 0) { 
      noteDuration = 1000 / noteDurations[thisNote];
      pauseBetweenNotes = noteDuration * 1.30;
   }
   
  }
  
}
void setup() {
  
  pinMode(aBuzzerPin,OUTPUT);
  pinMode(pBuzzerPin,INPUT);
  pinMode(buttonPin,INPUT_PULLUP);
  Serial.begin(9600);
  
}

void loop() {

  currentTime = millis();
  if (startedCounting == 0)
     lastTime = currentTime;
     
  knockValue = analogRead(pBuzzerPin);
  if (knockValue > minKnockValue)
     startedCounting = 1;

  if (startedCounting == 1) {
    
    if (currentTime-lastTime > melodyInterval) { 
  
          startedCounting = 0;
          singMelodyValue = 1;
        } 
  }

  if (singMelodyValue == 1)
      singMelody();
      
}
