#include <IRremote.hpp>    // Include the library
#define IR_RECEIVE_PIN 11  // IR receiver pin 11
void setup() {
  Serial.begin(9600);                                     // Message will be sent to PC
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the receiver
}
void loop() {
  if (IrReceiver.decode())  // Received IR signal
  {
    switch (IrReceiver.decodedIRData.decodedRawData)  // Remote IR codes
    {
      case 0xC94900802002: Serial.print("OK "); break;
      case 0xCE4E00802002: Serial.print("LEFT "); break;
      case 0xCF4F00802002: Serial.print("RIGHT "); break;
      case 0xCA4A00802002: Serial.print("FORWARD "); break;
      case 0xCB4B00802002: Serial.print("REVERSE "); break;
      case 0x901000802002: Serial.print("1 "); break;
      case 0x911100802002: Serial.print("2 "); break;
      case 0x921200802002: Serial.print("3 "); break;
      case 0x931300802002: Serial.print("4 "); break;
      case 0x941400802002: Serial.print("5 "); break;
      case 0x951500802002: Serial.print("6 "); break;
      case 0x961600802002: Serial.print("7 "); break;
      case 0x971700802002: Serial.print("8 "); break;
      case 0x981800802002: Serial.print("9 "); break;
      case 0x991900802002: Serial.print("0 "); break;
      case 0xA12100802002: Serial.print("Volume down "); break;
      case 0xA02000802002: Serial.print("Volume up "); break;
      default: Serial.print("other button ");
    }
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // Print raw data
    IrReceiver.resume();                                           // Enable receiving of the next value
  }
}

//3. ให้แก้ไขคำสั่งภายใน switch case ดังตัวอย่างข้างล่าง โดยเพิ่มเข้าไปในโปรแกรมข้อที่ 1 หรือข้อที่ 2 ก็ได้ ตาม Remote Control ที่นำมาทดลองใช้งานได้ เพื่อให้แสดงปุ่มกดต่างๆ ของคำสั่งใน Remote ที่นำมาใช้งาน//
