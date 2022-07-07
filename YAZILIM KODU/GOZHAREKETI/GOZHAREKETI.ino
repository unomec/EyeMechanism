

#include <Servo.h> //KÜTÜPHANEYİ ÇAĞIRDIK.
int sagsol = 11; //hor, kendi kartına göre değiştir.
int altust = 10; //ver, servo çıkışı değiştir.

Servo horServo; // Horizontal servo (left tot right) //YATAY HAREKET SAĞ-SOL
 Servo verServo; // Vertical servo (Up and down)     //DİKEY HAREKET ALT-SÜT

// Change these settings to your own setup and preferences. //SAĞ SOL HAREKET AYARLARINI DEĞİŞTİREBİLİRSİNİZ.
 int horServoPin = sagsol;
 int horMaxLeft = 60; // Maximum servo position Left //SOLA GİTME AÇISI
 int horMid = 90; // Middle servo position horizontal //ORTA NOKTA AÇISI
 int horMaxRight = 120; // Maximum servo position Right //SAĞA GİTME AÇISI
 int horStep = 1; // Step size for position horizontal // 1 ER AÇI İLERLE YAPAR 

int verServoPin = altust; //ÜST ALT HAREKET AYARLARINI DEĞİŞTİREBİLİRSİNİZ.
 int verMaxUp = 45; // Maximum servo position Up //YUKARI GİTME AÇISI
 int verMid = 65; // Middle servo position vertical //ORTA NOKTA AÇISI
 int verMaxDown = 95; // Maximum servo position Down //AŞAĞI GİTME AÇISI
 int verStep = 1; // Step size for position vertical //1 ER AÇI İLERLEME YAPAR

int delaySpeed = 500; // time between the movement //HAREKETLER ARASI BEKLEME SÜRESİ
 int pos = 0; // variable to store the servo position //POSİZYON TANIMLANDI 0 DEĞİŞGENİ.
 int positionwait = 5; // variable to wait for the servo to reach the position //HAREKETİ TAMAMLAMA SÜRESİ

 //(TANIMLAMALARIMIZI GİRDİK.)

void setup()
 {
 horServo.attach(sagsol); // attaches the servo on horzontal pin //TETİKLEME UÇLARI.
 verServo.attach(altust); // attaches the servo on vertical pin

horServo.write(horMid); // Put horizontal servo in neutral position //GÖZÜ KARŞIYA BAKMASINI SAĞLIYORUZ.
 verServo.write(verMid); // Put vertical servo in neutral position
 }

 //(BİR KERE ÇALIŞTIRILAN YÜKLEME KODLARIMIZI YAZDIK.)

void loop()
 {

// Look right //SAĞA BAKMA KODU
 for(pos = horMid; pos <= horMaxRight; pos += horStep)
 {
 horServo.write(pos);
 delay(positionwait);
 }
 delay(delaySpeed);

// Look left //SOLA BAKMA KODU
 for(pos = horMaxRight; pos>=horMaxLeft; pos-=horStep)
 {
 horServo.write(pos);
 delay(positionwait);
 }
 delay(delaySpeed);

// Look neutral //KARŞIYA BAKMA KODU
 for(pos = horMaxLeft; pos<=horMid; pos+=horStep)
 {
 horServo.write(pos);
 delay(positionwait);
 }
 delay(delaySpeed);

// Look Up //YUKARI BAKMA KODU
 for(pos = verMid; pos <= verMaxDown; pos += verStep)
 {
 verServo.write(pos);
 delay(positionwait);
 }
 delay(delaySpeed);

// Look down //AŞAĞI BAKMA KODU
 for(pos = verMaxDown; pos>=verMaxUp; pos-=verStep)
 {
 verServo.write(pos);
 delay(positionwait);
 }
 delay(delaySpeed);

//Look neutral //KARŞIYA BAKMA KODU.
 for(pos = verMaxUp; pos <= verMid; pos += verStep)
 {
 verServo.write(pos);
 delay(positionwait);
 }
 delay(delaySpeed);
 }
