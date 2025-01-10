// 1 saniyede (1000 milisaniye) bir mavi led yanıp söner
#define maviLed 8 // 8. çıkış

void setup() {
  pinMode(maviLed, OUTPUT); // 8. pin
}

void loop() {
  digitalWrite(maviLed, HIGH); // voltajını yükseltir
  delay(1000); // 1 saniye bekler
  digitalWrite(maviLed, LOW); // voltajını düşürür
  delay(1000); // 1 saniye bekler
}