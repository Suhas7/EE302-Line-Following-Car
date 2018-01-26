#define FS A2      // front sensor(distance)
#define LS A0      // left sensor(distance)
#define RS A1      // right sensor(distance)
#define LC A3       // right sensor(color)
#define RC A5      // front sensor(color)
#define LM 7       // left motor
#define RM 8      // right motor
#define LB 5
#define RB 6
int n = 0;
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
}
void loop()
{
   digitalWrite(LM, LOW);
   digitalWrite(RM, LOW);
   Serial.println(analogRead(RC));
  
  if(!(analogRead(LC) > 300) && (analogRead(RC) > 275)) // If left black, turn only right motor on
    {
      digitalWrite(LM, LOW);
      digitalWrite(RM, HIGH);

      delay(1000);
    }
  
  if((analogRead(LC) > 300) && !(analogRead(RC) > 275)) // If right black, turn only left motor on
    {
      digitalWrite(LM, HIGH);
      digitalWrite(RM, LOW);
      delay(1000);
    }
  
  if(!(analogRead(LC) > 300) && !(analogRead(RC) > 275)) // If both black, stop
    {
      digitalWrite(LM, HIGH);
      digitalWrite(RM, HIGH);
      delay(1000);
    }

   if(analogRead(LS) > 625) //if left distance sensor < 6in, turn right motor on
    {
      digitalWrite(LM, HIGH);
      digitalWrite(RM, LOW);
    }
    
   if(analogRead(RS) > 600)
    {
      digitalWrite(LM, LOW);
      digitalWrite(RM, HIGH);
    }
    
    if(analogRead(FS) > 600)
    {
      digitalWrite(LM, HIGH);
      digitalWrite(RM, HIGH);
    }

}
