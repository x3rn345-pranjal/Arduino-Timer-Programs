int i = 0;
void setup() {
  Serial.begin(115200);
  pinMode(8, INPUT);
}

void print_frequency(int frequency)
{
  Serial.println(frequency);
}

void loop() {
  //int input;
  //input = digitalRead(8);
  //Serial.print(input);
  i++;
  
  int period;
  float frequency;
  period = pulseIn(8,HIGH);
  period = 2*period;
  frequency = 1000000/period; 

  if (i == 2)
    print_frequency(frequency);
}


