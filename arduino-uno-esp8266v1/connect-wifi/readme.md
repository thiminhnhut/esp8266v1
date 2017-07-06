# Kết nối WiFi cho Arduino Uno với module thu phát WiFi ESP8266 V1 và thực hiện một số ứng dụng

* **Thực hiện:** Thi Minh Nhựt - **Email:** thiminhnhut@gmail.com

* **Thời gian:** Ngày 02 tháng 07 năm 2017

## Nội dung thực hiện

* Thực hiện upload firmware như hướng dẫn: [Xem hướng dẫn](https://github.com/thiminhnhut/esp8266v1/tree/cbbdf6947f443bad0e9579f01b98c3fde45db043/diagram-wire/upload-firmware)

* Kết nối WiFi cho Arduino Uno với ESP8266 V1 với giao tiếp mềm:
	
	+ Sơ đồ mạch phần cứng:

		- File Fritzing: [connect-esp8266v1-software.fzz](https://github.com/thiminhnhut/esp8266v1/blob/7bb52480c29d8cf17d14c7c7b884badafb029f14/diagram-wire/connect-esp8266v1/connect-esp8266v1-software.fzz)

		- Mạch kết nối trên Breadboard:
	
		![Kết nối ESP8266 V1 với Arduino Uno](https://raw.githubusercontent.com/thiminhnhut/esp8266v1/7bb52480c29d8cf17d14c7c7b884badafb029f14/diagram-wire/connect-esp8266v1/connect-esp8266v1-software_bb.png)
	
		- Mạch nguyên lý schematic:
	
		![Kết nối ESP8266 V1 với Arduino Uno](https://raw.githubusercontent.com/thiminhnhut/esp8266v1/7bb52480c29d8cf17d14c7c7b884badafb029f14/diagram-wire/connect-esp8266v1/connect-esp8266v1_schem.png)
		
	+ Chương trình mẫu: [connect-wifi](https://github.com/thiminhnhut/esp8266v1/tree/88824390287ad0d3f979065356e7e83a6b1bd648/arduino-uno-esp8266v1/connect-wifi)
