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
  //Serial.begin(9600);
  //Serial.setTimeout(10); //I think these are actually useless and I just forgot to take them out so if it doesn't work try uncommenting these
  serX.write(90); //Makes the servos move to a straight forward position
  serY.write(90);
}

void loop() {
  //Y100-130 X30-110
  //The default range I have it set up for
  dir = random(4);
  delay(200);
  switch(dir) //changing the value of amount will change how much the servos move
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
  while(yData > 130 || yData < 100 || xData > 110 || xData < 30) //change these and the if elses below to modify the bounds of the servos
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
void xPosDir() //all of these functions just make the servo move more smoothly with less speed.
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
