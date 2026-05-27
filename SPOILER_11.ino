// TB6612FNG Motor Driver Pins
#define AIN1 4
#define AIN2 3
#define PWMA 2

#define BIN1 6
#define BIN2 7
#define PWMB 8

#define STBY 5

void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(STBY, OUTPUT);

  // Enable motor driver
  digitalWrite(STBY, HIGH);
}

void loop() {
  moveForward(100);   // Speed: 0–255
}

void moveForward(int speed) {
  // Motor A forward
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, speed);

  // Motor B forward
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, speed);
}
