#define FS A2      // front sensor(distance)
#define LS A0      // left sensor(distance)
#define RS A1      // right sensor(distance)
#define LC A3       // right sensor(color)
#define RC A5      // front sensor(color)
#define LM 7       // left motor
#define RM 8      // right motor
#define LB 5
#define RB 6
int l=0;
int r=0;
void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(FS, INPUT);
  pinMode(LC, INPUT);
  pinMode(RC, INPUT);
  pinMode(LM, OUTPUT);
  pinMode(RM, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RB, OUTPUT);
  Serial.begin(9600); 
}
void loop()
{
   digitalWrite(LM, l);
   digitalWrite(RM, r);
   Serial.println(analogRead(LC));
   
   if(!(analogRead(LC) > 500) && (analogRead(RC) > 275)) // If left black, turn only right motor on
    {
      l=0;
      r=1;

    }
  
  if((analogRead(LC) > 500) && !(analogRead(RC) > 275)) // If right black, turn only left motor on
    {
      l=1;
      r=0;
    
    }
  
  if(!(analogRead(LC) > 500) && !(analogRead(RC) > 450)) // If both black, stop
    {
      l=1;
      r=1;
    }

   if(analogRead(RS) > 600)
    {
      l=0;
      r=1;
    }
    
    if(analogRead(FS) > 600)
    {
      l=1;
      r=1;
    }
    if(analogRead(LS) > 625) //if left distance sensor < 6in, turn right motor on
    {
      l=1;
      r=0;
    }
    if((analogRead(LC) > 400) && (analogRead(LC) < 460)) // If both black, stop
    {
      l=1;
      r=1;
    }

   // if(!(analogRead(FS) > 600))
    //{
      //l=0;
      //r=0;
    //}
}

