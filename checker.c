#include <stdio.h>
#include <assert.h>

int temperatureIsOk(float temperature)
{
  if(temperature < 0 || temperature > 45) 
  {
    printf("Temperature out of range!\n");
    return 0;
  }
  else
  {return 1;}
}

int socIsOk(float soc)
{
  if(soc < 20 || soc > 80)
   {
    printf("State of Charge out of range!\n");
    return 0;
  }
  else
  {return 1;}
}

int chargeRateIsOk(float chargeRate)
{
  if(chargeRate > 0.8)
   {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  else
  {return 1;}
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
  int temp_1 = 0;
  int temp_2 = 0;
  int temp_3 = 0;

  temp_1 = temperatureIsOk(temperature);
  temp_2 = socIsOk(soc);
  temp_3 = chargeRateIsOk(chargeRate); 
  return (temp_1+temp_2+temp_3);

}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
