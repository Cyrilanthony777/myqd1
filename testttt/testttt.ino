
int setpoint=70,Kp=3;

void setup()
{
  Serial1.begin(57600);
}
void loop()
{
  int s1,s2,s3,s4,so1=0,so2=0,so3=0,so4=0,op1,op2,op3,op4;
  int e1,e2,e3,e4,pp1,pp2,pp3,pp4,opx,opy;
  s1=0;
  s2=0;
  s3=0;
  s4=0;
  int Vanalog,voltage,alt;
  float sop1,sop2,sop3,sop4,alo,volt;
  alt=pulseIn(4,HIGH,30000);
  alo=(alt/149)*2.54;
  alt=alo;
  
  for(int i=0;i<=50;i++)
  {
    analogRead(A0);
    delay(2);
    s1 = analogRead(A0);
    
    so1=so1+s1;
  } 
  so1=so1/50;
  sop1=(so1*2.54)/2;
  op1=sop1;
  
  for(int i=0;i<=50;i++)
  {
    analogRead(A1);
    delay(2);
    s2 = analogRead(A1);
    so2=so2+s2;
  } 
  so2=so2/50;
  sop2=(so2*2.54)/2;
  op2=sop2;
  
  for(int i=0;i<=50;i++)
  {
    analogRead(A2);
    delay(2);
    s3 = analogRead(A2);
    so3=so3+s3;
  } 
  so3=so3/50;
  sop3=(so3*2.54)/2;
  op3=sop3;
  
  
  for(int i=0;i<=50;i++)
  {
    analogRead(A3);
    delay(2);
    s4 = analogRead(A3);
    so4=so4+s4;
  } 
  so4=so4/50;
  sop4=(so4*2.54)/2;
  op4=sop4;
  
  Vanalog=analogRead(A6);
  delay(2);
  volt=map(Vanalog,0,1023,0,16);
  
  e1=op1-setpoint;
  e2=op2-setpoint;
  e3=op3-setpoint;
  e4=op4-setpoint;
  
  pp1=e1*Kp;
  pp2=e2*Kp;
  pp3=e3*Kp;
  pp4=e4*Kp;
  
  opx=1500-pp1+pp2;
  opy=1500-pp3+pp4;
  
  
  
  
 
  Serial1.println("A");
  Serial1.println(op1);
  Serial1.println(op2);
  Serial1.println(op3);
  Serial1.println(op4);
  Serial1.println(opy);
  Serial1.println(opx);
  Serial1.println(alt);
  Serial1.println(volt);
  
}
