// Really Difficult Game by Trevor Taka

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

struct Point //Declar structure
{
  int x;
  int y;
};
Point p1 = {7,random(3) + 1}; //starting coordinates of platform
Point p2 = {10,random(3) + 1}; //starting coordinates of platform 2
Point p3 = {13,random(3) + 1}; //starting coodinates of platform 3
Point platforms[3] = {p1,p2,p3}; //array of platforms
Point jumper = {2,8}; //starting coordinates of jumper
int speed = 500; //speed of platforms
int gameOver = 0; //0 = game not started, 1 = game in progress, 2 = game over
int seed;

void setup() //run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
  randomSeed(millis); //starts random at random point
  Serial.begin(9600);
}

void loop()                     // run over and over again
{
  if (gameOver == 0) //if game not started
  {
    start();
  }
  if (gameOver == 1) //when game is still going on
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
  if (gameOver == 2); //if game over do "death"
  {
    death();
  }
}

void drawLava() //Draws bottom level that kills you
{
  for (int b = 0; b < 8; b++)
  DrawPx(b,0,Red); // Draws entire bottom row red for lava
}

void drawPlatform() //draws the original platforms
{
  for (int i = 0; i < 3; i++)
  {
    if (platforms[i].x < 8) //if left side of platform's x coord is less than 8
    {
      DrawPx(platforms[i].x,platforms[i].y,Blue); //Draw left side of platforms
    }
    if (platforms[i].x + 1 < 8) //if right side of platform's x coord is less than 8
    {
      DrawPx(platforms[i].x + 1,platforms[i].y,Blue); //Draw right side of platforms
    }
  }
}
void updatePlatform() //scrolls platforms from right to left
{
  for (int i = 0; i < 3; i++)
  {
    if (platforms[i].x > 0) //if platform's x coord is greater than 0
    {
      platforms[i].x--; //subtract one from platform x (move left 1)
    }
    else //if platform x is 0
    {
      platforms[i].x = 8; //reset x back to 8
      platforms[i].y = random(3) + 1; //reset to random height between 1 and 3
    }
  }
}

void drawJumper() //draws jumper
{
  if (jumper.y < 8) //if on the screen (<8)
  {
    DrawPx(jumper.x,jumper.y,Orange);
  }
}

void updateJumper() //jumper jumps
{
  CheckButtonsPress();
    if (Button_A) //when Button A is pressed
    {
      if (ReadPx(jumper.x,jumper.y - 1) == 5) //when jumper is on top of platform
      {
        Tone_Start(8000,300); //plays jumping tone
        jumper.y = jumper.y + 3; //jumps up 3
      }
    }
    if (ReadPx(jumper.x,jumper.y - 1) == 0)
  {
    jumper.y--; //subtract one from jumper y (move down 1)
  }
}

void checkDeath() //checks to see if in lava
{
  if ((ReadPx(jumper.x,jumper.y - 1) == 1) || (ReadPx(jumper.x,jumper.y) == 5)) //if under jumper is lava or hit by platform from side
  {
    ClearSlate();
    gameOver = 2; //set gameOver boolean to true
  }
}

void death() //if dead
{
  Tone_Start(8000,300);
  delay(500);
  Tone_Start(9000,300);
  delay(500);
  Tone_Start(10000,300);
  delay(500);
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

void start() //at start
{
DrawPx(0,2,Violet);
DrawPx(0,3,Violet);
DrawPx(0,4,Violet);
DrawPx(1,2,Violet);
DrawPx(2,2,Violet);
DrawPx(1,4,Violet);
DrawPx(2,4,Violet);
DrawPx(2,3,Violet);
DrawPx(0,2,Violet);
DrawPx(2,5,Violet);
DrawPx(2,6,Violet);
DrawPx(4,2,Violet);
DrawPx(4,3,Violet);
DrawPx(4,4,Violet);
DrawPx(4,6,Violet);
DrawPx(5,4,Violet);
DrawPx(6,4,Violet);
DrawPx(7,4,Violet);
DrawPx(6,3,Violet);
DrawPx(6,2,Violet);
DrawPx(6,4,Violet);
DrawPx(6,5,Violet);
DrawPx(6,6,Violet);
DrawPx(7,6,Violet);
DisplaySlate();
CheckButtonsPress();
if (Button_B)
{
  seed = millis();
  gameOver = 1;
  ClearSlate();
}
}
