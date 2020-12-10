import serial

ser = serial.Serial('/dev/ttyACM0')
text = "oi1,oi2\n"
i = 0
while True:
    try:
        ser.write(i+text)
        #//bpm = read_serial.decode('utf-8').strip()
        #//print(bpm)
    except KeyboardInterrupt:
        print("Exiting ......")
        break
