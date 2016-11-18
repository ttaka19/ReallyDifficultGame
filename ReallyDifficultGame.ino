// Really Difficult Game by Trevor Taka

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

struct Point
{
  int x;
  int y;
};
Point p1 = {7,random(3)};
Point p2 = {10,random(3)};
Point p3 = {13,random(3)};
Point platforms[3] = {p1,p2,p3};
Point jumper = {0,0};
int speed = 300;
int platformspeed = 500;

void setup() 
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
  randomSeed(millis);
  Serial.begin(9600);
}

void loop()                     // run over and over again
{
  Serial.print("function called");
  drawPlatform();
  DisplaySlate();
  delay(speed);
  ClearSlate();
  updatePlatform();
  DisplaySlate();
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
      platforms[i].x = 8;
      platforms[i].y = random(3);
    }
  }
}

void drawJumper() //draws jumper
{
  DrawPx(jumper.x,jumper.y,Red);
}

void updateJumper() //jumper jumps
{
  CheckButtonsPress();
    if (Button_A)
    {
      jumper.y = jumper.y + 1;
      delay(50);
      DrawPx(jumper.x,jumper.y - 1,0);
      DisplaySlate();
      jumper.y = jumper.y + 1;
      delay(50);
      DrawPx(jumper.x,jumper.y - 1,0);
      DisplaySlate();
      jumper.y = jumper.y + 1;
      delay(50);
      DrawPx(jumper.x,jumper.y - 1,0);
      DisplaySlate();
      jumper.y = jumper.y - 1;
      delay(50);
      DrawPx(jumper.x,jumper.y - 1,0);
      DisplaySlate();
    }
}

