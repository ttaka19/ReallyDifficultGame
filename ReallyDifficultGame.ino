// Really Difficult Game by Trevor Taka

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

struct Point
{
  int x;
  int y;
};
Point p1 = {7,random(3) + 1};
Point p2 = {11,random(3) + 1};
Point p3 = {14,random(3) + 1};
Point platforms[3] = {p1,p2,p3};
Point jumper = {2,7};
int speed = 500;
boolean gameOver = false; //game not over

void setup() 
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
  randomSeed(millis);
  Serial.begin(9600);
}

void loop()                     // run over and over again
{
  if (gameOver == false)
  {
    Serial.print("function called");
    drawJumper();
    drawPlatform();
    drawLava();
    updateJumper();
    checkDeath();
    DisplaySlate();
    delay(speed);
    ClearSlate();
    updatePlatform();
    DisplaySlate();
  }
  else death(); //if game over do "death"
}

void drawLava() //Draws bottom level that kills you
{
  for (int b = 0; b < 8; b++)
  DrawPx(b,0,Red);
}

void drawPlatform() //draws the original platforms
{
  for (int i = 0; i < 3; i++)
  {
    if (platforms[i].x < 8)
    {
      DrawPx(platforms[i].x,platforms[i].y,Blue);
    }
    if (platforms[i].x + 1 < 8)
    {
      DrawPx(platforms[i].x + 1,platforms[i].y,Blue);
    }
  }
}
void updatePlatform() //scrolls platforms from right to left
{
  for (int i = 0; i < 3; i++)
  {
    if (platforms[i].x > 0)
    {
      platforms[i].x--;
    }
    else
    {
      platforms[i].x = 9;
      platforms[i].y = random(3) + 1;
    }
  }
  if (ReadPx(jumper.x,jumper.y - 1) == 0)
  {
    jumper.y--;
  }
}

void drawJumper() //draws jumper
{
  if (jumper.y < 8)
  {
    DrawPx(jumper.x,jumper.y,Orange);
  }
}

void updateJumper() //jumper jumps
{
  CheckButtonsPress();
    if (Button_A)
    {
      jumper.y = jumper.y + 2;
      delay(300);
      jumper.y = jumper.y + 2;
      delay(300);
    }
}

void checkDeath () //checks to see if in lava
{
  if (ReadPx(jumper.x,jumper.y) == 1)
  {
    ClearSlate();
    gameOver = true;
  }
}

void death() //if dead
{
  DrawPx(0,0,Red); //draw red x
  DrawPx(1,1,Red);
  DrawPx(2,2,Red);
  DrawPx(3,3,Red);
  DrawPx(4,4,Red);
  DrawPx(5,5,Red);
  DrawPx(6,6,Red);
  DrawPx(7,7,Red);
  DrawPx(0,7,Red);
  DrawPx(1,6,Red);
  DrawPx(2,5,Red);
  DrawPx(3,4,Red);
  DrawPx(4,3,Red);
  DrawPx(5,2,Red);
  DrawPx(6,1,Red);
  DrawPx(7,0,Red);
  DisplaySlate();
}


