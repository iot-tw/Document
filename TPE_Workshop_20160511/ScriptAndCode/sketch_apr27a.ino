#include <SoftwareSerial.h>   // 引用程式庫
 
// 定義連接LoRa模組的序列埠
SoftwareSerial LoRa(10, 11); // 接收腳, 傳送腳
char val;  // 儲存接收資料的變數
 
void setup() {
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial.println("LoRa is ready!");
  Serial.write('\r');
  // 設定LoRa模組的連線速率
  LoRa.begin(9600);
  
  //用print 的方式自動下達AT command
  
}
 
void loop() {
 //送出測試資料 lat: 25.045361, long:121.522544, batteryLevel:200, temp: 30, state: 10(00001010)
  // LoRa.print("AT+DTX=22,073E4970017E2971C81E0A\r");
  // delay(1500*60);
  //自行輸入AT command
 if (Serial.available()) {
    val = Serial.read();
    LoRa.print(val);
    
  }
  // 若收到LoRa模組的資料，則送到「序列埠監控視窗」
  ;
  if (LoRa.available() ) {
    val = LoRa.read();
    Serial.print(val);
  }
}