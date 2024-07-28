#include "Temperature_check.h"
#include "Logging_status.h"
#include "Parameter_utilities.h"
#include "Parameter_limits.h"

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