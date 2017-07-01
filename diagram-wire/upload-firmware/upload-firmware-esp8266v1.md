# Sử dụng Arduino Uno để nạp firmware cho module thu phát WiFi ESP8266 V1

* **Thực hiện:** Thi Minh Nhựt - **Email:** thiminhnhut@gmail.com

* **Thời gian:** Ngày 01 tháng 07 năm 2017

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

	+ [Sdk1.0.0 v0.22 ESP8266 V1 firmware](http://esp8266.ru/download/esp8266-firmware/AT22SDK100-2015-03-20-boot1.2.bin): http://esp8266.ru/download/esp8266-firmware/AT22SDK100-2015-03-20-boot1.2.bin
	
	Được file có tên `AT22SDK100-2015-03-20-boot1.2.bin`.

* Thực hiện nạp firmware cho ESP8266 V1 trên hệ điều hành Ubuntu:

	+ Tạo thưc mục `esptool-master` và di chuyển file `AT22SDK100-2015-03-20-boot1.2.bin`
	đến thư mục `esptool-master` vừa tạo và đổi tên thành `AT22SDK10020150320boot12.bin`:
	
		```bash
	
		$ cd
		
		$ mkdir esptool-master
		
		$ mv Downloads/AT22SDK100-2015-03-20-boot1.2.bin esptool-master/AT22SDK10020150320boot12.bin
		
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
		
		Connecting........
		
		Detecting chip type... ESP8266
		
		Chip is ESP8266
		
		Uploading stub...
		
		Running stub...
		
		Stub running...
		
		Erasing flash (this may take a while)...
		
		Chip erase completed successfully in 3.1s
		
		Hard resetting...
		
		```
	
		- Nếu xuất hiện lỗi thì rút cáp ra và kết nối lại để module ESP8266 V1 reset.
		Đợi 5s và lặp lại lệnh trên.
		
	+ Nạp firmware cho ESP8266 V1:
	
		- Rút cáp ra và kết nối lại để module ESP8266 reset. Đợi 5s.
		
		- Thực hiện lệnh sau:
		
		```bash
		
		$ sudo esptool.py --port /dev/ttyACM0 write_flash 0x00000 AT22SDK10020150320boot12.bin
		
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
		
		Compressed 520192 bytes to 172469...
		
		Wrote 520192 bytes (172469 compressed) at 0x00000000 in 15.0 seconds (effective 277.9 kbit/s)...
		
		Hash of data verified.
		
		Leaving...
		
		Hard resetting...
		
		```
		
	+ Hoàn thành quá trình nạp firmware cho ESP8266 V1.