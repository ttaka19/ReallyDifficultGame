// Really Difficult Game by Trevor Taka

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.
int random_platform = 0;
int speed = 200;
struct Platform
{
  int x;
  int y;
}
Point platform_left_one = {6,0}
Point platform_right_one = {7,0}
Point platform_left_two = {6,1}
Point platform_right_two = {7,1}
Point platform_left_three = {6,2}
Point platform_right_three = {7,2}
void setup() 
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
  drawPlatform();
  delay(speed);
  updatePlatform();
  DisplaySlate();
  delay(100);
  ClearSlate();

}

void drawPlatform()
{
  DrawPx(platform_left,ph,Blue);
  DrawPx(platform_right,ph,Blue);
  delay(speed * 2);
  random_platform = random(3);
  if (random_platform == 0)
  {
    platform_left = 6;
    platform_right = 7;
    DrawPx(platform_left,ph - 1,Blue);
    DrawPx(platform_right,ph - 1,Blue);
  }
  if (random_platform == 1)
  {
    platform_left_two = 6;
    platform_right_two = 7;
    DrawPx(platform_left_two,ph,Blue);
    DrawPx(platform_right_two,ph,Blue);
  }
  if (random_platform == 2)
  {
    DrawPx(platform_left_three,ph + 1,Blue);
    DrawPx(platform_right_three,ph + 1,Blue);
  }
}

void updatePlatform() //scrolls platforms from right to left
{
}

