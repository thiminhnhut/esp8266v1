/* Su dung Atom Editor voi PlatformIO
 * Ket noi WiFi cho Arduino Uno voi module ESP8266 V1
 * Thuc hien: Thi Minh Nhut - Email: thiminhnhut@gmail.com
 * Thoi gian: Ngay 02 thang 07 nam 2017
 */

#include <Arduino.h>
#include <SoftwareSerial.h>

void Config(); // Cau hinh cho module ESP8266
void ConnectWiFi(String NetworkSSID, String NetworkPASS); // Ket noi WiFi
String GetResponse(String AT_Command, int wait); // Doc thong tin tra ve tu ESP8266
void clearSerialBuffer(); // Xoa du lieu thua

SoftwareSerial ESPSerial(12, 13); // RX, TX use for monitor
HardwareSerial & MonitorSerial = Serial;

String ssid = "Tam7";
String pass = "21019400";

void setup(){
    MonitorSerial.begin(9600);
    ESPSerial.begin(9600);

    Config(); // Cau hinh cho module ESP8266
}

void loop(){

}

void Config(){
    /* Function: Cau hinh cho ESP8266 voi tap lenh AT
     */

    clearSerialBuffer();

    // Kiem tra module san sang hoat dong hay chua
    MonitorSerial.print("AT : ");
    MonitorSerial.println(GetResponse("AT", 100));

    // Chon mode STA
    MonitorSerial.print("AT+CWMODE=1 : ");
    MonitorSerial.println(GetResponse("AT+CWMODE=1", 10));

    // Ket noi WiFi
    ConnectWiFi(ssid, pass);
    delay(5000);

    // Che do multiple connection
    MonitorSerial.print("AT+CIPMUX=1 : ");
    MonitorSerial.println(GetResponse("AT+CIPMUX=1", 10));

    // Xem dia chi IP
    MonitorSerial.print("IP address: ");
    MonitorSerial.println(GetResponse("AT+CIFSR", 10));
    delay(200);
}

void ConnectWiFi(String NetworkSSID, String NetworkPASS){
    /* Function: Ket noi WiFi cho ESP8266 V1
     * Su dung tap lenh AT
     */
    String cmd = "AT+CWJAP=\"";
    cmd += NetworkSSID;
    cmd += "\",\"";
    cmd += NetworkPASS;
    cmd += "\"";
    MonitorSerial.println(cmd);
    MonitorSerial.println(GetResponse(cmd, 10));
}

String GetResponse(String AT_Command, int wait){
    /* Function: Doc du lieu tu Module ESP8266 gui ve
     * va hien thi len man hinh de quan sat
     */
    String tmpData;

    ESPSerial.println(AT_Command);
    delay(wait);
    while (ESPSerial.available() > 0){
        char c = ESPSerial.read();
        tmpData += c;

        if (tmpData.indexOf(AT_Command) > -1){
            tmpData = "";
        }
        else{
            tmpData.trim();
        }
   }
   return tmpData;
}

void clearSerialBuffer(){
       while (ESPSerial.available() > 0){
         ESPSerial.read();
       }
}
