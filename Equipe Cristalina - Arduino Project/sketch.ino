#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Servo.h>

#define DS18B20_PIN A0
#define EC_PIN A1
#define PH_PIN A2
#define DO_PIN A3
#define LDR_PIN A4
#define SERVO_LEFT_PIN 9
#define SERVO_RIGHT_PIN 10

OneWire oneWire(DS18B20_PIN);
DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo servoLeft;
Servo servoRight;

unsigned long previousSensorMillis = 0;
unsigned long previousServoMillis = 0;
unsigned long previousLcdMillis = 0;
const long sensorInterval = 5000;
const long servoInterval = 1000;
const long lcdInterval = 5000;
int led1 = 13;
int led2 = 12;

void setup() {
  Serial.begin(9600);
  sensors.begin();
  lcd.init();
  lcd.backlight();
  servoLeft.attach(SERVO_LEFT_PIN);
  servoRight.attach(SERVO_RIGHT_PIN);
  servoLeft.write(90);
  servoRight.write(90);
  Serial.println("Leituras dos Sensores:");
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousSensorMillis >= sensorInterval) {
    previousSensorMillis = currentMillis;

    lcd.setCursor(0, 0);
    lcd.print("Monitor de Agua");

    sensors.requestTemperatures();
    float temperatureC = sensors.getTempCByIndex(0);
    int ecValue = analogRead(EC_PIN);
    float ecVoltage = ecValue * (5.0 / 1023.0);
    int phValue = analogRead(PH_PIN);
    float phVoltage = phValue * (5.0 / 1023.0);
    float ph = 3.5 * phVoltage;
    int doValue = analogRead(DO_PIN);
    float doVoltage = doValue * (5.0 / 1023.0);
    int ldrValue = analogRead(LDR_PIN);

    Serial.println("Leituras dos Sensores:");
    Serial.print("Temperatura: ");
    Serial.print(temperatureC);
    Serial.println(" °C");

    Serial.print("Condutividade Elétrica: ");
    Serial.print(ecVoltage);
    Serial.println(" V");

    Serial.print("pH: ");
    Serial.println(ph);

    Serial.print("Oxigênio Dissolvido: ");
    Serial.print(doVoltage);
    Serial.println(" V");

    Serial.print("Luminosidade: ");
    Serial.println(ldrValue);

    boolean contaminada = false;
    float limitePH = 7.0;
    float limiteEC = 2.5;
    float limiteDO = 3.0;

    if (ph > limitePH || ecVoltage > limiteEC || doVoltage < limiteDO || ldrValue > 500) {
      contaminada = true;
      lcd.setCursor(0, 1);
      lcd.print("Agua Contaminada");
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
    } else {
      lcd.setCursor(0, 1);
      lcd.print("Agua Segura         ");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
    }

    previousLcdMillis = currentMillis;
  }

  if (currentMillis - previousLcdMillis >= lcdInterval) {
    lcd.clear();
  }

  if (currentMillis - previousServoMillis >= servoInterval) {
    previousServoMillis = currentMillis;
    moverServo();
  }
}

void moverServo() {
  static int moveState = 0;

  moveState = (moveState + 1) % 4;

  switch (moveState) {
    case 0:
      servoLeft.write(180);
      servoRight.write(180);
      break;
    case 1:
      servoLeft.write(0);
      servoRight.write(0);
      break;
  }
}
