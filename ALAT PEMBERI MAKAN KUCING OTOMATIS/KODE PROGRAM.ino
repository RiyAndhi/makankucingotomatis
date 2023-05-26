#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 rtc;
char Hari[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
String hari;

int tanggal, bulan, tahun, jam, menit, detik;

#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

#include <Servo.h>
Servo makan;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  makan.attach(9);
  makan.write(0);

  rtc.begin(); // Memulai RTC
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Mengatur waktu RTC dengan waktu kompilasi
}

void loop() {
  // Data RTC
  DateTime now = rtc.now();
  hari = Hari[now.dayOfTheWeek()];
  tanggal = now.day();
  bulan = now.month();
  tahun = now.year();
  jam = now.hour();
  menit = now.minute();
  detik = now.second();

  // Tampilan Serial Monitor
  Serial.println(hari + " " + String(tanggal) + "/" + String(bulan) + "/" + String(tahun));
  Serial.println(String(jam) + ":" + String(menit) + ":" + String(detik));
  Serial.println();

  delay(1000);

  // Tampilan LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(hari + " " + String(tanggal) + "/" + String(bulan) + "/" + String(tahun));
  lcd.setCursor(0, 1);
  lcd.print(String(jam) + ":" + String(menit) + ":" + String(detik));

  // Atur Jadwal Makan Pagi
  if (jam == 5 && menit == 59 && detik == 59) 
  {
    makan.write(150);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Selamat Makan");
    lcd.setCursor(5, 1);
    lcd.print("Meong");
    delay(5000);
    makan.write(0);
    lcd.clear();
  }

  // Atur Jadwal Makan Siang
  if (jam == 11 && menit == 59 && detik == 59)
  {
    makan.write(150);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Selamat Makan");
    lcd.setCursor(5, 1);
    lcd.print("Meong");
    delay(5000);
    makan.write(0);
    lcd.clear();
  }

  // Atur Jadwal Makan Malam
  if (jam == 17 && menit == 59 && detik == 59) 
  {
    makan.write(150);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Selamat Makan");
    lcd.setCursor(5, 1);
    lcd.print("Meong");
    delay(5000);
    makan.write(0);
    lcd.clear();
  }

}
