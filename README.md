# Arduino Christmas Lights
This setup allows an Arduino to control a (cheap) strip of LED lights in order to simulate an (expensive) array of christmas lights. The cheap LED lights are not controllable individually.
### Features
 - 10 different blinking functions (extendable to 2^10=1024 functions if input are interpreted as binary, might be a fun future extension)
 - Each function can be either:
   - A fixed blinking interval (see func_0() and func_1() in the code)
   - A blinking pattern (see func_2() and func_5() in the code)
   - A MORSE transmission (see func_3() and func_4() in the code)
 - The LED strip only has a + and a - morset and no other control, so it is electrically equivalent to a single led (see scheme below). There is no resistor connected to the LED since the led strip consumes enough power.
 ### Schematic
 !(Schematic)[schematic.png]
