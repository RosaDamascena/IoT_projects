import RPi.GPIO as GPIO
import time

TrigPin = 16
EchoPin = 20
BUZZER = 21

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(TrigPin, GPIO.OUT)
GPIO.setup(EchoPin, GPIO.IN)

GPIO.setup(BUZZER, GPIO.OUT)

p = GPIO.PWM(BUZZER, 261.6)
p.start(50)

def distance() :
    GPIO.output(TrigPin, True)
    time.sleep(0.00001)
    GPIO.output(TrigPin, False)
    
    while GPIO.input(EchoPin) == 0 :
        start_time = time.time()
        
    while GPIO.input(EchoPin) == 1 :
        end_time = time.time()
        
    duration = end_time - start_time
    distanceCm = duration * 17000
    distanceCm = round(distanceCm, 2)
    return distanceCm

try :
    while True:
        distanceCm = distance()
        if (distanceCm >= 0) and (distanceCm<10) :
            print("do")
            p.ChangeFrequency(261.6)
        elif (distanceCm >= 10) and (distanceCm<13) :
            print("le")
            p.ChangeFrequency(293.6)
        elif (distanceCm >= 13) and (distanceCm<16) :
            print("mi")
            p.ChangeFrequency(329.6)
        elif (distanceCm >= 16) and (distanceCm<19) :
            print("fa")
            p.ChangeFrequency(349.2)
        elif (distanceCm >= 19) and (distanceCm<22) :
            print("sol")
            p.ChangeFrequency(392.0)
        elif (distanceCm >= 22) and (distanceCm<25) :
            print("la")
            p.ChangeFrequency(440.0)
        elif (distanceCm >= 25) and (distanceCm<28) :
            print("si")
            p.ChangeFrequency(493.9)
        elif (distanceCm >= 28) and (distanceCm<31) :
            print("5oc do")
            p.ChangeFrequency(523.0)
        else :
            print("no")
            p.ChangeFrequency(1.0)
            
        print("cm:", distanceCm)
        time.sleep(0.5)
        
except KeyboardInterrupt :
    pass

GPIO.cleanup()