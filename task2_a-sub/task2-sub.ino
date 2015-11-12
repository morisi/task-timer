#include <MsTimer2.h>
const int trig = 4; //Trig ピンをデジタル 4 番に接続 
const int echo = 5; //Echo ピンをデジタル 5 番に接続 
unsigned long interval; //Echo のパルス幅 
float l, time = 0, a, start_t, goal_t;
int i = 0, b = 0;

void countsec(){ //時間の計測
  time = millis();
  Serial.println(time/1000);
  }

void setup() { 
  pinMode(trig, OUTPUT);//4 番を出力ポートに設定 
  pinMode(echo, INPUT);//5 番を入力ポートに設定  
  Serial.begin(9600);
  MsTimer2::set(50, countsec); // タイマ割り込み間隔の設定(T=500ms)
  MsTimer2::start(); // タイマ割り込み開始*/
} 
 
 void loop(){
   
  if( b == 0){
  //time = millis(); 
  digitalWrite(trig, HIGH); //10μs のパルスをセンサーに入力 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); //LOW に戻す 
  
  interval = pulseIn(echo, HIGH, 500000);//Echo 信号が HIGH である時間(μs)を計測 
  l = (331.5 + 0.61 * 25) * interval / 1000000 / 2 * 100;//距離の計算 
   
  //Serial.println(time/1000);
  
  
  
  if(l > 5 && l < 10 && i == 0){//距離が10ｃｍ未満の時 
  Serial.println("start");
  start_t = millis();
  i = 1;
   }
   
   else if(l > 40 && l < 100 && i == 1){
    Serial.println("goal");
    goal_t = millis();
   i = 2; 
   }
   
   //else if(l <= 5){
     
   
  else if(i == 2){
    a = goal_t - start_t;
   Serial.println(a/1000);
   i = 0;
  }
  
  }
   delay(100); //次の Trig 信号の入力まで 100ms 待機 
 
 }
