int buttonpin = 3;
int ledpin = 2;
int time_delay, time_var;
int reaction = 0;

unsigned int val = 0;


void STOPcount(){
  val = TCNT1;
  TCCR1B = 0;
  TIMSK1 = 0;
  }

void setup() {
  pinMode(buttonpin , INPUT);
  pinMode(ledpin, OUTPUT);
  
  
  TCNT1 = 0;    // Timer 
  TCCR1A = 0;   // working in 
  TCCR1B = 0;   // normal mode
  
  attachInterrupt(digitalPinToInterrupt(buttonpin), STOPcount , HIGH);// Switch as interrupt
  interrupts();
  Serial.begin(9600);
}


ISR(TIMER1_OVF_vect){ //Recording each overflow
  reaction++;
}





void loop() {
  
  TCNT1 = 0;      //counter value set to 0 for next reaction time reading
  reaction = 0;   //number of overflows set to 0

  
  time_var = random(1,10);
  time_delay = time_var*1000;
  
  delay(time_delay);
  digitalWrite(ledpin, HIGH);
  
  
  TCCR1B = (1<<CS10);
  TIMSK1 |= (1 << TOIE1);

  while(digitalRead(buttonpin) == LOW){}
  digitalWrite(ledpin, LOW);

  
  
  long unsigned time = reaction*65536 + val;  //Total time
  double time_total = (double)(time);         //Time is seconds
  time_total = time_total/16000000;
  Serial.println();
  Serial.print(time_total,8);
  Serial.print(" seconds");
}
