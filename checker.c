#include <stdio.h>
#include <assert.h>

typedef struct
{
    float lowerLimit;
    float upperLimit;
    float lowerWarning;
    float upperWarning;
} ParameterLimits;

typedef struct
{
    float upperLimit;
    float upperWarning;
} ChargeRateLimits;

ParameterLimits temperatureLimits = {0, 45, (0 + 0.05 * 45), (45 - 0.05 * 45)};
ParameterLimits socLimits = {20, 80, (20 + 0.05 * 80), (80 - 0.05 * 80)};
ChargeRateLimits chargeRateLimits = {0.8, (0.8 - 0.05 * 0.8)};

void logStatus(int isOk, const char* parameterName) 
{
  if (!isOk)
  {
      printf("%s out of range!\n", parameterName);
  }
}

void logWarning(int isWarning, const char* parameterName)
{
    if (isWarning)
    {
        printf("Warning: %s approaching limit!\n", parameterName);
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

int isTemperatureWarning(float temperature)
{
    int tempLowWarning = temperature >= temperatureLimits.lowerLimit && temperature <= temperatureLimits.lowerWarning;
    int tempHighWarning = temperature >= temperatureLimits.upperWarning && temperature <= temperatureLimits.upperLimit;
    int tempWarning = tempLowWarning || tempHighWarning;
    logWarning(tempWarning, "Temperature");
    return tempWarning;
}

int IstemperatureOk(float temperature)
{
  if (isTemperatureWarning(temperature))
  {
    return 1;
  }
  int tempOk = !isValueOutOfRange(temperature, 0, 45);
  logStatus(tempOk, "Temperature");
  return tempOk;
}

int isSocWarning(float soc)
{
    int socLowWarning = soc >= socLimits.lowerLimit && soc <= socLimits.lowerWarning;
    int socHighWarning = soc >= socLimits.upperWarning && soc <= socLimits.upperLimit;
    int socWarning = socLowWarning || socHighWarning;
    logWarning(socWarning, "State of Charge");
    return socWarning;
}

int IsSocOk(float soc)
{
   if (isSocWarning(soc))
   {
    return 1;
   }
  int socOk = !isValueOutOfRange(soc, 20, 80);
  logStatus(socOk, "State of Charge");
  return socOk;
}

int isChargeRateWarning(float chargeRate) {
    int chargeRateWarning = chargeRate >= chargeRateLimits.upperWarning && chargeRate <= chargeRateLimits.upperLimit;
    logWarning(chargeRateWarning, "Charge Rate");
    return chargeRateWarning;
}

int IschargeRateOk(float chargeRate)
{
  if (isChargeRateWarning(chargeRate))
  {
    return 1;
  }
  int chargeRateOk = !isValueGreaterThan(chargeRate, 0.8);
  logStatus(chargeRateOk, "Charge Rate");
  return chargeRateOk;
}

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
    return IstemperatureOk(temperature) && IsSocOk(soc) && IschargeRateOk(chargeRate);
}

int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
