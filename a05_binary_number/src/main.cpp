#include <Arduino.h>

int pins[4] = {9, 10, 11, 12};

void toggleLeds(int nums[4])
{
  for (int i = 0; i < 4; i++)
  {
    if (nums[i] == 1)
    {
      digitalWrite(pins[i], HIGH);
    }
    else
    {
      digitalWrite(pins[i], LOW);
    }
  }
}

void showNumber(int n)
{
  int i = 0, nums[4] = {0, 0, 0, 0};
  while (n > 0)
  {
    nums[i] = n % 2;
    i++;
    n /= 2;
  }
  toggleLeds(nums);
}

void setup()
{
  for (int x : pins)
  {
    pinMode(x, OUTPUT);
  }
}

void loop()
{
  for (int i = 0; i < 16; i++)
  {
    showNumber(i);
    delay(1000);
  }
}
