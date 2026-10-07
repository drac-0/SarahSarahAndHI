# This either would be random side project or a total dedication to cope from AnnaKav stagnant process

## Foreword

midterm is here, but i couldn't care less. Grade can be whatever it is. College can be whatever it is. People can be whoever they are. 

i don't know what this project purpose in the first place, i just haven't make any significant progress in my life beside setting up the server.

One thing cross my mind when i brew the homeserver. And that is **SSH Alerter**.

This is pretty exciting, finally i step my foot onto the baremetal programming.

## Adjustment in makefile

my working environment is linux, so this mini program might not be working properly in other OS.

Anyway, here is a little adjustment you need to make before using the program

inside the makefile, there is two part you need to change, since the setup i have might different from you

1. -mmcu=(the microcontroller architecture you use)
```
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o led.o led.c
```

2. ATMEGA328 to your microcontroller architecture and the /dev/ttyUSB0 to the interface for you arduino

```
sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:led.hex
```


## Afterword

it's nice to have my hand working on something



