#ifndef MENU_H
#define MENU_H

#include "PROGMEM_READ.h"
#include "components.h"

//Fonts for lcd text printing
extern uint8_t Ubuntu[];
extern uint8_t UbuntuBold[];
extern uint8_t Arial_round_16x24[];
extern uint8_t BigFont[];
extern uint8_t Dingbats1_XL[];
extern uint8_t Various_Symbols_16x32[];
extern uint8_t SmallFont[];
extern uint8_t SevenSegNumFont[];
extern uint8_t battery_24x48[];


bool normalButtons = true; //Used for knowing if normal buttons template is selected

//Some functions declarations
void clearScreen();
void clearArea(int, int, int, int);
void manageFonts(int);
void manageBreathalyser();
void printMQ3Value();
void manageMQ3ScreenTime();
void manageHands();
void resetVariables();

const char batteryLevels[6][2] = {
  {"0"}, {"1"}, {"2"}, {"3"}, {"4"},  {"5"}
};

byte batteryLevel = 5;

const unsigned short signatureHeight = 25;
const unsigned short dividerHeight = 10;

//Menu variables
bool _welcomeScreen = true;
bool blinks[] = {false, false};//Battery

unsigned long long lastTime[8]; // used with milliss
//WelcomeScreen, Battery Decrease, Battery Blinking, Alcohol Sensor,
//Screen nr 8/9 Timer,  Alcohol Printing Time,Gear shifting time
unsigned long long times[8] = {1500, 300000, 500, 5000, 3000 , 150, 4000}; // used to count times
//welcomeScreen, Battery Decrease, Battery Blinking, Alcohol Sensor,
//Screen nr 8/9 Timer, Alcohol Printing Time, Gear shifting time

char buffer[40]; //Buffer for reading from PROGMEM

const unsigned short buttonTextOffset = 5;

const char signature[40] PROGMEM {" Rares Munteanu  Smart Cover"};
const byte menusLength[] {1, 3, 3, 4, 5, 2, 2, 1, 2, 2};
int buttonIndex = -1;
int pressedButton;


const char menusInfo[][10][40] PROGMEM {
  {
    {"MENU"},
  },
  {
    {"Please blow for 5 seconds"},
    {"near the alcohol sensor"},
    {"Value:"}
  },
  {
    {"Voice volume:"},
    {"Voice gender:"},
    {"Transmission:"}
  },
  {
    {"Background"},
    {"color:"},
    {"Buttons"},
    {"template:"}
  },
  {
    {"This is a 'Smart steering "},
    {"wheel cover' project made by"},
    {"Rares Munteanu and designed"},
    {"especially for beginner"},
    {"drivers."}
  },
  {
    {"Please place your hands"},
    {"on the steering wheel"}
  },
  {
    {"Both hands are on"},
    {"the steering wheel"}
  },
  {
    {"Shifting gear"}
  },
  {
    {"Sorry you are drunk"},
    {"engine turned off"}
  },
  {
    {"You are good to go"},
    {"engine turned on"}
  }
};

//Menus texts position on the lcd
const short menusPos[][10][2] PROGMEM {
  { //Main menu
    {CENTER, 20},
  },
  { //Start Engine
    {CENTER, 120},
    {CENTER, 150},
    {CENTER, 180}
  },
  { //Driver Settings
    {20, 70},
    {20, 130},
    {20, 190}
  },
  { //Display Settings
    {35, 75},
    {35, 105},
    {35, 160},
    {35, 190}
  },
  { // Info
    {25, 80},
    {25, 110},
    {25, 140},
    {25, 170},
    {25, 200}
  },
  {
    {CENTER, 140},
    {CENTER, 170}
  },
  {
    {CENTER, 140},
    {CENTER, 170}
  },
  {
    {CENTER, CENTER},
  },
  {
    {CENTER, 120},
    {CENTER, 160}
  },
  {
    {CENTER, 120},
    {CENTER, 160}
  }
};

// 0 -SmallFont; 1-BigFont; 2-Ubuntu; 3-UbuntuBold; 4-Arial_round_16x24
const byte menusFont[][10] {
  {3},
  {4, 4, 4},
  {4, 4, 4},
  {4, 4, 4, 4},
  {1, 1, 1, 1, 1},
  {4, 4},
  {4, 4},
  {2},
  {4, 4},
  {4, 4}
};

bool hasButtons[] = {true, true, true, true, true, true, true, false, false, false};
// Used to know if a menu has buttons 

bool isMenu[] = {false, false, false, false, false, false, false, false, false, false};
//Used not to redraw the same menu everytime if nothing has changed

int buttons[20];
//enum allButtons {startEngine, driverSettings, displaySettings, info, backButton};
int currentMenu = 0;//Main Menu in the beginning
int howManyMenus = 10;

//To know how many buttons a menu has, used in combinations with hasButtons
const short howManyButtons[] {
  4, 1, 7, 5, 1, 1, 1, 0, 0, 1
};

//The id for every button from the menus
const int menuButtons[][10] PROGMEM {
  { 0, 1, 2, 3 },
  {4},
  {5, 6, 7, 8, 9, 10, 11},
  {12, 13, 14, 15, 16},
  {17},
  {18},
  {19}
};


//Buttons position on the lcd
//4 -> x,y,width,height
const int buttonsPos[][10][4] PROGMEM{
  {
    {15, 100, 200, 35},
    {230, 100, 245, 35},
    {15, 200, 270, 35},
    {300, 200, 80, 35}
  },
  {
    {360, 240, 100, 25},
  },
  {
    {250, 65, 40, 30},
    {320, 65, 40, 30},
    {250, 125, 80, 30},
    {350, 125, 100, 30},
    {250, 185, 110, 30},
    {380, 185, 80, 30},
    {360, 250, 100, 25},
  },
  {
    {250, 90, 100, 25},
    {365, 90, 100, 25},
    {250, 175, 100, 25},
    {365, 175, 100, 25},
    {360, 240, 100, 25}
  },
  {
    {360, 240, 100, 25}
  },
  {
    {360, 240, 100, 25}
  },
  {
    {360, 240, 100, 25}
  }
};

const char buttonsText[][10][40] {
  {
    {"Start Engine"},
    {"Driver Settings"},
    {"Display Settings"},
    {"Info"}
  },
  {
    {"Back"},
  },
  {
    {"25"},
    {"28"},
    {"Male"},
    {"Female"},
    {"Manual"},
    {"Auto"},
    {"Back"}
  },
  {
    {"Black"},
    {"Green"},
    {"Normal"},
    {"Invert"},
    {"Back"}
  },
  {
    {"Back"}
  },
  {
    {"Back"}
  },
  {
    {"Back"}
  }
};

//Function to create buttons and initialize the inside text
void initializeButtons() {
  int x, y, width, height;
  myButtons.setButtonColors(Black, DarkGrey, White, Blue, 0xCE2C); //Normal buttons template

  for (int _currentMenu = 0; _currentMenu < howManyMenus; _currentMenu++) {
    if (hasButtons[_currentMenu]) {
      for (int _currentButton = 0; _currentButton < howManyButtons[_currentMenu]; _currentButton++) {
        x = PROGMEM_get(&buttonsPos[_currentMenu][_currentButton][0]);
        y = PROGMEM_get(&buttonsPos[_currentMenu][_currentButton][1]);
        width = PROGMEM_get(&buttonsPos[_currentMenu][_currentButton][2]);
        height = PROGMEM_get(&buttonsPos[_currentMenu][_currentButton][3]);
        buttons[++buttonIndex] = myButtons.addButton(x, y, width, height, buttonsText[_currentMenu][_currentButton], BUTTON_DISABLED);
      }
    }
  }
}

//Function that clears the screen and prepare the lcd for changing the menu to another one
void changeMenu(int whatMenu) {
  if (whatMenu < 0) {
    clearScreen();
  }
  else {
    if (hasButtons[currentMenu]) {
      int x, y, width, height;
      for (int _currentButton = 0; _currentButton < howManyButtons[currentMenu]; _currentButton++) {
        x = PROGMEM_get(&buttonsPos[currentMenu][_currentButton][0]);
        y = PROGMEM_get(&buttonsPos[currentMenu][_currentButton][1]);
        width = PROGMEM_get(&buttonsPos[currentMenu][_currentButton][2]);
        height = PROGMEM_get(&buttonsPos[currentMenu][_currentButton][3]);
        myButtons.disableButton(buttons[PROGMEM_get(&menuButtons[currentMenu][_currentButton])]);
        clearArea(x, y, width, height);
      }
    }
  }
  isMenu[currentMenu] = false;
  currentMenu = whatMenu;
}

//Function used to gray out the buttons from
// driver settings and display settings that 
// has already been selected
void manageSelectedButtons(int whatButton) {
  switch (whatButton) {
    case 5: {
        if (voiceVolume == 25)
          myButtons.disableButton(5);
        break;
      }
    case 6: {
        if (voiceVolume == 28)
          myButtons.disableButton(6);
        break;
      }
    case 7: {
        if (voiceGender == 2) //Male
          myButtons.disableButton(7);
        break;
      }
    case 8: {
        if (voiceGender == 1) //Female
          myButtons.disableButton(8);
        break;
      }
    case 9: {
        if (transmission == 0) //Manual
          myButtons.disableButton(9);
        break;
      }
    case 10: {
        if (transmission == 1) //Auto
          myButtons.disableButton(10);
        break;
      }
    case 12: {
        if (backColor == Black)
          myButtons.disableButton(12);
        break;
      }
    case 13: {
        if (backColor == 0x00E0)
          myButtons.disableButton(13);
        break;
      }
    case 14: {
        if (normalButtons == true)
          myButtons.disableButton(14);
        break;
      }
    case 15: {
        if (normalButtons == false)
          myButtons.disableButton(15);
        break;
      }
  }
}

//Function to draw the buttons and the text on lcd
// AND handle the warning messages when the driver try
// to start the engine
void drawMenus() {
  if (!isMenu[currentMenu]) {
    clearScreen();

    //Drawing text
    for (int i = 0; i < menusLength[currentMenu]; i++) {
      PROGMEM_read(&menusInfo[currentMenu][i], buffer);
      lcd.setColor(Red);
      lcd.setBackColor(VGA_TRANSPARENT);
      manageFonts(i);
      lcd.print(buffer, PROGMEM_get(&menusPos[currentMenu][i][0]), PROGMEM_get(&menusPos[currentMenu][i][1]));
    }

    //Drawing Buttons if necessary
    if (hasButtons[currentMenu]) {
      for (int i = 0; i < howManyButtons[currentMenu]; i++) {
        myButtons.enableButton(buttons[PROGMEM_get(&menuButtons[currentMenu][i])]);
        manageSelectedButtons(buttons[PROGMEM_get(&menuButtons[currentMenu][i])]);
        myButtons.drawButton(buttons[PROGMEM_get(&menuButtons[currentMenu][i])]);
      }
    }
    isMenu[currentMenu] = true;
  }

  if (currentMenu == 1) {
    manageBreathalyser();
    printMQ3Value();
  }
  if (currentMenu == 8 || currentMenu == 9)
    manageMQ3ScreenTime();

  if (engineStarted)
    manageHands();
}

void clearArea(int x, int y, int width, int height) {
  lcd.setColor(backColor);
  lcd.fillRect(x, y, x + width, y + height);
}


//Function to manage what the lcd should show depending on what button
//has been pressed
void manageMenus(int _pressedButton) {
  switch (_pressedButton) {
    case -1: {
        break;
      }
    case 0 : {
        measuringMQ3 = true;
        lastTime[3] = millis();
        lastTime[5] = millis();
        changeMenu(1); //Starting Engine Menu
        break;
      }
    case 1 : {
        changeMenu(2); //Driver Settings Menu
        break;
      }
    case 2 : {
        changeMenu(3); //Display Settings Menu
        break;
      }
    case 3 : {
        changeMenu(4); //Info
        break;
      }
    case 4: {
        changeMenu(0);
        resetVariables();
        digitalWrite(ledPin, LOW);
        break;
      }
    case 5: {
        myButtons.disableButton(5, true);
        myButtons.enableButton(6, true);
        voiceVolume = 25;
        myMP3.volume(voiceVolume);
        break;
      }
    case 6: {
        myButtons.disableButton(6, true);
        myButtons.enableButton(5, true);
        voiceVolume = 28;
        myMP3.volume(voiceVolume);
        break;
      }
    case 7 : {
        myButtons.disableButton(7, true);
        myButtons.enableButton(8, true);
        voiceGender = 2;//Male;
        break;
      }
    case 8: {
        myButtons.disableButton(8, true);
        myButtons.enableButton(7, true);
        voiceGender = 1; //Female
        break;
      }
    case 9: {
        myButtons.disableButton(9, true);
        myButtons.enableButton(10, true);
        transmission = 0;//Manual;
        break;
      }
    case 10: {
        myButtons.disableButton(10, true);
        myButtons.enableButton(9, true);
        transmission = 1;//Automatic
        break;
      }
    case 11: {
        changeMenu(0);
        break;
      }
    case 12 : {
        myButtons.disableButton(12, true);
        myButtons.enableButton(13, true);
        backColor = Black;
        changeMenu(currentMenu);
        break;
      }
    case 13: {
        myButtons.disableButton(13, true);
        myButtons.enableButton(12, true);
        backColor = 0x00E0;
        changeMenu(currentMenu);
        break;
      }
    case 14: {
        myButtons.disableButton(14, true);
        myButtons.enableButton(15, true);
        myButtons.setButtonColors(Black, DarkGrey, White, Blue, 0xCE2C);
        normalButtons = true;
        changeMenu(currentMenu);
        break;
      }
    case 15: {
        myButtons.disableButton(15, true);
        myButtons.enableButton(14, true);
        myButtons.setButtonColors(0xCE2C, 0xB73F, Blue, Red, Black);
        normalButtons = false;
        changeMenu(currentMenu);
        break;
      }
    case 16 : {
        changeMenu(0);
        break;
      }
    case 17 : {
        changeMenu(0);
        break;
      }
    case 18: {
        resetVariables();
        changeMenu(0);
        myMP3.pause();
        myMP3.stopRepeat();
        digitalWrite(ledPin, LOW);
        break;
      }
    case 19: {
        resetVariables();
        changeMenu(0);
        myMP3.pause();
        myMP3.stopRepeat();
        digitalWrite(ledPin, LOW);
        break;
      }
  }
}

unsigned short getFontWidth(uint8_t font[]) {
  return font[0];
}
unsigned short getFontHeight(uint8_t font[]) {
  return font[1];
}

//Draw the lower screen signature
void drawSignature() {

  const short displayXSize = lcd.getDisplayXSize();
  const short displayYSize = lcd.getDisplayYSize();

  const int signatureWidth = displayXSize;
  const int dividerWidth = signatureWidth;

  const int offset = 10;

  lcd.setColor(206, 199, 100); //~Gray-Yellow
  lcd.fillRect(0, displayYSize - signatureHeight, signatureWidth, displayYSize);

  lcd.setColor(47, 175, 68); // Dark Green
  lcd.fillRect(0, displayYSize - signatureHeight - dividerHeight, dividerWidth, displayYSize - signatureHeight);

  PROGMEM_read(&signature, buffer);
  lcd.setFont(BigFont);
  lcd.setColor(Black);
  lcd.setBackColor(206, 199, 100); // ~Gray-Yellow
  lcd.print(buffer, offset , displayYSize - signatureHeight + offset - 5);
  lcd.print("~", offset , displayYSize - signatureHeight + offset);
  lcd.print("~", offset + strlen("~Rares Munteanu") * getFontWidth(BigFont) , displayYSize - signatureHeight + offset);

}

void drawBattery(uint16_t color = VGA_WHITE) {
  uint8_t localFont = lcd.getFont();
  word localColor = lcd.getColor();
  lcd.setFont(battery_24x48);
  lcd.setColor(color);
  lcd.setBackColor(backColor);
  lcd.print(batteryLevels[batteryLevel], 415, 18);
  lcd.setFont(localFont);
  lcd.setColor(localColor);
}

//Draw the upper screen model
void drawModel() {
  const short displayXSize = lcd.getDisplayXSize();
  const short displayYSize = lcd.getDisplayYSize();

  lcd.setColor(47, 175, 68);
  for (int i = dividerHeight + 10; i <= displayXSize - 10; i += 20)
    lcd.fillCircle(i, 0, 10);

}

void welcomeScreen() {
  lcd.setFont(UbuntuBold);
  lcd.setColor(Red);
  lcd.setBackColor(VGA_TRANSPARENT);
  lcd.print("Welcome!", CENTER, CENTER);
  drawBattery();
}

void clearBattery() {
  lcd.setColor(backColor);
  lcd.fillRect(415, 18, 415 + getFontWidth(battery_24x48), 18 + getFontHeight(battery_24x48));
}

void manageBattery() {
  //Battery simulation function ( not real life battery ) - it depends on time
  if (batteryLevel > 0) {
    if (millis() - lastTime[1] > times[1]) { //times[1] = battery decrease time
      if (batteryLevel >= 1)
        batteryLevel--;
      if (batteryLevel > 0)
        drawBattery();
      else
        drawBattery(Red);
      lastTime[1] = millis();
    }
  }
  else if (batteryLevel == 0) {
    if (millis() - lastTime[2] > times[2]) {
      if (blinks[0]) { //Battery is drawn
        clearBattery();
        blinks[0] = false;
      }
      else {
        drawBattery(Red);
        blinks[0] = true;
      }
      lastTime[2] = millis();
    }
  }
}

void clearScreen() {
  lcd.setColor(backColor);
  lcd.fillRect(0, dividerHeight + 1, lcd.getDisplayXSize(), lcd.getDisplayYSize() - dividerHeight - signatureHeight - 1);
  drawBattery();
}

//Function used to print text from the menu 
// with specific text fonts
void manageFonts(int which) {
  switch (menusFont[currentMenu][which]) {
    case 0: {
        lcd.setFont(SmallFont);
        break;
      }
    case 1: {
        lcd.setFont(BigFont);
        break;
      }
    case 2: {
        lcd.setFont(Ubuntu);
        break;
      }
    case 3: {
        lcd.setFont(UbuntuBold);
        break;
      }
    case 4: {
        lcd.setFont(Arial_round_16x24);
        break;
      }
    default: {
        lcd.setFont(BigFont);
        break;
      }
  }
}

#endif
