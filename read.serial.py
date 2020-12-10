import serial

ser = serial.Serial('/dev/ttyACM0')
f = open("data.txt","a")

while True:
    try:
        read_serial = ser.readline()
        #//bpm = read_serial.decode('utf-8').strip()
        #//print(bpm)
        print(read_serial)
        f.write(read_serial)
        f.flush()
    except KeyboardInterrupt:
        print("Exiting ......")
        break
