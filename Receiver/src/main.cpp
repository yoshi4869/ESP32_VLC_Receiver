#include <Arduino.h>
const int voutPin = 26;//フォトダイオードの割当ピン
const int LEDON_val = 10;//LED ONになる相当数のmV
void setup()
{
  Serial.begin(115200);
}

void loop()
{
  // R1の電圧を取得
  int reading = analogRead(voutPin);

  // AD値をmVに変換
  float voltage = ((long)reading * 5000) / 1024;

  Serial.print(voltage);
  Serial.print(" mV, ");

  // 電圧から電流を求める I=E/R (R=1000)
  float microamp = (voltage * 1000) / 1000;

  Serial.print(microamp);
  Serial.print(" uA, ");

  // 電流をlxに変換
  // S9648-100の照度係数は0.26mA/100lx
  float lx = microamp / (260 / 100);

  Serial.print(lx);
  Serial.print(" lx, ");
  Serial.print("data ");
  //ハイパスフィルタ R=220Ω, C=10^-6Fをつけている
  if(LEDON_val <= reading){
  Serial.println("1");
  }
  else{
  Serial.println("0");
  }
  delay(100);
}