#include "BatteryChecks.h"
#include "ChargeRateChecks.h"
#include "SocChecks.h"
#include "Temperature_check.h"

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
    return IstemperatureOk(temperature) && IsSocOk(soc) && IschargeRateOk(chargeRate);
}