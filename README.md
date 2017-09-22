# Arduino-Timer-Programs
This contains all the programs along with their explanations.

The Timer is operated on fast PWM mode where TOP value is set in OCR1A. The value in OCR1A corresponds to the number of cycles after which flag is toggled. Thus to achieve the frequency of 9600Hz toggle must happen after 833 steps. 1 step corresponds to 1/16MHz time as if one take 'X' number of steps then it corresponds to X/16MHz time when the compare flag toggles. To get two toggles which correspond to a complete (one HIGH and one LOW state) we equate
http://latex.codecogs.com/gif.latex?%5Cfrac%7B1%7D%7B9600Hz%7D%20%3D%20%5Cfrac%7B2*X%7D%7B16MHz%7D

Thus gettting X = 833 as required number of steps.
