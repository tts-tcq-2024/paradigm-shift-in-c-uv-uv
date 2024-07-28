#include "Logging_status.h"
#include "Parameter_utilities.h"
#include "Parameter_limits.h"
#include "SocChecks.h"

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