from time import sleep
from machine import Pin
a = 0

led = Pin(25, Pin.OUT)
state = 0

while True:
    led.toggle()
    sleep(0.05)
        
    