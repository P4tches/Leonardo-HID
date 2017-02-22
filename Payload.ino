#include <HID.h>
#include <Keyboard.h>

#define LED_NUMLOCK    (1 << 0)
#define LED_CAPSLOCK   (1 << 1)
#define LED_SCROLLLOCK (1 << 2)
uint8_t keyNone[8] = { 0, 0, 0, 0, 0, 0, 0 };

void setup() {
  Keyboard.begin();
  checkBoard();
  //insert HID code after here
  delay(500);
  Keyboard.press(0x87);//Minimize all windows
  Keyboard.press('m');
  Keyboard.releaseAll();
  delay(100);
  Keyboard.press(0x87); //Windows GUI
  Keyboard.press(0x72); //'R'
  Keyboard.releaseAll();
  delay(700);
  Keyboard.print("cmd");
  Keyboard.write(0xB0); //return
  delay(1000);
  Keyboard.print("ipconfig");
  Keyboard.write(0xB0);
  delay(100);
  Keyboard.press(0x87);//Minimize all windows
  Keyboard.press('m');
  Keyboard.releaseAll();
}

void loop() {
  // put your main code here, to run repeatedly:
}

void checkBoard(){
  delay(3000);
  boolean caps=false;
  while(caps==false){
    uint8_t ledStatus;
    delay(100);
    Keyboard.write(136+83);
    //Keyboard.release(136+83);
    delay(100);
    ledStatus = Serial.read();
  if (ledStatus & LED_NUMLOCK) {
    break;     
  }}
  Keyboard.write(136+83);
  //Keyboard.release(136+83);
  delay(500);
}

void uac(){
  delay(1000);
  Keyboard.write(0xD8);
  //Keyboard.release(0xD8);
  Keyboard.write(0xB0); //return
}
