#define sensor A1
#define pump A0
int avg_window=20;
int threshold=300;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(pump, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int curr_avg = 0;
  for (int i = 0; i < avg_window; i++) {
    int current_reading = analogRead(sensor);
    curr_avg += current_reading;
    delay(10);
  }  
  curr_avg = curr_avg / avg_window;
  if (curr_avg < threshold) {
    Serial.println(pump, 1023);
    analogWrite(pump, 1023);
    delay(5000);
  }
  analogWrite(pump, 0);
  Serial.println(curr_avg);
}
