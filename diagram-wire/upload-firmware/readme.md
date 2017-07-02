# Sử dụng Arduino Uno để nạp firmware cho module thu phát WiFi ESP8266 V1

* **Thực hiện:** Thi Minh Nhựt - **Email:** thiminhnhut@gmail.com

* **Thời gian:** Ngày 02 tháng 07 năm 2017

## Nguồn tham khảo

* [CORDOBO - Flash ESP8266-01 with Arduino Uno](http://cordobo.com/2300-flash-esp8266-01-with-arduino-uno/)

## Các bước thực hiện:

* Thực hiện kết nối module WiFi ESP8266 V1 và Arduino Uno như sơ đồ bên dưới:

	+ File Fritzing: [upload-firmware-esp8266v1.fzz](https://github.com/thiminhnhut/esp8266v1/blob/e32ac07e5e60ad408d3db009c4304f8301a8b8bd/diagram-wire/upload-firmware/upload-firmware-esp8266v1.fzz)

	+ Mạch kết nối trên Breadboard:
	
	![Upload firmware ESP8266 V1 với Arduino Uno](https://raw.githubusercontent.com/thiminhnhut/esp8266v1/e32ac07e5e60ad408d3db009c4304f8301a8b8bd/diagram-wire/upload-firmware/upload-firmware-esp8266v1_bb.png)
	
	+ Mạch nguyên lý schematic:
	
	![Upload firmware ESP8266 V1 với Arduino Uno](https://raw.githubusercontent.com/thiminhnhut/esp8266v1/e32ac07e5e60ad408d3db009c4304f8301a8b8bd/diagram-wire/upload-firmware/upload-firmware-esp8266v1_schem.png)

* Các phần mềm cần chuẩn bị cho quá trình nạp firmware cho ESP8266 V1 trên hệ điều hành Ubuntu:

	+ [Arduino IDE](https://www.arduino.cc/en/main/software): https://www.arduino.cc/en/main/software

	+ [Python 2](https://www.python.org/downloads/): https://www.python.org/downloads/
	
		Được cài đặt sẵn trên hệ điều hành.

	+ [Pip](https://pypi.python.org/pypi/pip): https://pypi.python.org/pypi/pip
	
		Có thể sử dụng lệnh cài đặt:

		```bash

		$ sudo apt-get install python-pip

		```

	+ [esptool](https://pypi.python.org/pypi/esptool): https://pypi.python.org/pypi/esptool
	
		Có thể sử dụng lệnh cài đặt:

		```bash

		sudo pip install esptool

		```
	
	+ [Pyserial](https://pypi.python.org/pypi/pyserial/2.7): https://pypi.python.org/pypi/pyserial/2.7
	
		Có thể sử dụng lệnh cài đặt:
	
		```bash
	
		$ sudo pip install pyserial
	
		```

	+ [ESP8266 V1 firmware](https://github.com/thiminhnhut/esp8266v1/blob/45adc9adb733d796801b79265804057a7ef4552c/firmware/ESP8266_AT_V00180902_04.bin)
	
	Được file có tên `ESP8266_AT_V00180902_04.bin`.

* Thực hiện nạp firmware cho ESP8266 V1 trên hệ điều hành Ubuntu:

	+ Tạo thưc mục `esptool-master` và di chuyển file `ESP8266_AT_V00180902_04.bin`
	đến thư mục `esptool-master`:
	
		```bash
	
		$ cd
		
		$ mkdir esptool-master
		
		$ mv Downloads/ESP8266_AT_V00180902_04.bin esptool-master/
		
		```
	
	+ Tìm tên port kết nối giữa Arduino Uno và máy tính: mở Arduino IDE để xem (vào Tools)
	hoặc sử dụng lệnh `ls /dev/tty*`. Ví dụ tên cổng kết nối là `ttyACM0`.
	
	+ Xóa flash:
		
		- Thực hiện lệnh sau:
	
		```bash
		
		$ sudo esptool.py --port /dev/ttyACM0 erase_flash
		
		```
	
		- Xuất hiện thông báo tương tự như sau:
	
		```bash
		
		esptool.py v2.0
		
		Connecting....
		
		Detecting chip type... ESP8266
		
		Chip is ESP8266
		
		Uploading stub...
		
		Running stub...
		
		Stub running...
		
		Erasing flash (this may take a while)...
		
		Chip erase completed successfully in 2.8s
		
		Hard resetting...
		
		```
	
		- Nếu xuất hiện lỗi thì rút cáp ra và kết nối lại để module ESP8266 V1 reset.
		Đợi 5s và lặp lại lệnh trên.
		
	+ Nạp firmware cho ESP8266 V1:
	
		- Rút cáp ra và kết nối lại để module ESP8266 reset. Đợi 5s.
		
		- Thực hiện lệnh sau:
		
		```bash
		
		$ sudo esptool.py --port /dev/ttyACM0 write_flash 0x00000 ESP8266_AT_V00180902_04.bin
		
		```
		
		- Xuất hiện thông báo tương tự như sau:
	
		```bash
		
		esptool.py v2.0
		
		Connecting....
		
		Detecting chip type... ESP8266
		
		Chip is ESP8266
		
		Uploading stub...
		
		Running stub...
		
		Stub running...
		
		Configuring flash size...
		
		Auto-detected Flash size: 1MB
		
		Flash params set to 0x0020
		
		Compressed 520192 bytes to 135542...
		
		Wrote 520192 bytes (135542 compressed) at 0x00000000 in 11.9 seconds (effective 348.8 kbit/s)...
		
		Hash of data verified.
		

		Leaving...
		
		Hard resetting...

		
		```
		
	+ Hoàn thành quá trình nạp firmware cho ESP8266 V1.
