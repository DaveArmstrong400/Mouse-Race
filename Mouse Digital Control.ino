#include <PID_v1.h>

  int inputleft=14;
  int inputright=15;
  int right = 5;   
  int left = 6;
  double leftspeed = 0;
  double rightspeed = 0;
  double Setpointr, Inputr, Outputr;
  double Setpointl, Inputl, Outputl; 
  double Kpr=22.5, Kir=0, Kdr=6;
  double Kpl=22.5, Kil=0, Kdl=6;
  PID PIDright(&Inputr, &Outputr, &Setpointr, Kpr, Kir, Kdr, REVERSE);
  PID PIDleft(&Inputl, &Outputl, &Setpointl, Kpl, Kil, Kdl, REVERSE);

void setup() 
{
  Inputr = analogRead(inputright);
  Inputl = analogRead(inputleft);
  Setpointr = 75;
  Setpointl = 80;
  PIDright.SetMode(AUTOMATIC);
  PIDleft.SetMode(AUTOMATIC);
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);  
}

void loop() 
{
  
  Inputr = analogRead(inputright);
  Inputl = analogRead(inputleft);
  PIDright.Compute();
  PIDleft.Compute();

  if ((Inputr>550 && Inputl<40) || (Inputl>500 && Inputr<40))
  {    
     PIDright.SetOutputLimits(0, 125);
     PIDleft.SetOutputLimits(0, 125);
     double Kpr=23.5; Kir=0; Kdr=7;
     double Kpl=23.5; Kil=0; Kdl=7;
     PIDright.SetSampleTime(15);
     PIDleft.SetSampleTime(15);
  }
    else
  { 
     PIDright.SetOutputLimits(0, 170);
     PIDleft.SetOutputLimits(0, 170);
     double Kpr=22.5; Kir=0; Kdr=6;
     double Kpl=22.5; Kil=0; Kdl=6;
     PIDright.SetSampleTime(10);
     PIDleft.SetSampleTime(10);
  }

  analogWrite(left,Outputl);
  analogWrite(right, Outputr);
}
