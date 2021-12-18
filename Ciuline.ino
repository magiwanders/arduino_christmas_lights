const int pin_0 = 3; // Fixed Slow
const int pin_1 = 4; // Fixed Fast
const int pin_2 = 5; // Random blinks
const int pin_3 = 6;
const int pin_4 = 7;
const int pin_5 = 8;
const int pin_6 = 9;
const int pin_7 = 10;
const int pin_8 = 11;
const int pin_9 = 12;

int status = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
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

void simpleBlink(int interval) {
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(interval);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(interval); 
}

void simpleHigh(int interval) {
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(interval);                       
}

void simpleLow(int interval) {
  digitalWrite(LED_BUILTIN, LOW);    
  delay(interval); 
}

void dot() {
  simpleHigh(250);
  simpleLow(250);
}

void line() {
  simpleHigh(750);
  simpleLow(250);
}

void space() {
  simpleLow(750);  
}

void nextword() {
  simpleLow(1750);  
}

void func_0() {
  simpleBlink(1000);
}

void func_1() {
  simpleBlink(250);
}

void func_2() {
  simpleBlink(1000/random(1, 5));                 
}

void func_3() {
  dot();
  dot();
  dot();
  space();

  dot();
  dot();
  line();
  space();
  
  line();
  dot();
  line();
  dot();
  space();

  dot();
  line();

  nextword();
}

void func_4() {
  
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
