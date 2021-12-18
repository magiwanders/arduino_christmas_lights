// This program allow an Arduino to control a (cheap) strip of lights in order to simulate an (expensive) array of christmas lights.
// Note: the strip does not feature individual control of leds so it is electrically equivalent to a single light, here controlled with LED_BUILTIN (pin 13).
// Future Upgrades: analog dimming control with onw of the analog pins.

const int pin_0 = 3; // Fixed Slow
const int pin_1 = 4; // Fixed Fast
const int pin_2 = 5; // Random blinks
const int pin_3 = 6; // Spells "SUCA" in Morse Code
const int pin_4 = 7; // Spells "SOS" in Morse Code
const int pin_5 = 8;
const int pin_6 = 9;
const int pin_7 = 10;
const int pin_8 = 11;
const int pin_9 = 12;

int status = 0;
int T = 250; // Time unit is 250ms

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // This controls the lights
  pinMode(pin_0, INPUT);
  pinMode(pin_1, INPUT);
  pinMode(pin_2, INPUT);
  pinMode(pin_3, INPUT);
  pinMode(pin_4, INPUT);
  pinMode(pin_5, INPUT);
  pinMode(pin_6, INPUT);
  pinMode(pin_7, INPUT);
  pinMode(pin_8, INPUT);
  pinMode(pin_9, INPUT);
  Serial.begin(9600);
}

void loop() {

  if ( digitalRead(pin_0) == HIGH ) status = 0;
  if ( digitalRead(pin_1) == HIGH ) status = 1;
  if ( digitalRead(pin_2) == HIGH ) status = 2;
  if ( digitalRead(pin_3) == HIGH ) status = 3;
  if ( digitalRead(pin_4) == HIGH ) status = 4;
  if ( digitalRead(pin_5) == HIGH ) status = 5;
  if ( digitalRead(pin_6) == HIGH ) status = 6;
  if ( digitalRead(pin_7) == HIGH ) status = 7;
  if ( digitalRead(pin_8) == HIGH ) status = 8;
  if ( digitalRead(pin_9) == HIGH ) status = 9;

  Serial.print(status);
  Serial.println();

  switch (status) {
    case 0:
      func_0();
      break;
    case 1:
      func_1();
      break;
    case 2:
      func_2();
      break;
    case 3:
      func_3();
      break;
    case 4:
      func_4();
      break;
    case 5:
      func_5();
      break;
    case 6:
      func_6();
      break;
    case 7:
      func_7();
      break;
    case 8:
      func_8();
      break;
    case 9:
      func_9();
      break;
    default:
      break;
  }
}


//////////////////////////////////////////////
// Simple ON/OFF controls.
//////////////////////////////////////////////

// On/Off cycle of length 2*interval
void simpleBlink(int interval) {
  simpleON(interval);
  simpleOFF(interval);
}

// On for 'interval'
void simpleON(int interval) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(interval);
}

// Off for 'interval'
void simpleOFF(int interval) {
  digitalWrite(LED_BUILTIN, LOW);
  delay(interval);
}


//////////////////////////////////////////////
// Morse Code Components (with official Morse timing)
//////////////////////////////////////////////

void dot() {
  simpleON(T);
  Serial.print(".");
}

void line() {
  simpleON(3*T);
  Serial.print("_");
}

void wtn_letter_space() {
  simpleOFF(T);  
  Serial.print("'");
}

void btw_letter_space() {
  simpleOFF(3*T);
  Serial.print("'''");
}

void space() {
  simpleOFF(7*T);
  Serial.print("'''''''");
}

//////////////////////////////////////////////
// Morse Code Transmission
//////////////////////////////////////////////

void transmit_morse(String sentence) {
  int len = sentence.length();
  Serial.println(sentence);

  // For each letter of the sentence
  for(int i=0; i<len; i++) {
    if (sentence[i]==' ') space();
    else {
      transmit(encode(sentence[i]));
      if (i<len-1 && sentence[i+1]!=' ') btw_letter_space();
    }
  }
  
  space();
  Serial.println();
}

String encode(char letter){
  switch (letter) {
    case 'a': return ".-";
    case 'b': return "-...";
    case 'c': return "-.-.";
    case 'd': return "-..";
    case 'e': return ".";
    case 'f': return "..-.";
    case 'g': return "--.";
    case 'h': return "....";
    case 'i': return "..";
    case 'j': return ".---";
    case 'k': return "-.-";
    case 'l': return ".-..";
    case 'm': return "--";
    case 'n': return "-.";
    case 'o': return "---";
    case 'p': return ".--.";
    case 'q': return "--.-";
    case 'r': return ".-.";
    case 's': return "...";
    case 't': return "-";
    case 'u': return "..-";
    case 'v': return "...-";
    case 'w': return ".--";
    case 'x': return "-..-";
    case 'y': return "-.--";
    case 'z': return "--..";
    
    case '0': return "-----";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
  }
  return "";
}

// Transmits dots and lines correctly spaced.
void transmit(String morse_char) {
  int len = morse_char.length();
  for(int i=0; i<len; i++){
    if (morse_char[i]=='.') dot();
    else if (morse_char[i]=='-') line();
    if (i!=len-1) wtn_letter_space();
  }
}

//
void func_0() {
  simpleBlink(4*T);
}

void func_1() {
  simpleBlink(T);
}

void func_2() {
  simpleBlink(4*T/random(1, 5));
}

void func_3() {
  transmit_morse("suca");
}

void func_4() {
  transmit_morse("sos");
}

void func_5() {

}

void func_6() {

}

void func_7() {

}

void func_8() {

}

void func_9() {
}
