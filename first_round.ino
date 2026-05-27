/*
  This program is for digital reading bot where use two back sensor
  applicable for first round and final code
*/
#define buz_hi digitalWrite(buzzer,HIGH)
#define buz_low digitalWrite(buzzer,LOW)

int n1 = 12, n2 = 11, n3 = 7, n4 = 8, e1 = 10, e2 = 9; // final pin for arshad vai bot of motor running
int sen1 = 28 , sen2 = 30 , sen3 = 32 , sen4 = 34 , sen5 = 36 , sen6 = 38 , sen7 = 40 , back1 = 26 , back2 = 24;
// final sensor name of pin from left
int s1, s2, s3, s4, s5, s6, s7, b1, b2;


/////////////////////////////////////////////////////////////////
int buzzer = 15;
/////////////////////////////////////////////////////////////////
int white;
int black;
int line_color = white;;// '1' means line color black

/////////////////////////////////////////////////////////////////
int ss1, ss2, ss3, ss4, ss5, ss6, ss7;
//////////////////////////////////////////////////////////////
int gg1,gg2, gg3, gg4, gg5, gg6, gg7;

int TX3 = 14;
void setup()
{
  Serial.begin(9600);
  pinMode(sen1, INPUT); // for sensor pin
  pinMode(sen2, INPUT);
  pinMode(sen3, INPUT);
  pinMode(sen4, INPUT);
  pinMode(sen5, INPUT);
  pinMode(sen6, INPUT);
  pinMode(sen7, INPUT);
  pinMode(back1, INPUT);
  pinMode(back2, INPUT);

  ////////////////////////////////////////////////////////////////////
  pinMode(n1, OUTPUT);    // for motor driver pin
  pinMode(n2, OUTPUT);
  pinMode(n3, OUTPUT);
  pinMode(n4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  /////////////////////////////////////////////////////////////
  pinMode(buzzer, OUTPUT);

  ////////////////////////////////////////////////////////////////////
  buz_hi;
  delay(250);
  buz_low;
  delay(250);
  pinMode(TX3, INPUT); // use for button
  ////////////////////////////////////////////////////////////////////
 
  
  //////////////////////////////////////////////////////////////////
  while (digitalRead(TX3) == HIGH)
  {
    delay(10);
  }
  buz_hi;
  delay(250);
  buz_low;
  delay(250);
  buz_hi;
  delay(250);
  buz_low;
  delay(250);
}


void loop()
{
   read_sensor();
   if ((s1 + s2 + s3 + s4 + s5 + s6 + s7) >= 6)
    {
      buz_hi;
      bot(-250,-250);
      delay(50);
      bot(0,0);
      delay(20);
      bot(120, 120);
      b1 = 0;
      while (b1 == 0)
      {
         
        bot(120, 120);
        read_sensor();
      }
      read_sensor();
      if ((s1 + s2 + s3 + s4 + s5 + s6 + s7) >= 6)
      {
        bot(-250, -250);
        delay(40);
        bot(0, 0);
        delay(20);
        buz_hi;
        for (int t = 0; t<3 ; t++ )
        {
        delay(1000);
        }
        buz_low;
        
        while (1);
      }
      else
      {
      normal_line();
      }
    }

    //////////////////////////////////////////////////////////////////////
   else if ((s1 + s2 +s3 + s4) >= 3)
    {
      bot(180, 180);
      b1 = 0;
      while (b1 == 0)
      {
        bot(180, 180);
        read_sensor();
      }

      read_sensor();// to check bot position on line
      if ((s1 + s2 + s3 + s4 + s5 + s6 + s7) >= 6)
      { 
        bot(180, 180);
        delay(100);
        read_sensor();
      if ((s1 + s2 + s3 + s4 + s5 + s6 + s7) >= 6)
      { 
        bot(180, 180);
        delay(100);
        read_sensor();
      if ((s1 + s2 + s3 + s4 + s5 + s6 + s7) >= 6)
      {
         buz_hi;
        bot(-250, -250);
        delay(40);
        bot(0, 0);
        delay(20);
        buz_hi;
        for (int t = 0; t<3 ; t++ )
        {
        delay(1000);
        }
        buz_low;
        while (1);
      }
      else
      {
      normal_line();
      }
      }
        else
      {
      normal_line();
      }
      }
      else if ((( s7) == 0) && (s2==1 || s3 == 1 || s4 == 1 || s5 == 1 ))
       {
        bot(180, 180);
        delay(70);
        read_sensor();
     if ((( s7) == 0) && (s2==1 || s3 == 1 || s4 == 1 || s5 == 1 ))
       {
        bot(180, 180);
        delay(150);
        read_sensor();
    
        if ((( s7) == 0) && (s2==1 || s3 == 1 || s4 == 1 || s5 == 1 ))
        { 
            normal_line();
       
         }
          else
          {
             buz_hi;
            left_move();
             buz_low;
          }
        }
          else
          {
             buz_hi;
            left_move();
             buz_low;
          }
       }
      else
          {
             buz_hi;
            left_move();
             buz_low;
          }
     
    }// end of left found condition
    /////////////////////////////////////////////////////////////////////////////////
 else if ((s7 + s6 + s5 + s4) >= 3) 
    {
      
      bot(180, 180);
      b2 = 0;
      while (b2 == 0)
      {
        bot(180, 180);
        read_sensor();
      }
      read_sensor();// to check bot position on line
        if ((s1 + s2 + s3 + s4 + s5 + s6 + s7) >= 6)
      { 
        bot(180, 180);
        delay(100);
        read_sensor();
       if ((s1 + s2 + s3 + s4 + s5 + s6 + s7) >= 6)
      { 
        bot(180, 180);
        delay(100);
        read_sensor();
      if ((s1 + s2 + s3 + s4 + s5 + s6 + s7) >= 6)
      {
         buz_hi;
        bot(-250, -250);
        delay(40);
        bot(0, 0);
        delay(20);
        buz_hi;
        for (int t = 0; t<3 ; t++ )
        {
        delay(1000);
        }
        buz_low;
        while (1);
      }
      else
      {
      normal_line();
      }
      }
        else
      {
      normal_line();
      }
      }
     else if (((s1 ) == 0) && ( s3 == 1 || s4 == 1 || s5 == 1 || s6 == 1))
      {
        bot(180, 180);
        delay(70);
        read_sensor();
     if (((s1 ) == 0) && ( s3 == 1 || s4 == 1 || s5 == 1 || s6 == 1))
      {
        bot(180, 180);
        delay(150);
        read_sensor();
       if (((s1 ) == 0) && ( s3 == 1 || s4 == 1 || s5 == 1 || s6 == 1))
        {
       normal_line();
        }
      
      else
      {
         buz_hi;
        right_move();
         buz_low;
      }
      
    }
         else
      {
         buz_hi;
        right_move();
         buz_low;
      }
      
    }

    else
      {
         buz_hi;
        right_move();
         buz_low;
      }
     
    }
    // end of right found condition
        ////////////////////////////////////////////////////////////
     else if ((s1 + s2 >=1)&&( s3 + s4 + s5 + s6 + s7 + b1+ b2 == 0))
  {
  s4=0;
  while (s4==0)
  {
  bot(-120,120);
  read_sensor();
  }
   
  }
  /////////////////////////////////////////////////////////////////////
   else if ((s7 + s6 >=1)&&( s3 + s4 + s5 + s1 + s2 + b1+ b2 == 0))
  {
  s4=0;
  while (s4==0)
  {
  bot(120,-120);
  read_sensor();
  }

  } 
    //////////////////////////////////////////////////////////  
     else
      {
      normal_line();
      }
}
//////////////////////////////////////////////////////////
void left_move()
/////////////////////////////////////////////////////////
{
  bot(-250, -250);
  delay(40);
  bot(0, 0);
  delay(20);
  bot(-120, 120);
  delay(250);
  s4 = 0;
  while (s4 == 0)
  {
    bot(-120, 120);
    read_sensor();
  }
  bot(-250, -250);
  delay(20);
  bot(0, 0);
  delay(10);
}

void right_move()
/////////////////////////////////////////////////////////
{
  bot(-250, -250);
  delay(40);
  bot(0, 0);
  delay(20);
  bot(120, -120);
  delay(250);
  s4 = 0;
  while (s4 == 0)
  {
    bot(120, -120);
    read_sensor();
  }
  bot(-250, -250);
  delay(20);
  bot(0, 0);
  delay(10);
}

void normal_line()
{
  //////////////////////////////////////////////////////////////
//  read_sensor();
  //////////////////////////////////////////////////////////////
  if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 1 && s5 == 0 && s6 == 0 && s7 == 0)
  {
    bot(220, 220);    //CW   CW//STRAIGHT
  }

  /////////////////////////////////////////////////////////////////////
  else if (s1 == 0 && s2 == 0 && s3 == 1 && s4 == 1 && s5 == 0 && s6 == 0 && s7 == 0)
  {
    bot(110, 180);	//CW   CW//lefT
  }
  else if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 1 && s5 == 1 && s6 == 0 && s7 == 0)
  {
    bot(180, 110);	//CW   CW//right
  }

  //////////////////////////////////////////////////////////////////////
  else if (s1 == 0 && s2 == 0 && s3 == 1 && s4 == 0 && s5 == 0 && s6 == 0 && s7 == 0)
  {
    bot(40, 180);	//CW   CW//lefT

  }
  else if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 1 && s6 == 0 && s7 == 0)
  {
    bot(180, 40);	//CW   CW//right
  }

  /////////////////////////////////////////////////////////////////
  else if (s1 == 0 && s2 == 1 && s3 == 1 && s4 == 0 && s5 == 0 && s6 == 0 && s7 == 0)
  {
    bot(0, 180);	//CCW  CW//hard left
  }
  else if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 1 && s6 == 1 && s7 == 0)
  {
    bot(180, 0);	 //CW  CCW//hard right
  }
  /////////////////////////////////////////////////////
  else if (s1 == 0 && s2 == 1 && s3 == 0 && s4 == 0 && s5 == 0 && s6 == 0 && s7 == 0)
  {
    bot(-50, 180);	//CCW  CW//hard left
  }
  else if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 0 && s6 == 1 && s7 == 0)
  {
    bot(180, -50);	 //CW  CCW//hard right
  }
  /////////////////////////////////////////////////////////////
  else if (s1 == 1 && s2 == 1 && s3 == 0 && s4 == 0 && s5 == 0 && s6 == 0 && s7 == 0)
  {
    bot(-110, 180);	//CCW  CW//hard left
  }
  else if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 0 && s6 == 1 && s7 == 1)
  {
    bot(180, -110);	 //CW  CCW//hard right
  }
  /////////////////////////////////////////////////////////////
  else if (s1 == 1 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 0 && s6 == 0 && s7 == 0)
  {
    bot(-180, 180);	//CCW  CW//hard left
  }
  else if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 0 && s6 == 0 && s7 == 1)
  {
    bot(180, -180);	 //CW  CCW//hard right
  }
}// end of normal_line function


void bot(int left, int right)// left motor value// right motor value
/////////////////////////////////////////////////////
{
  left =(left+15);
  if (left == 0)
  {
    left_motor(0, left);
  }
  else if (left > 0)
  {
    left_motor(1, left);
  }
  else
  {
    left_motor(2, -left);
  }
  /////////////////////////////////////right motor
  if (right == 0)
  {
    right_motor(0, 0);
  }
  else if (right > 0)
  {
    right_motor(1, right);
  }
  else
  {
    right_motor(2, -right);
  }

}


void left_motor(int dir, int spd)// sub function for left motor operation
//////////////////////////////////////////////////////////////////
{
  if (dir == 1) // for forward
  {
    digitalWrite(n1, HIGH);
    digitalWrite(n2, LOW);
  }
  else if (dir == 2) // for reverse
  {
    digitalWrite(n2, HIGH);
    digitalWrite(n1, LOW);
  }
  else// FOR STOP
  {
    digitalWrite(n2, LOW);
    digitalWrite(n1, LOW);
  }
  analogWrite(e1, spd);
}

void right_motor(int dir, int spd)// function for right motor operation
{
  if (dir == 1) //for forward
  {
    digitalWrite(n3, HIGH);
    digitalWrite(n4, LOW);
  }
  else if (dir == 2) // for reverse
  {
    digitalWrite(n4, HIGH);
    digitalWrite(n3, LOW);
  }
  else
  {
    digitalWrite(n3, LOW);
    digitalWrite(n4, LOW);
  }
  analogWrite(e2, spd);
}


void read_sensor()
//////////////////////////////////////////////////////
{
  if (line_color == white)
  {
    if (digitalRead(sen1) == LOW)
      s1 = 0;
    else
      s1 = 1;

    if (digitalRead(sen2) == LOW)
      s2 = 0;
    else
      s2 = 1;

    if (digitalRead(sen3) == LOW)
      s3 = 0;
    else
      s3 = 1;

    if (digitalRead(sen4) == LOW)
      s4 = 0;
    else
      s4 = 1;

    if (digitalRead(sen5) == LOW)
      s5 = 0;
    else
      s5 = 1;

    if (digitalRead(sen6) == LOW)
      s6 = 0;
    else
      s6 = 1;

    if (digitalRead(sen7) == LOW)
      s7 = 0;
    else
      s7 = 1;

    if (digitalRead(back1) == LOW)
      b1 = 0;
    else
      b1 = 1;

    if (digitalRead(back2) == LOW)
      b2 = 0;
    else
      b2 = 1;
  }
  else
  {
     if (digitalRead(sen1) == LOW)
      s1 = 1;
    else
      s1 = 0;

    if (digitalRead(sen2) == LOW)
      s2 = 1;
    else
      s2 = 0;

    if (digitalRead(sen3) == LOW)
      s3 = 1;
    else
      s3 = 0;

    if (digitalRead(sen4) == LOW)
      s4 = 1;
    else
      s4 = 0;

    if (digitalRead(sen5) == LOW)
      s5 = 1;
    else
      s5 = 0;

    if (digitalRead(sen6) == LOW)
      s6 = 1;
    else
      s6 = 0;

    if (digitalRead(sen7) == LOW)
      s7 = 1;
    else
      s7 = 0;

    if (digitalRead(back1) == LOW)
      b1 = 1;
    else
      b1 = 0;

    if (digitalRead(back2) == LOW)
      b2 = 1;
    else
      b2 = 0;
  }
}
