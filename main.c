#include <stdio.h>
// begin of hell

//should be delete after finished
void printOptions()
{
  printf("1. Spinning Thingy\n");
  printf("2. Water\n");
  printf("3. Elevator\n");
  printf("4. Electric Car\n");
  printf("5. TBD\n");
  printf("6. Exit\n");
}
/*
Calculate Rotating Thingy
*/
/*hashtag: begin of pain*/
double spinningThingy(double n2) //im sorry, you not nut, my bad
{
  double output = 1;
  if (n2 < 0)
  {
    output = -1;
  } else {
    output = n2 * 36;
  }
  return output;
}
/*
Calculate Water Bills (Not accurate)
TODO: This needs fixing, but this is not my project. The owner/submitter must be resposinble
for any problems that this shit code might make
PLEASE FIX THE BUGS BEFORE SUBMIT
*/
int WaterBills(int sv, int x, int y)
//sv: human online
//x: new number
//y: old number
{
  int Total = 0, WaterUsed = 0;
  if (x < y || sv < 0){
    Total = -1;
  }
  else {
    WaterUsed = x - y;
    if (WaterUsed <= 4 * sv){
      Total = WaterUsed * 6700;
    }
    else if (WaterUsed <= 6*sv){
      Total = 6700 * 4 * sv + (WaterUsed - 4*sv)*12900;
    }
    else Total =6700 * 4 * sv + 12900 * 2 * sv + (WaterUsed - (2+4)*sv)*14400;
  }
  Total = Total * 1.27;
  return Total;
}
/*
TODO: add more comment to make this code easier to read and maintain
(which probably never be...)
*/
//Indeed

int Elevator(int FromFloor, int ToFloor, int Weight)
{
  int ElecNeed;
  if (Weight > 0) {
    int Travel = FromFloor - ToFloor;
    if (Weight <= 1000)
    {
      if (Travel > 0)
      {
        // Go Down
        ElecNeed = (Travel)*Weight * 5;
      }
      else
      {
        // Go Up
        ElecNeed = (Travel) / (-1) * Weight * 7;
      }
    }
    if (Weight > 1000 && Weight <= 1600)
    {
      Weight = Weight - 1000;
      if (Travel > 0)
      {
        // Go Down
        ElecNeed = (Weight * Travel * 7) + (1000 * Travel * 5); //full the new one first, then the old one
      }
      else
      {
        // Go up
        Travel = Travel / -1;
        ElecNeed = (Weight * Travel * 12) + (1000 * Travel * 7); //full the new one first, then the old one
      }
    }
    else
    {
      if (Weight > 1600 && Weight <= 2600)
      {
        Weight = Weight - 1600;
        if (Travel > 0)
        {
          // Go Down
          ElecNeed = (Weight * 5 * Travel) + (1000 * 5 * Travel) + (600 * 7 * Travel);
        }
        if (Travel < 0)
        {
          // Go up
          Travel = Travel / -1;
          ElecNeed = (Weight * Travel * 7) + (1000 * 7 * Travel) + (600 * 12 * Travel);
        }
      }
    }
  }
  if (Weight < 0)
  {
    ElecNeed = -1;
  }
    return ElecNeed;
}

/*
This is the fucking worst code i've have ever written till this point
It will probably fuck everything
But im to tired to fix it
TODO: Fix when i have energy to fix this shit
(or someone else will do this)
*/

double ElectricCar1(int Percen, int k)
{
  int roadType = k;
  int distanceAbleToTravel;
  if (Percen > 50)
  {
    switch (roadType)
    {
    case 1:
      // highway
      distanceAbleToTravel = (Percen / 3) * 5;
      break;

    case 2:
      Percen = Percen - 50;
      distanceAbleToTravel = (Percen / 3.6) * 5 + (30 / 4.9) * 5 + (20 / 7) * 5;
      break;
    case 3:
      Percen = Percen - 50;
      distanceAbleToTravel = (Percen / 8) * 5 + (30 / 10.5) * 5;
      break;
      // leverage surface
    case 4:
      // mix
      Percen = Percen - 50;
      distanceAbleToTravel = (Percen / 4.4) * 5 + (30 / 5.3) * 5;
    }
  }
  if (Percen < 50 && Percen > 20)
  {
    switch (roadType)
    {
    case 1:
      distanceAbleToTravel = (Percen / 3) * 5;
    case 2:
      Percen = Percen - 20;
      distanceAbleToTravel = (Percen / 4.9) * 5 + (20 / 7) * 5;
    case 3:
      Percen = Percen - 20;
      distanceAbleToTravel = (Percen / 10.5) * 5;
    case 4:
      Percen = Percen - 20;
      distanceAbleToTravel = (Percen / 5.3) * 5;
    }
  }
  else
  {
    distanceAbleToTravel = 0;
  }
  return distanceAbleToTravel;
}

double ElectricCar2()
{
  int Battery = 100;
  int n;
  double distanceTraveled = 0;
  while (Battery != 0)
  {
    scanf("%d", &n);
    if (n > 0)
    {
      Battery = Battery - (n / 2.15);
      distanceTraveled = distanceTraveled + n / 2.15;
    }
    if (n < 0)
    {
      Battery = Battery + (n / 10);
      distanceTraveled = distanceTraveled + n * (-1);
    }
    if (n == 0)
    {
      Battery = Battery + 25;
    }
    if (Battery > 100)
    {
      Battery = 100;
    }
    if (Battery == 0)
    {
      break;
    }
  }
  printf("%.1lf", distanceTraveled);
  return 0;
}

/*
main program loop
TODO: fix the input to be on 1 line
*/
int main()
{
  int exit = 0;
  int n, x, y, z;
  double n1,n2;
  int options;
  while (exit != 1)
  {
    printOptions();
    scanf("%d", &options);
    switch (options)
    {
    case 1:
      scanf("%lf", &n2); //you son of the... 
      printf("%d\n", (int)spinningThingy(n2));
      exit = 1;
      break;
    case 2:
      scanf("%d %d %d", &n, &x, &y);
      printf("%d\n", WaterBills(n, x, y));
      exit = 1;
      break;
    case 3:
      scanf("%d %d %d", &n, &x, &y);
      printf("%d\n", Elevator(n, x, y));
      exit = 1;
      break;
    case 4:
      scanf("%d %d", &n, &x);
      printf("%.2lf", ElectricCar1(n, x));
      exit = 1;
      break;
    case 5:
      ElectricCar2();
      exit = 1;
      break;
    case 6:
      exit = 1;
      printf("exiting...... \nthanks!");
      break;
    }
  }

  return 0;
}