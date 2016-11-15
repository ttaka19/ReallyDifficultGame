// Really Difficult Game by Trevor Taka

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

struct Point
{
  int x;
  int y;
};
Point platforml1 = {6,random(3)};
Point platformr1 = {7,platforml1.y};
Point platforml2 = {6,random(3)};
Point platformr2 = {7,platforml2.y};
Point platforml3 = {6,random(3)};
Point platformr3 = {7,platforml3.y};
Point jumper = {0,0};
int speed = 100;
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
  updatePlatform();
}

void drawPlatform()
{
  DrawPx(platforml1.x,platforml1.y,Blue);
  DrawPx(platformr1.x,platformr1.y,Blue);
  delay(platformspeed);
  DrawPx(platforml2.x,platforml2.y,Blue);
  DrawPx(platformr2.x,platformr2.y,Blue);
  delay(platformspeed);
  DrawPx(platforml3.x,platforml3.y,Blue);
  DrawPx(platformr3.x,platformr3.y,Blue);
  delay(platformspeed);
}

void updatePlatform() //scrolls platforms from right to left
{
  if (platforml1.x > 0)
  {
    platforml1.x--;
    platformr1.x--;
  }
  else
  {
    platforml1.x = 6;
    platformr1.x = 7;
    platforml1.y = random(3);
    platformr1.y = platforml1.y;
  }
  DisplaySlate();
  if (platforml2.x > 0)
  {
    platforml2.x--;
    platformr2.x--;
  }
  else
  {
    platforml2.x = 6;
    platformr2.x = 7;
    platforml2.y = random(3);
    platformr2.y = platforml2.y;
  }
  DisplaySlate();
if (platforml3.x > 0)
  {
    platforml3.x--;
    platformr3.x--;
  }
  else
  {
    platforml3.x = 6;
    platformr3.x = 7;
    platforml3.y = random(3);
    platformr3.y = platforml3.y;
  }
  DisplaySlate();
}

