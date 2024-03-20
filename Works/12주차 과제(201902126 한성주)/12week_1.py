import spidev
import RPi.GPIO as GPIO
import time

ledwhite = 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(ledwhite, GPIO.OUT)

spi = spidev.SpiDev()
spi.open(0, 0)
spi.max_speed_hz = 1000000

def analogRead(ch) :
    buf = [(1<<2)|(1<<1)|(ch&4)>>2, (ch&3)<<6, 0]
    buf = spi.xfer(buf)
    adcValue = ((buf[1]&0xF)<<8)|buf[2]
    return adcValue

try :
    while 1 :
        cdsValue = analogRead(0)
        print(cdsValue)
        
        if cdsValue > 1000:
            GPIO.output(ledwhite, GPIO.HIGH)
        else :
            GPIO.output(ledwhite, GPIO.LOW)
            
        time.sleep(0.2)
        
except KeyboardInterrupt :
    pass

GPIO.cleanup()
spi.close()