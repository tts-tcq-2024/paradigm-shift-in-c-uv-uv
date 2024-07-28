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

int isLowWarning(float value, float lowerLimit, float lowerWarning) 
{
    return value >= lowerLimit && value <= lowerWarning;
}

int isHighWarning(float value, float upperWarning, float upperLimit) 
{
    return value >= upperWarning && value <= upperLimit;
}

int isTemperatureWarning(float temperature)
{
    int tempLowWarning = isLowWarning(temperature, temperatureLimits.lowerLimit, temperatureLimits.lowerWarning);
    int tempHighWarning = isHighWarning(temperature, temperatureLimits.upperWarning, temperatureLimits.upperLimit);
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
  int tempOk = !isValueOutOfRange(temperature, temperatureLimits.lowerLimit, temperatureLimits.upperLimit);
  logStatus(tempOk, "Temperature");
  return tempOk;
}

int isSocWarning(float soc)
{
    int socLowWarning = isLowWarning(soc, socLimits.lowerLimit, socLimits.lowerWarning);
    int socHighWarning = isHighWarning(soc, socLimits.upperWarning, socLimits.upperLimit);
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
  int socOk = !isValueOutOfRange(soc, socLimits.lowerLimit, socLimits.upperLimit);
  logStatus(socOk, "State of Charge");
  return socOk;
}

int isChargeRateWarning(float chargeRate) {
    int chargeRateWarning = isHighWarning(chargeRate, chargeRateLimits.upperWarning, chargeRateLimits.upperLimit);
    logWarning(chargeRateWarning, "Charge Rate");
    return chargeRateWarning;
}

int IschargeRateOk(float chargeRate)
{
  if (isChargeRateWarning(chargeRate))
  {
    return 1;
  }
  int chargeRateOk = !isValueGreaterThan(chargeRate, chargeRateLimits.upperLimit);
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
