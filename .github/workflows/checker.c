#include <stdio.h>
#include <assert.h>

void logStatus(int isOk, const char* parameterName) 
{
  if (!isOk)
  {
      printf("%s out of range!\n", parameterName);
  }
}

int isValueOutOfRange(float value, float Lower_boundary, float Upper_boundary)
{
    return (value < Lower_boundary || value > Upper_boundary);
}

int isValueGreaterThan(float value, float threshold)
{
    return (value > threshold);
}

int IstemperatureOk(float temperature)
{
  int tempOk = !isValueOutOfRange(temperature, 0, 45);
  logStatus(tempOk, "Temperature");
  return tempOk;
}

int IsSocOk(float soc)
{
  int socOk = !isValueOutOfRange(soc, 20, 80);
  logStatus(socOk, "State of Charge");
  return socOk;
}

int IschargeRateOk(float chargeRate)
{
  int chargeRateOk = !isValueGreaterThan(chargeRate, 0.8);
  logStatus(chargeRateOk, "Charge Rate");
  return chargeRateOk;
}

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
    return temperatureIsOk(temperature) && socIsOk(soc) && chargeRateIsOk(chargeRate);
}

int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
