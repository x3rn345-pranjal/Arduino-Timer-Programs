# Arduino-Timer-Programs
This contains all the programs along with their explanations.

The Timer is operated on fast PWM mode where TOP value is set in OCR1A. The value in OCR1A corresponds to the number of cycles after which flag is toggled. Thus to achieve the frequency of 9600Hz toggle must happen after 833 steps. 1 step corresponds to 1/16MHz time as if one take 'X' number of steps then it corresponds to X/16MHz time when the compare flag toggles. To get two toggles which correspond to a complete (one HIGH and one LOW state) we equate

![Alt text](https://github.com/x3rn345-pranjal/Arduino-Timer-Programs/blob/master/CodeCogsEqn.gif)

Thus gettting X = 833 as required number of steps.

# Arduino-Timer-Project: Measuring Reaction Time
The schematic was implemented as shown here.

![Alt text](https://github.com/x3rn345-pranjal/Arduino-Timer-Programs/blob/master/Timer%20Project_bb.jpg)

The circuit lights the led and the buzzer at the same time providing two stimulus for reaction. The direct supply is not used instead the led and buzzer are manually controlled by state of pin 2. When the push button is pressed the code is such that the led and the buzzzer goes off and the time interval i.e the time the buzzer and led were on are noted.

The time is captured with the help of inbuilt 16bit timer. The maximum accuracy of the timer is 100ns which is 10 times better then using the inbuilt function 'micros()' .
