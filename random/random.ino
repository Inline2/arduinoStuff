#include<Servo.h>

Servo serX;
Servo serY;
int xData;
int yData;
//int xDir;
//int yDir;
int dir;
int amount = 10;

void setup() {
  serX.attach(10);
  serY.attach(11);
  Serial.begin(9600);
  Serial.setTimeout(10);
  serX.write(90);
  serY.write(90);
}

void loop() {
  //Y100-130 X30-110
  dir = random(4);
  amount = 10;
  delay(200);
  switch(dir)
  {
    case 0:
      amount = 10;
      xPosDir();
      break;
    case 1:
      amount = 10;
      xNegDir();
      break;
    case 2:
      amount = 5;
      yPosDir();
      break;
    case 3:
      amount = 5;
      yNegDir();
      break;
  }
  while(yData > 130 || yData < 100 || xData > 110 || xData < 30)
  {
    if(yData > 130)
    {
      amount = 10;
      yNegDir();
    }
    else if(yData < 100)
    {
      amount = 10;
      yPosDir();
    }
    else if(xData > 110)
    {
      amount = 20;
      xNegDir();
    }
    else
    {
      amount = 20;
      xPosDir();
    }
  }
  
}
void xPosDir()
{
  amount = xData + amount;
  for(xData = xData; xData <= amount; xData++)
  {
    serX.write(xData);
    delay(15);
  }
}
void xNegDir()
{
  amount = xData - amount;
  for(xData = xData; xData >= amount; xData--)
  {
    serX.write(xData);
    delay(15);
  }
}
void yPosDir()
{
  amount = yData + amount;
  for(yData = yData; yData <= amount; yData++)
  {
    serY.write(yData);
    delay(15);
  }
}
void yNegDir()
{
  amount = yData - amount;
  for(yData = yData; yData >= amount; yData--)
  {
    serY.write(yData);
    delay(15);
  }
}
