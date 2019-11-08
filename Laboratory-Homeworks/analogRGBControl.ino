const int inputPinR = A0;
const int inputPinG = A1;
const int inputPinB = A2;

const int outputPinR = 3;
const int outputPinG = 5;
const int outputPinB = 6;

int rInValue = 0;
int gInValue = 0;
int bInValue = 0;

int rOutValue = 0;
int gOutValue = 0;
int bOutValue = 0;


void setup() {
  
  pinMode(inputPinR,INPUT);
  pinMode(inputPinG,INPUT);
  pinMode(inputPinB,INPUT);

  pinMode(outputPinR,OUTPUT);
  pinMode(outputPinG,OUTPUT);
  pinMode(outputPinB,OUTPUT);
  
}

void setColor(int red, int green, int blue)
{
  rOutValue=map(rInValue,0,1023,0,255);
  gOutValue=map(gInValue,0,1023,0,255);
  bOutValue=map(bInValue,0,1023,0,255);

  analogWrite(outputPinR,rOutValue);
  analogWrite(outputPinG,gOutValue);
  analogWrite(outputPinB,bOutValue);
  
}

void loop() {
  
  rInValue=analogRead(inputPinR);
  gInValue=analogRead(inputPinG);
  bInValue=analogRead(inputPinB);
  setColor(rInValue,gInValue,bInValue);
  
}
