# ATtiny Board Definitions for the Arduino IDE

Please note, that the installation depends on the version of your Arduino IDE.

After the installation, you should have several ATtiny variants available which are ATtiny44, 45, 84, 85 with speeds of 1, 8 and 20MHz for a total of 12 new entries in the `Tools > Board` menu of the Arduino IDE.

## Installation in Linux

### Arduino IDE Version 1.0.x

```
cd /tmp
wget https://github.com/damellis/attiny/archive/ide-1.0.x.zip
unzip ide-1.0.x.zip
sudo cp -r attiny-ide-1.0.x/attiny /usr/share/arduino/hardware/attiny
```

### Arduino IDE Version 1.6.x

```
wget https://github.com/damellis/attiny/archive/master.zip
unzip master.zip
sudo cp -r attiny-master /usr/share/arduino/hardware/attiny
```

