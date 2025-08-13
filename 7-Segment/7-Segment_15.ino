// กำหนดขา segment A ถึง G และจุดทศนิยม
int segmentA = A0;
int segmentB = A1;
int segmentC = A2;
int segmentD = 4;
int segmentE = 2;
int segmentF = 7;
int segmentG = 8;
int segmentDP = 13;

// ขาควบคุมหลักของ 7-segment 4 หลัก
int digit1 = 5;
int digit2 = 6;
int digit3 = 9;
int digit4 = 10;

// เซ็นเซอร์อุณหภูมิ
int tempSensorPin = A3;

int digitValues[4] = { 0, 0, 0, 0 };  // เก็บตัวเลขที่จะแสดง

void setup() {
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(segmentDP, OUTPUT);

  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);

  pinMode(tempSensorPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // อ่านอุณหภูมิ
  int raw = analogRead(tempSensorPin);
  float voltage = raw * (5.0 / 1023.0);
  float tempC = voltage * 10;  // สำหรับ LM35

  Serial.print("Temp = ");
  Serial.println(tempC, 2);

  // แปลงเป็นตัวเลข 4 หลัก ทศนิยม 2 ตำแหน่ง
  int displayValue = (int)(tempC * 100);  // เช่น 25.37 -> 2537

  digitValues[0] = (displayValue / 1000) % 10;  // หลักพัน
  digitValues[1] = (displayValue / 100) % 10;   // หลักร้อย
  digitValues[2] = (displayValue / 10) % 10;    // หลักสิบ
  digitValues[3] = displayValue % 10;           // หลักหน่วย

  // แสดงผลแบบ 7-segment
  for (int i = 0; i < 4; i++) {
    showDigit(i + 1, digitValues[i], i == 1);  // แสดงจุดทศนิยมหลังหลักที่ 2
    delay(5);                                  // หน่วงสลับหลัก
  }
}

// แสดงเลขแต่ละหลักพร้อมทศนิยมถ้าต้องการ
void showDigit(int digit, int number, bool showDot) {
  clearDisplay();
  displaySegment(number);
  digitalWrite(segmentDP, showDot ? HIGH : LOW);  // จุดทศนิยม

  // เปิดหลัก
  digitalWrite(digit1, digit == 1 ? HIGH : LOW);
  digitalWrite(digit2, digit == 2 ? HIGH : LOW);
  digitalWrite(digit3, digit == 3 ? HIGH : LOW);
  digitalWrite(digit4, digit == 4 ? HIGH : LOW);
}

// ดับทุก segment
void clearDisplay() {
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
  digitalWrite(segmentDP, LOW);
}

// แสดงตัวเลข 0-9
void displaySegment(int number) {
  switch (number) {
    case 0:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, LOW);
      break;
    case 1:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;
    case 2:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
      break;
    case 3:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
      break;
    case 4:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 5:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 6:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 7:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;
    case 8:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
    case 9:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;
  }
}