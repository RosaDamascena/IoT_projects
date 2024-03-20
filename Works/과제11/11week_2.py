import RPi.GPIO as GPIO
import time

ledRed=23
ledGreen=24
swPin=21

GPIO.setmode(GPIO.BCM)
GPIO.setup(ledRed, GPIO.OUT)
GPIO.setup(ledGreen, GPIO.OUT)
GPIO.setup(swPin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
swState=0

try:
    while 1:
        swValue=GPIO.input(swPin)
        if swValue == 1:
            if swState ==0:
                swState=1
            else:
                    swState=0
            time.sleep(0.5)
                    
        if swState ==1:
            GPIO.output(ledRed, GPIO.HIGH)
            GPIO.output(ledGreen, GPIO.LOW)
            time.sleep(0.1)
            GPIO.output(ledRed, GPIO.LOW)
            GPIO.output(ledGreen, GPIO.HIGH)
            time.sleep(0.1)
        else:
            GPIO.output(ledRed, GPIO.LOW)
            GPIO.output(ledGreen, GPIO.LOW)
            
        print(swState)
        time.sleep(0.1)
        
except KeyboardInterrupt:
     pass
        
GPIO.cleanup()