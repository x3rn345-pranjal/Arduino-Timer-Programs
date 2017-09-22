void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  TCNT1 = 0;
  TCCR1A = 0;
  TCCR1A |= (1<<COM1A0) |  (1<<WGM10) | (1<<WGM11);
  TCCR1B = 0;
  TCCR1B = (1<<WGM13) | (1<<WGM12) | (1<<CS10);
  OCR1A = 833;  
}

void loop() {
  // put your main code here, to run repeatedly:

}
