// Really Difficult Game by Trevor Taka

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.
int ph = 1; //platform height
int platform_left = 6; //left side of platform
int platform_right = 7; //right side of platform

void setup() 
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
  drawPlatform();
  drawPlatfor();
  delay(300);
  updatePlatform();
  DisplaySlate();
  delay(100);
  ClearSlate();

}

void drawPlatform()
{
  DrawPx(platform_left,ph,Blue);
  DrawPx(platform_right,ph,Blue);
}

void drawPlatfor()
{
  DrawPx(platform_left,ph + 1,Blue);
  DrawPx(platform_right,ph + 1,Blue);
}

void drawPlatfo()
{
  DrawPx(platform_left,ph + 2,Blue);
  DrawPx(platform_right,ph + 2,Blue);
}

void drawPlatf()
{
  DrawPx(platform_left,ph + 3,Blue);
  DrawPx(platform_right,ph + 3,Blue);
}

void drawPlat()
{
  DrawPx(platform_left,ph + 4,Blue);
  DrawPx(platform_right,ph + 4,Blue);
}

void updatePlatform()
{
  platform_left = platform_left - 1;
  platform_right = platform_right - 1;
}

