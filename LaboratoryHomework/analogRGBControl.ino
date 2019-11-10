const int potPinR = A0;
const int potPinG = A1;
const int potPinB = A2;

const int ledPinR = 3;
const int ledPinG = 5;
const int ledPinB = 6;

int rInValue = 0;
int gInValue = 0;
int bInValue = 0;

int rOutValue = 0;
int gOutValue = 0;
int bOutValue = 0;


void setup() {
  
  pinMode(potPinR,INPUT);
  pinMode(potPinG,INPUT);
  pinMode(potPinB,INPUT);

  pinMode(ledPinR,OUTPUT);
  pinMode(ledPinG,OUTPUT);
  pinMode(ledPinB,OUTPUT);
  
}

void setColor(int red, int green, int blue){
  
  rOutValue=map(rInValue,0,1023,0,255);
  gOutValue=map(gInValue,0,1023,0,255);
  bOutValue=map(bInValue,0,1023,0,255);

  analogWrite(ledPinR,rOutValue);
  analogWrite(ledPinG,gOutValue);
  analogWrite(ledPinB,bOutValue);
  
}

void loop() {
  
  rInValue=analogRead(potPinR);
  gInValue=analogRead(potPinG);
  bInValue=analogRead(potPinB);
  setColor(rInValue,gInValue,bInValue);
  
}
