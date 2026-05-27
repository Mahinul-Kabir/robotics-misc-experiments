
#include <SoftwareSerial.h>

int IN1 = 7; //LEFT MOTOR
int IN2 = 8;
int E1 = 6;

int IN3 = 9; //RIGHT MOTOR
int IN4 = 10;
int E2 = 11;

int s1, s2, s3, s4, s5; //sensor name converted into degital
int Sen1, Sen2, Sen3, Sen4, Sen5; //sensor analog value varriable name
int X1,X2,X3,X4,X5;

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(E1, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(E2, OUTPUT);

 Serial.begin(9600);   //serial communication initialise
autocalib();
delay(5000);
}

void loop()
{
  Sensor_calibration();
  Read_Sensor();
  normal_line();

  //  if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 1 && s5 == 1) //for left 90
  //  {
  //    motor(200, 200);
  //    delay(100);
  //    motor(-200, -200);
  //    delay(50);
  //    motor(-150, 150);
  //    delay(80);
  //    s3 = 1;
  //    while (s3 == 1)
  //    {
  //      motor(-150, 150);
  //      Read_Sensor();
  //    }
  //  }
  //
  //
  //  else if (s1 == 1 && s2 == 1 && s3 == 0 && s4 == 0 && s5 == 0) //for right 90
  //  {
  //    motor(200, 200);
  //    delay(100);
  //    motor(-200, -200);
  //    delay(50);
  //    motor(150, -150);
  //    delay(80);
  //    s3 = 1;
  //    while (s3 == 1)
  //    {
  //      motor(150, -150);
  //      Read_Sensor();
  //    }
  //  }
  //
  //  else
  //  {
  //    normal_line();
  //  }
}




//////////////for normal curve line////////
void normal_line()
{
  Read_Sensor();
  if (s1 == 1 && s2 == 1 && s3 == 0 && s4 == 1 && s5 == 1)
  {
    motor(100, 100);
  }
  else if (s1 == 1 && s2 == 0 && s3 == 0 && s4 == 1 && s5 == 1)
  {
    motor(80, 100);
  }
  else if (s1 == 1 && s2 == 0 && s3 == 1 && s4 == 1 && s5 == 1)
  {
    motor(60, 100);
  }

  else if (s1 == 0 && s2 == 0 && s3 == 1 && s4 == 1 && s5 == 1)
  {
    motor(0, 100);
  }
  else if (s1 == 0 && s2 == 1 && s3 == 1 && s4 == 1 && s5 == 1)
  {
    motor(-100, 150);
  }

  else if (s1 == 1 && s2 == 1 && s3 == 0 && s4 == 0 && s5 == 1)
  {
    motor(100, 80);
  }
  else if (s1 == 1 && s2 == 1 && s3 == 1 && s4 == 0 && s5 == 1)
  {
    motor(100, 60);
  }
  else if (s1 == 1 && s2 == 1 && s3 == 1 && s4 == 0 && s5 == 0)
  {
    motor(100, 0);
  }
  else if (s1 == 1 && s2 == 1 && s3 == 1 && s4 == 1 && s5 == 0)
  {
    motor(150, -100);
  }
}



//////for sensor analog read///////////
void Read_Sensor()
{
  Sen1 = analogRead(A1);
  if (Sen1 > X1)
    s1 = 1;
  else
    s1 = 0;

  Sen2 = analogRead(A2);
  if (Sen2 > X2)
    s2 = 1;
  else
    s2 = 0;


  Sen3 = analogRead(A3);
  if (Sen3 > X3)
    s3 = 1;
  else
    s3 = 0;


  Sen4 = analogRead(A4);
  if (Sen4 > X4)
    s4 = 1;
  else
    s4 = 0;

  Sen5 = analogRead(A5);
  if (Sen5 > X5)
    s5 = 1;
  else
    s5 = 0;


}


///////////for display sensor value////////
void Sensor_calibration()
{
  Read_Sensor();

  Serial.print("Sen1=");
  Serial.print(Sen1);
  Serial.print(" ; ");
  Serial.print("Sen2=");
  Serial.print(Sen2);
  Serial.print(" ; ");
  Serial.print("Sen3=");
  Serial.print(Sen3);
  Serial.print(" ; ");
  Serial.print("Sen4=");
  Serial.print(Sen4);
  Serial.print(" ; ");
  Serial.print("Sen5=");
  Serial.print(Sen5);
  Serial.println();
  Serial.println();
  delay(500);
}




///////////motor function//////////////////
void motor(int L_spd, int R_spd)
{

  Left_motor(L_spd);
  Right_motor(R_spd);


}


void Left_motor(int L_spd)
{
  if (L_spd > 0)
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(E1, L_spd);

  }
  else if (L_spd < 0)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(E1, -L_spd);

  }
  else if (L_spd == 0)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(E1, 0);

  }
}

void Right_motor(int R_spd)
{
  if (R_spd > 0)
  {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(E2, R_spd);

  }
  else if (R_spd < 0)
  {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(E2, -R_spd);
  }
  else if (R_spd == 0)
  {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(E2, 0);
  }
}

void autocalib()
    {
    int ax1 = analogRead(A1);
    int ax2= analogRead(A2);
    int ax3= analogRead(A3);
    int ax4= analogRead(A4);
    int ax5= analogRead(A5);
    delay(2000);
    motor(100,100);
    delay(500);
    motor(0,0);
    int bx1 = analogRead(A1);
    int bx2= analogRead(A2);
    int bx3= analogRead(A3);
    int bx4= analogRead(A4);
    int bx5= analogRead(A5);

X1=(ax1+bx1)/2;
X2=(ax2+bx2)/2;
X3=(ax3+bx3)/2;
X4=(ax4+bx4)/2;
X5=(ax5+bx5)/2;
    
    }


