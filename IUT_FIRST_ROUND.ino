/*
  This program is for digital reading bot where use two back sensor
  applicable for first round and final code
*/
#define buz_hi digitalWrite(buzzer,HIGH)
#define buz_low digitalWrite(buzzer,LOW)

int n1 = 12, n2 = 11, n3 = 7, n4 = 8, e1 = 10, e2 = 9; // final pin for arshad vai bot of motor running
int sen1 = 40 , sen2 = 38 , sen3 = 36 , sen4 = 34 , sen5 = 32 , sen6 = 30 , sen7 = 28 , back1 = 26 , back2 = 24;
// final sensor name of pin from left
int s1, s2, s3, s4, s5, s6, s7, b1, b2;
int h = 0;
float duration_forward, duration_left, duration_right, duration_below;
float distance_forward, distance_left, distance_right, distance_below;
float length_forward, length_left, length_right,length_below;
////////////////////////////////////////////////////////////////////////////
int trigpin_forward = 6;
int echopin_forward = 5;

int trigpin_left = 42;
int echopin_left = 44;

int trigpin_right = 46;
int echopin_right = 48;

int trigpin_below = 50;
int echopin_below = 52;

/////////////////////////////////////////////////////////////////
int Kp =160;
int Ki =0;
int Kd =39;
float correction ;
float deviation ;
float totalerror =0;
float previous_deviation =0;
/////////////////////////////////////////////////////////////////
int buzzer = 15;
/////////////////////////////////////////////////////////////////
int line_color = 1;// '1' means line color black
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
  /////////////////////////////////////////////////////////////
  pinMode(trigpin_forward, OUTPUT);
  pinMode(echopin_forward, INPUT);

  pinMode(trigpin_left, OUTPUT);
  pinMode(echopin_left, INPUT);

  pinMode(trigpin_right, OUTPUT);
  pinMode(echopin_right, INPUT);
  pinMode(trigpin_below, OUTPUT);
  pinMode(echopin_below, INPUT);
  ////////////////////////////////////////////////////////////////////
  buz_hi;
  delay(250);
  buz_low;
  delay(250);
  pinMode(TX3, INPUT); // use for button
  ////////////////////////////////////////////////////////////////////
  read_sensor();
  
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
///////////////////////////////////////////////////////////////
{
if (((s1 + s2 + s3 + s4 + s5 + s6 + s7 )==7)&&(( b1 + b2)==2))
 {
 pid_sub();
 }


  if (h==1)
    {
      
    read_sensor();
   length_forward=read_sonar_forward();

    if((length_forward>0) && (length_forward<=20))
    {
       read_sensor();
       length_forward=read_sonar_forward();
       if((length_forward>0) && (length_forward<=20))
       { 
        bot(-180,-180);
         delay(20);
         bot(0,0);
         delay(10);
       
        length_forward>0;
         while(length_forward>0)
          {
           bot(0,0);
          length_forward=read_sonar_forward();
          }
      }
      else 
      {
          normal_line(); 
      }
    }
    }
   read_sensor();
   if ((s1 + s2 + s3 + s4 + s5 + s6 + s7) >= 6)
    {
      bot(180, 180);
      b1 = 0;
      while (b1 == 0)
      {
        bot(180, 180);
        read_sensor();
      }
      read_sensor();
      if ((s1 + s2 + s3 + s4 + s5 + s6 + s7) >= 6)
      {
        bot(-180, -180);
        delay(40);
        bot(0, 0);
        delay(20);
        while (1);
      }
      else
      {
      normal_line();
      }
    }
  else if ((s1 + s2 + s3 + s4 + s5 + s6 + s7) == 0)
  {
    bot(90, 90);
    delay(30);// to remove line break fault
    read_sensor();
    if ((s1 + s2 + s3 + s4 + s5 + s6 + s7) == 0)
    {
      bot(90,90);
      delay(10);// again check to remove line fault
      read_sensor();
      if ((s1 + s2 + s3 + s4 + s5 + s6 + s7) == 0) // must be break
      {
      
       decision_making();
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
    
  }// end of line break check condition
 
  //////////////////////////////////////////////////////////////////////////////////
   
    else if ((s1 + s2 +s3 + s4) >= 3)
    {
          length_left= read_sonar_left();
         if((length_left>0) && (length_left<=20))
         {
      
         decision_making();
         
         }

   else 
   {
      gg1 = 0, gg2 = 0, gg3 = 0, gg4 = 0, gg5 = 0, gg6 = 0, gg7 = 0;
      bot(180, 180);
      take_sample();
      b1 = 0;
      while (b1 == 0)
      {
        bot(180, 180);
        read_sensor();
         take_sample_two();
       
      }
      calculation();
      
      if (ss7+ss6>=1)
      
      {
        right_move();
      }
      else if (gg7+gg6>=1)
      {
          right_move();
             
          pid_sub();   
           
                    
           
      }
      else
      {
      read_sensor();// to check bot position on line
      if (((s1 + s7) == 0) && (s2==1 || s3 == 1 || s4 == 1 || s5 == 1 || s6 == 1))
       {
        bot(180, 180);
        delay(100);
        read_sensor();
        if (((s1 + s7) == 0) && (s2==1 || s3 == 1 || s4 == 1 || s5 == 1 || s6 == 1))
        { 
          bot(180, 180);
          delay(50);
          read_sensor();
          if (((s1 + s7) == 0) && (s2==1 || s3 == 1 || s4 == 1 || s5 == 1 || s6 == 1))
          {
            normal_line();
       
          }
          else
          {
            left_move();
          }
        }  
          else
          {
            left_move();
          }
    
      }
    else
        {
          left_move();
        }
     
      }
     }
     
    }// end of left found condition
    /////////////////////////////////////////////////////////////////////////////////
     
    
     else if ((s7 + s6 + s5 + s4) >= 3) 
    { 
      
     length_left= read_sonar_left();
     if((length_left>0) && (length_left<=20))
     {
        
     decision_making();
     
     }

    else
     {
      bot(180, 180);
      b2 = 0;
      while (b2 == 0)
      {
        bot(180, 180);
        read_sensor();
      }
      read_sensor();// to check bot position on line
     if ((( s7) == 0) && (  s3 == 1 || s4 == 1 || s5 == 1 || s6 == 1))
      {
        bot(180, 180);
        delay(50);
        read_sensor();
        if ((( s7) == 0) && (  s3 == 1 || s4 == 1 || s5 == 1 || s6 == 1))
        {
        right_move();
        }
      
      else
      {
        right_move();
      }
      
    }
     else
      {
        right_move();
      }
     }
    }// end of right found condition
    //////////////////////////////////////////////////////////
  else if ((s1 + s2 >=1)&&( s3 + s4 + s5 + s6 + s7 + b1+ b2 == 0))
  {
  
  s4=0;
  while (s4==0)
  {
  bot(-120,120);
  read_sensor();
  }
  }

    ////////////////////////////////////////////////////////////////
    else
    {
      normal_line();
    }
}

void decision_making()
/////////////////////////////////////////////////
{
  

    read_sensor();
 
   length_left=read_sonar_left();
  delay(2);
   length_right=read_sonar_right();
   
    if (((length_left>0)&&(length_left<=20)) &&((length_right>0)&& (length_right<=20)))

    {
          buz_hi;
        delay(50);
        buz_low;
      cave_function();
     
    
    }
    
    else if((length_right>0)&&(length_right<=20))
    {
     buz_hi;
     delay(50);
//  buz_low;
     inclint_bridge();
    }
   else
    {
    normal_line();
    
    }
   
}
//////////////////////////////////////////////////////////////////////////////////////////
void cave_function()
{
 
 int cave=1;
  while(cave==1)
  {
    read_sensor();
   length_right= read_sonar_right();
   length_left= read_sonar_left();

  if(length_right==0 && length_left==0)
    {
     bot(250,220);
     delay(30);
      length_right=read_sonar_left();
      length_left= read_sonar_left();
      if(length_right==0 && length_left==0)
      {
        bot(-200,-200);
        delay(50);
        bot(0,0);
        delay(500);
        buz_hi;
        delay(50);
        buz_low;
        cave = 0;
      }
      else
      {
        operation();
      }
    }
    else
    {
      operation();
    }
    
  }// while close
     
 h = 1; 
 
}
void operation()
{
  length_right= read_sonar_left();
  if(length_right>0 && length_right<=3)
    {
      bot(220,180);
    }
    else if(length_right>3 && length_right<=5)
    {
      bot(220,200);
    }
    else if(length_right>5 && length_right<=7)
    {
      bot(220,210);
    } 
    else if(length_right>7 && length_right<=9)
    {
      bot(190,200);
    }
    else if(length_right>9 && length_right<=11)
    {
      bot(170,200);
    }
    else if(length_right>11)
    {
      bot(160,200);
    }
}
////////////////////////////////////////////////////////////////////
void inclint_bridge()
{
      bot(-250,-250);
        delay(50);
        bot(0,0);
        delay(500);  
  int cave=1;
  while(cave==1)
  {
    read_sensor();
    length_forward=read_sonar_forward();
   delay(2);
   length_right=read_sonar_right();
   delay(2);
   length_below=read_sonar_below();
   delay (2);
   if((s1+s2+s3+s4+s5+s6+s7)>=1)
    {
      bot(110,110);
      delay(100);
      read_sensor();
      if((s1+s2+s3+s4+s5+s6+s7)>=1)
      {
        bot(-110,-110);
        delay(100);
        bot(0,0);
        delay(10);
       normal_line();
       cave = 0;
       buz_low;
      }
    }
   else if (length_below>10)
    {
    bot(-250,-250);
    delay(40);
    bot(0,0);
    delay(200);
    
    buz_low;
     length_below <10;
    while (length_below <10)
    {
      bot (0,0); 
    length_below=read_sonar_below(); 
   
    }
      for (int j=0;j<6;j++)
      {
      delay (1000);
      }
    }
   
    
    else if ((length_forward>0)&&(length_forward<13))
    {
    bot(-180,-180);
    delay(40);
    bot(0,0);
    delay(20);
    bot(-120,120);
    delay(450);
     bot(120,-120);
    delay(30);
    bot(0,0);
    delay(20);
    }
    
      else if(length_right>0 && length_right<=3)
    {
      bot(60,140);
    }
    else if(length_right>3 && length_right<=6)
    {
      bot(70,140);
    }
    else if(length_right>6 && length_right<=9)
    {
      bot(140,140);
    }
    else if(length_right>9 && length_right<=12)
    {
      bot(140,50);
    }
    else if(length_right>12 && length_right<=15)
    {
      bot(140,30);
    }
    else if(length_right>15 && length_right<=18)
    {
      bot(120,30);
    }
    else
    {
      bot(40,100);
    }
  }
  h = 1;
}
///////////////////////////////////////////////////////////

void   pid_sub()
{
  int l =0;
          while (l == 0)
          {
                read_sensor();
               length_forward=read_sonar_forward();
                if((length_forward>0) && (length_forward<=20))
                {
                   read_sensor();
                  length_forward=read_sonar_forward();
                   if((length_forward>0) && (length_forward<=20))
                   { 
                     bot(-180,-180);
                     delay(20);
                     bot(0,0);
                     delay(10);
                    length_forward>0;
                     while(length_forward>0)
                      {
                       bot(0,0);
                     length_forward=read_sonar_forward();
                      }
                  }
                }
                else if ((s1 + s2 + s3 + s4 + s5 + s6 + s7) == 0)
                    {
                      bot(120, 120);
                      delay(30);// to remove line break fault
                      read_sensor();
                      if ((s1 + s2 + s3 + s4 + s5 + s6 + s7) == 0)
                        {
                          bot(-250, -250);
                          delay(50);
                          bot(0, 0);
                          delay(500);
                           
                          l = 1;
                        } 
                      else
                        {
                        normal_line();
                        }
                    }
                  else if ((s1 + s2+ s3 + s4 + s5 ) == 0)
                  {
                   

                  bot(120,-120);
                  read_sensor();
                  delay (20);

                 
                  }
                 else if ((s7 + s6+ s5 + s4 + s3 ) == 0)
                  {
                   

              
                  bot(-120,120);
                  read_sensor();
                  delay (20);
                 
              
                }
              else
               {
                normal_line_pid();
                   
             }
           }
                    
}
/////////////////////////////////////////////////////////////
void check_position()
{
  int positionn = 0;
  while (positionn == 0)
  {
   length_forward=read_sonar_forward();
    if ((length_forward >= 17) && (length_forward <= 19))
    {
     bot(0, 0);
    }
    else if ((length_forward != 0) && (length_forward < 17))
    {
      bot(-90, -90);
   length_forward=read_sonar_forward();
      while (1)
      {

       length_forward=read_sonar_forward();
        if (length_forward < 17)
        {
          bot(-90, -90);
        }
        else if (length_forward > 19)
        {
          bot(90, 90);
        }
        else if ((length_forward >= 17) && (length_forward <= 19))
        {
          bot(100, 100);
          delay(20);

        }
        else if (length_forward <= 19)
        {
         bot(90, 90);
        }
       else if (length_forward >0)
      {
      
       positionn = 1;
       break;
      }
      }
      bot(-120, -120);
      delay(20);
      bot(0, 0);
      delay(100);
    }
  }
}
void exact_position()
///////////////////////////////////////////////////////////
{
  while (1)
  {
    read_sensor();
    if (((s4 + s3) == 2) || ((s4 + s5) == 2) || (s4 == 1))
    {
      break;
    }
    else if (s3 == 1)
    {
      bot(0, 90);
      delay(5);
    }
    else if (s5 == 1)
    {
      bot(90, 0);
      delay(5);
    }
    else if ((s3 + s2) == 2)
    {
      bot(0, 90);
      delay(5);
    }
    else if ((s5 + s6) == 2)
    {
      bot(90, 0);
      delay(5);
    }
  }

}

void left_move()
/////////////////////////////////////////////////////////
{
  bot(-180, -180);
  delay(50);
  bot(0, 0);
  delay(20);
  bot(-160, 160);
  delay(250);
  s4 = 0;
  while (s4 == 0)
  {
    bot(-160, 160);
    read_sensor();
  }
  bot(160, -160);
  delay(40);
  bot(0, 0);
  delay(10);
}

void right_move()
/////////////////////////////////////////////////////////
{
  bot(-180, -180);
  delay(50);
  bot(0, 0);
  delay(20);
  bot(160, -160);
  delay(250);
  s4 = 0;
  while (s4 == 0)
  {
    bot(160, -160);
    read_sensor();
  }
  bot(-160, 160);
  delay(40);
  bot(0, 0);
  delay(10);
}

void normal_line()
{
  //////////////////////////////////////////////////////////////
  read_sensor();
  //////////////////////////////////////////////////////////////
  if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 1 && s5 == 0 && s6 == 0 && s7 == 0)
  {
    bot(160, 160);    //CW   CW//STRAIGHT
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
    bot(56, 180);	//CW   CW//lefT

  }
  else if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 1 && s6 == 0 && s7 == 0)
  {
    bot(180, 56);	//CW   CW//right
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
    bot(-65, 170);	//CCW  CW//hard left
  }
  else if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 0 && s6 == 1 && s7 == 0)
  {
    bot(170, -65);	 //CW  CCW//hard right
  }
  /////////////////////////////////////////////////////////////
  else if (s1 == 1 && s2 == 1 && s3 == 0 && s4 == 0 && s5 == 0 && s6 == 0 && s7 == 0)
  {
    bot(-110, 170);	//CCW  CW//hard left
  }
  else if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 0 && s6 == 1 && s7 == 1)
  {
    bot(170, -110);	 //CW  CCW//hard right
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
  if (line_color == 1)
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
      b1 = 1;
    else
      b1 = 0;

    if (digitalRead(back2) == LOW)
      b2 = 1;
    else
      b2 = 0;
  }
}
//////////////////////////////////////////////////////////
void take_sample()
{
  ss1 = 0, ss2 = 0, ss3 = 0, ss4 = 0, ss5 = 0, ss6 = 0, ss7 = 0;
  bot(180, 180);
  int i = 0;
  for (i = 0; i <= 50; i++)
  {
    read_sensor();
    if (s1 == 1)
    { ss1++;
    }
    else
    { ss1--;
    }

    if (s2 == 1)
    { ss2++;
    }
    else
    { ss2--;
    }
    if (s3 == 1)
      ss3++;
    else
    { ss3--;
    }

    if (s4 == 1)
    { ss4++;
    }
    else
    { ss4--;
    }

    if (s5 == 1)
    { ss5++;
    }
    else
    { ss5--;
    }

    if (s6 == 1)
    { ss6++;
    }
    else
    { ss6--;
    }

    if (s7 == 1)
    { ss7++;
    }
    else
    { ss7--;
    }
    delay (1);

  }

  if (ss1 > 0)
  { ss1 = 1;
  }
  else
  { ss1 = 0;
  }

  if (ss2 > 0)
  { ss2 = 1;
  }
  else
  { ss2 = 0;
  }

  if (ss3 > 0)
  { ss3 = 1;
  }
  else
  { ss3 = 0;
  }

  if (ss4 > 0)
  { ss4 = 1;
  }
  else
  { ss4 = 0;
  }

  if (ss5 > 0)
  { ss5 = 1;
  }
  else
  { ss5 = 0;
  }

  if (ss6 > 0)
  { ss6 = 1;
  }
  else
  { ss6 = 0;
  }

  if (ss7 > 0)
  { ss7 = 1;
  }
  else
  { ss7 = 0;
  }

}
////////////////////////////
float read_sonar_forward()
{
  digitalWrite(trigpin_forward, LOW);
  delayMicroseconds(5);
  digitalWrite(trigpin_forward, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin_forward, LOW);
  duration_forward = pulseIn(echopin_forward, HIGH, 1800);
  distance_forward = duration_forward / 58.2;
  return distance_forward;
    
}

float read_sonar_left()
{
  digitalWrite(trigpin_left, LOW);
  delayMicroseconds(5);
  digitalWrite(trigpin_left, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin_left, LOW);
  duration_left = pulseIn(echopin_left, HIGH, 1800);
  distance_left = duration_left / 58.2;
  return distance_left;
  
}

float read_sonar_right()
{
  digitalWrite(trigpin_right, LOW);
  delayMicroseconds(5);
  digitalWrite(trigpin_right, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin_right, LOW);
  duration_right = pulseIn(echopin_right, HIGH, 1800);
  distance_right = duration_right / 58.2;
  return distance_right;
  
}

float read_sonar_below()
{
  digitalWrite(trigpin_below, LOW);
  delayMicroseconds(5);
  digitalWrite(trigpin_below, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin_below, LOW);
  duration_below = pulseIn(echopin_below, HIGH, 1800);
  distance_below = duration_below / 58.2;
 return distance_below;
 
}

/////////////////////////////////////////////////////////////////
  void getping_all()
{
  length_forward=read_sonar_forward();
  delay(2);
   length_left=read_sonar_left();
  delay(2);
   length_right=read_sonar_right();
  delay(2);
   length_right=read_sonar_below();
   delay (2);
}
//////////////////////////////////////////////////////////////
void take_sample_two()
{
     bot(180,180);
    if (s1 == 1)
    { gg1++;
    }
    else
    { gg1--;
    }

    if (s2 == 1)
    { gg2++;
    }
    else
    { gg2--;
    }
    if (s3 == 1)
      gg3++;
    else
    { gg3--;
    }

    if (s4 == 1)
    { gg4++;
    }
    else
    { gg4--;
    }

    if (s5 == 1)
    { gg5++;
    }
    else
    { gg5--;
    }

    if (s6 == 1)
    { gg6++;
    }
    else
    { gg6--;
    }

    if (s7 == 1)
    { gg7++;
    }
    else
    { gg7--;
    }

}
///////////////////////////////////////////
void calculation()
{
 
  if (gg1 > 0)
  { gg1 = 1;
  }
  else
  { gg1 = 0;
  }

  if (gg2 > 0)
  { gg2 = 1;
  }
  else
  { gg2 = 0;
  }

  if (gg3 > 0)
  { gg3 = 1;
  }
  else
  { gg3 = 0;
  }

  if (gg4 > 0)
  { gg4 = 1;
  }
  else
  { gg4 = 0;
  }

  if (gg5 > 0)
  { gg5 = 1;
  }
  else
  { gg5 = 0;
  }

  if (gg6 > 0)
  { gg6 = 1;
  }
  else
  { gg6 = 0;
  }

  if (ss7 > 0)
  { gg7 = 1;
  }
  else
  { gg7 = 0;
  }
}
////////////////////////////////////////////////////////////////
void  normal_line_pid()
{
pid();
cale_turn();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pid()
   {
    
   
   deviation = ((s1*-6 + s2*-4 + s3*-2 + s4*0 + s5*2 + s6*4 + s7*6)/(s1+s2+s3+s4+s5+s6+s7));
   correction = ((Kp*deviation)+(Ki*totalerror)+(Kd*(deviation-previous_deviation)));
   totalerror += correction;
   previous_deviation = deviation;
    if (correction>250)
      {
        correction = 250;
      }
    if(correction<-250)
      {
       correction = -250;
      }
         if (totalerror>250)
      {
        totalerror = 250;
      }
    if(totalerror<-250)
      {
        totalerror = -250;
      }


}
////////////////////////////////////////////////////////////////////////////////////////////// 
void cale_turn()
{
int left,right; 
if(deviation==0)
{
left = 250;
right =250;
}
else if(deviation>0)
{
left = 250;

right =(250 - correction);
}
else
{
left =( 250 + correction);

right =250;
}
bot(left,right);
}
