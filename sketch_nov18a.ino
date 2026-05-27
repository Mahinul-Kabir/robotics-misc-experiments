//LINE CODE FOR NSU OF NEW ROBOT
#define WHITE 1
#define BLACK 0

int line_color=BLACK;

int n1=7,n2=5,n3=3,n4=2,e1=6,e2=4;    //for motor driver
int ss1=0,ss2=0,ss3=0,ss4=0,ss5=0,ss6=0,ss7=0;// this is sample variable
int S1,S2,S3,S4,S5,S6,S7;     //final sensor name
                                                     //                            LEFT SIDE    RIGHT SIDE
int sen1=53,sen2=51,sen3=49,sen4=47,sen5=45,sen6=43,sen7=41;//sensor output pin( - s1 s2 s3 "s4" s5 s6 s7 )

#define A digitalRead(sen1)
#define B digitalRead(sen2)
#define C digitalRead(sen3)
#define D digitalRead(sen4)
#define E digitalRead(sen5)
#define F digitalRead(sen6)
#define G digitalRead(sen7)


#define mb_pressed digitalRead(22)==LOW
#define rb_pressed digitalRead(24)==LOW

#define YELLOW_HI digitalWrite(26,HIGH)
#define YELLOW_LOW digitalWrite(26,LOW)
#define RED_HI digitalWrite(28,HIGH)
#define RED_LOW digitalWrite(28,LOW)
#define BLUE_HI digitalWrite(30,HIGH)
#define BLUE_LOW digitalWrite(30,LOW)
#define BUZ_HI digitalWrite(32,HIGH)
#define BUZ_LOW digitalWrite(32,LOW)

void setup()
{ 
  pinMode(30,OUTPUT);//for indicators
  pinMode(28,OUTPUT);
  pinMode(26,OUTPUT); 
  pinMode(24,OUTPUT);
 pinMode(32,OUTPUT); 
  
  pinMode(n1,OUTPUT);//as output for 293D
  pinMode(n2,OUTPUT);
  pinMode(n3,OUTPUT);
  pinMode(n4,OUTPUT);
  pinMode(e1,OUTPUT);
  pinMode(e2,OUTPUT);
  //////////////////////////////////

 /////////////////////////////////// 
  pinMode(sen1,INPUT); //as input
  pinMode(sen2,INPUT);
  pinMode(sen3,INPUT);
  pinMode(sen4,INPUT);
  pinMode(sen5,INPUT);
  pinMode(sen6,INPUT);
  pinMode(sen7,INPUT);
//  int setup_com=1;
  

   while(mb_pressed)
  {
    delay(10);
  }
  BUZ_HI;
  delay(250);
  BUZ_LOW;
  RED_HI;
  delay(250);
  RED_LOW;
  YELLOW_HI;
  delay(250);
  YELLOW_LOW;
  BLUE_HI;
  delay(250);
  BLUE_LOW;
  delay(10);
}

 void loop()
  {
    while(1)
    {
      read_sensor();
      
    //////////////////////////////////////////////////////////////////////////////
    if(((S1+S2+S3+S4)>=3)&&((S6+S7)==0))
      {
        bot(220,220);
        delay(70);
        read_sensor();
        if((S2+S3+S4+S5+S6)>=1)
        {
          normal_line();
        }
        else
        {
          left_move();
        }
      }
      
      
      //////////////////////////////////////////////////////////////////////////////
  //  else if((((S6+S7)>=1)&&(S4==1)&&((S1+S2)==0)) || (((S4+S5+S6+S7)>=3)&&((S1+S2)==0)))
  else if(((S4+S5+S6+S7)>=3)&&((S1+S2)==0))
    {
      bot(220,220);
        delay(70);
        read_sensor();
        if((S2+S3+S4+S5+S6)>=1)
        {
          normal_line();
        }
        else
        {
          right_move();
        }
    }
//////////////////////////////////////////////////////////////////////////////////////////
   
//////////////////////////////////////////////////////////////////////////////////////////
  else
  {
    normal_line();
  }   
 }
}
////////////////////////////////////////////////////////////////////////////////////////////


    
    
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void normal_line()
{
   //////////////////////////////////////////////////////////////
   read_sensor();
   BUZ_LOW;
   ////////////////////////////////////////////////////////////// 
   if(S1==0 && S2==0 && S3==0 && S4==1 && S5==0 && S6==0 && S7==0)
  {			
    //bot(180,180);     //CW   CW//STRAIGHT
    bot(200,200);
  }
  
  /////////////////////////////////////////////////////////////////////
  else if(S1==0 && S2==0 && S3==1 && S4==1 && S5==0 && S6==0 && S7==0) 
  {
      //bot(100,180);	//CW   CW//lefT	
      bot(140,200);
  }
  else if(S1==0 && S2==0 && S3==0 && S4==1 && S5==1 && S6==0 && S7==0) 
  {
    //bot(180,100);	//CW   CW//right
    bot(200,140);
  }
  
 ////////////////////////////////////////////////////////////////////// 
  else if(S1==0 && S2==0 && S3==1 && S4==0 && S5==0 && S6==0 && S7==0)
  {
      //bot(40,180);	//CW   CW//lefT
      bot(80,200);
		
  }
  else if(S1==0 && S2==0 && S3==0 && S4==0 && S5==1 && S6==0 && S7==0)
  {
    //bot(180,40);	//CW   CW//right
    bot(200,80);
  }
  
  /////////////////////////////////////////////////////////////////
  else if(S1==0 && S2==1 && S3==1 && S4==0 && S5==0 && S6==0 && S7==0)
  {
    bot(40,180);	//CCW  CW//hard left
  }
  else if(S1==0 && S2==0 && S3==0 && S4==0 && S5==1 && S6==1 && S7==0) 
  {
    bot(180,40);	 //CW  CCW//hard right
  } 
  /////////////////////////////////////////////////////
  else if(S1==0 && S2==1 && S3==0 && S4==0 && S5==0 && S6==0 && S7==0)
  {
    //bot(-60,180);	//CCW  CW//hard left
    bot(0,180);
  } 
  else if(S1==0 && S2==0 && S3==0 && S4==0 && S5==0 && S6==1 && S7==0)
  {
   // bot(180,-60);	 //CW  CCW//hard right
   bot(180,0);
  }
  /////////////////////////////////////////////////////////////
  else if(S1==1 && S2==1 && S3==0 && S4==0 && S5==0 && S6==0 && S7==0)
  {
    //bot(-100,180);	//CCW  CW//hard left
    bot(-50,180);
  } 
  else if(S1==0 && S2==0 && S3==0 && S4==0 && S5==0 && S6==1 && S7==1)
  {
   // bot(180,-100);	 //CW  CCW//hard right
    bot(180,-50);
  }
  /////////////////////////////////////////////////////////////
   else if(S1==1 && S2==0 && S3==0 && S4==0 && S5==0 && S6==0 && S7==0)
  {
    bot(-80,180);	//CCW  CW//hard left
  } 
  else if(S1==0 && S2==0 && S3==0 && S4==0 && S5==0 && S6==0 && S7==1)
  {
    bot(180,-80);	 //CW  CCW//hard right
  }
}


void bot(int left, int right)// left motor value// right motor value
{
  if(left==0)
  {
    left_motor(0,left);
  }
  else if(left>0)
  {
    left_motor(1,left);
  }
  else
  {
    left_motor(2,-left);
  }
  /////////////////////////////////////
  if(right==0)
  {
    right_motor(0,0);
  }
  else if(right>0)
  {
    right_motor(1,right);
  }
  else
  {
    right_motor(2,-right);
  }
  
}
//////////////////////////////////////////////////////////////////
void left_motor(int dir, int spd)// sub function for left motor operation
{
  if(dir==1)// for forward
  {
    digitalWrite(n1,HIGH);
    digitalWrite(n2,LOW);
  }
  else if(dir==2)// for reverse
  {
    digitalWrite(n2,HIGH);
    digitalWrite(n1,LOW);
  }
  else// FOR STOP
  {
    digitalWrite(n2,LOW);
    digitalWrite(n1,LOW);
  }
  analogWrite(e1,spd);
}

void right_motor(int dir, int spd)// function for right motor operation
{
  if(dir==1)//for forward
  {
    digitalWrite(n3,HIGH);
    digitalWrite(n4,LOW);
  }
  else if(dir==2)// for reverse
  {
    digitalWrite(n4,HIGH);
    digitalWrite(n3,LOW);
  }
  else
  {
    digitalWrite(n3,LOW);
    digitalWrite(n4,LOW);
  }
  analogWrite(e2,spd);
}


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void left_move()
{
  bot(-200,-200);
  delay(40);
  bot(0,0);
  delay(10);
/// BUZ_HI;
 bot(-160,160);  //CCW  CW//hard hard left//turn start
 delay(50);//upto 45 degree
/// BUZ_LOW; 
 S4=0;
 while(S4!=1)
 {
///   YELLOW_HI;
   bot(-140,140);
   read_sensor();
 }
 bot(140,-140);
 delay(70);
/// YELLOW_LOW;
 //read_sensor();
 normal_line();
}
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
void right_move()
{
  bot(-200,-200);
  delay(40);
  bot(0,0);
  delay(10);
/// BUZ_HI;
 bot(160,-160);  //CW   CCW//hard hard right//turn start
 delay(50);
/// BUZ_LOW; 
 S4=0;
 while(S4!=1)
 {
   BLUE_HI;
   bot(140,-140);  // CW    CCW//hard hard right
   read_sensor();
 }
 bot(-140,140);
 delay(60);
// BLUE_LOW;
// read_sensor();
normal_line();
}

void slow_left_move()
{
  bot(-200,-200);
  delay(40);
  bot(0,0);
  delay(10);
/// BUZ_HI;
 bot(-120,120);  //CCW  CW//hard hard left//turn start
 delay(50);//upto 45 degree
/// BUZ_LOW; 
 S4=0;
 while(S4!=1)
 {
///   YELLOW_HI;
   bot(-100,100);
   read_sensor();
 }
 bot(100,-100);
 delay(50);
/// YELLOW_LOW;
 //read_sensor();
 normal_line();
}
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
void slow_right_move()
{
  bot(-200,-200);
  delay(40);
  bot(0,0);
  delay(10);
/// BUZ_HI;
 bot(120,-120);  //CW   CCW//hard hard right//turn start
 delay(50);
/// BUZ_LOW; 
 S4=0;
 while(S4!=1)
 {
   BLUE_HI;
   bot(100,-100);  // CW    CCW//hard hard right
   read_sensor();
 }
 bot(-100,100);
 delay(50);
// BLUE_LOW;
// read_sensor();
normal_line();
}
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////

void read_sensor()
{
  if(line_color==WHITE)
  {
      if(A==HIGH)
      S1=0;
      else
      S1=1;
      if(B==HIGH)
      S2=0;
      else
      S2=1;
      if(C==HIGH)
      S3=0;
      else
      S3=1;
      if(D==HIGH)
      S4=0;
      else
      S4=1;
      if(E==HIGH)
      S5=0;
      else
      S5=1;
      if(F==HIGH)
      S6=0;
      else
      S6=1;
      if(G==HIGH)
      S7=0;
      else
      S7=1; 
  }
  else
  {
    if(A==LOW)
      S1=0;
      else
      S1=1;
      if(B==LOW)
      S2=0;
      else
      S2=1;
      if(C==LOW)
      S3=0;
      else
      S3=1;
      if(D==LOW)
      S4=0;
      else
      S4=1;
      if(E==LOW)
      S5=0;
      else
      S5=1;
      if(F==LOW)
      S6=0;
      else
      S6=1;
      if(G==LOW)
      S7=0;
      else
      S7=1; 
  }
}



////////////////////////////////////////////////
///function for left sonar
///////////////////////////////



