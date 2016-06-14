# attiny
ATtiny microcontroller support for the Arduino IDE

The AtTiny?5 microcontroller is an 8 pin AVR microcontroller, with different amounts of memory depending on the model. The AtTyiny?4 is a 14 pin chip. All these chips can be programmed using the Arduino IDE, using this package.

# Installing AtTiny support for Arduino

In your Arduino ID, install AtTiny support.
Paste the following URL as a new line in the following text box to tell the
IDE there's a new source for board configurations:

Menu: File -> Preferences -> Settings -> Additional Boards Manager URLs:

https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json

Now go to the boards manager to fetch and install AtTiny support.

Menu: Tools/Board/Boards Manager...

Scroll until you find the AtTiny support, and click the install button.

# Wiring the AtTiny

To program the chip, you will need a separate Arduino board with an USB board that you can program. The Arduino UNO is the ideal choice. You will need one capacitor, and wire 4 data pins plus 5V power and ground to the microcontroller. A breadboard is a good way to do so.

look up the ArduinoISP wiring diagram.

For example: http://highlowtech.org/?p=1695

# Programming the AtTiny

Fist, program your board to be an ISP.

Menu: File -> Examples -> 11.ArduinoISP
Compile this for your board.

Second: Install a capacitor between the board's reset pin and ground to prevent it from reseting. Also make sure your AtTiny is wired properly to your board.

Third: Select the AtTiny board and frequency at which you want it to run. Beware that if you pick External Clock, the Attiny will not work unless you wire it with an external crystal. For testing, stick with an internal clock (8 or 16MHz).

Change the programmer from AVRISP mkII to ArduinoISP.

Upload the code ( -> icon).

