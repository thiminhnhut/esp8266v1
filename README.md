# Sử dụng module thu phát WiFi ESP8266 V1

* **Thực hiện:** Thi Minh Nhựt - **Email:** thiminhnhut@gmail.com

* **Thời gian bắt đầu:** Ngày 25 tháng 06 năm 2017

## Nguồn tham khảo

1. [CORDOBO - Flash ESP8266-01 with Arduino Uno](http://cordobo.com/2300-flash-esp8266-01-with-arduino-uno/)

2. [Amith MP - Connecting ESP8266-01 to Arduino UNO/ MEGA and BLYNK](https://www.instructables.com/id/Connecting-ESP8266-01-to-Arduino-UNOMEGA-and-BLYNK/)

3. [Connect to ESP8266 ONLY using Arduino Uno](https://forum.arduino.cc/index.php?topic=283043.0)

4. [Arduino to ESP8266 By Serial Communication](http://www.martyncurrey.com/arduino-to-esp8266-serial-commincation/)

## Sơ đồ và chức năng của các chân trên module WiFi ESP8266 V1

* Sơ đồ chân:

![Sơ đồ chân module ESP8266 V1](https://raw.githubusercontent.com/thiminhnhut/esp8266v1/master/diagram-wire/esp8266_pinout.png)

* Chức năng của các chân:

	+ Chân số 1 - RX: Chân RX của giao thức UART, nối đến chân TX của vi điều khiển.

	+ Chân số 2 - VCC: +3.3V.
	
	+ Chân số 3 - GPIO0: kéo xuống mức thấp cho chế độ upgrade firmware.
	
	+ Chân số 4 - RST: Chân Reset ở mức thấp.
	
	+ Chân số 5 - GPIO2: không sử dụng.	
	
	+ Chân số 6 - CH_PD: Chân quy định thu phát WiFi.
	Chân CH_PD được kéo lên mức thì bắt đầu thu phát WiFi.
	Chân CH_PD được kéo xuống mức thấp thì dừng thu phát WiFi.
	
	+ Chân số 7 - GND: 0V.
	
	+ Chân số 8 - TX: Chân TX của giao thức UART, nối đến chân RX của vi điều khiển.


## Sử dụng Arduino Uno để nạp firmware cho module thu phát WiFi ESP8266 V1

	[Xem hướng dẫn thực hiện.](https://github.com/thiminhnhut/esp8266v1/tree/5f0cc97069c7dc7b1cbf2f8b146486254e41189a/diagram-wire/upload-firmware)

## Kết nối module thu phát WiFi ESP8266 V1 với Arduino Uno

	[Xem hướng dẫn thực hiện.](https://github.com/thiminhnhut/esp8266v1/tree/5f0cc97069c7dc7b1cbf2f8b146486254e41189a/diagram-wire/connect-esp8266v1)
