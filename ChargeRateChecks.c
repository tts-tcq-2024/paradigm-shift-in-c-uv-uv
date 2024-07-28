#include "Logging_status.h"
#include "Parameter_utilities.h"
#include "Parameter_limits.h"
#include "ChargeRateChecks.h"

int isChargeRateWarning(float chargeRate)
{
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