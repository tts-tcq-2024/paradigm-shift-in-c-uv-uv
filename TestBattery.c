#include <assert.h>
#include "BatteryChecks.h"
#include <stdio.h>


void testAllParametersWithinRange() 
{
    assert(batteryIsOk(25, 70, 0.5) == 1);
}

void testTemperatureLowBreach() 
{
    assert(batteryIsOk(-1, 50, 0.5) == 0);
}

void testTemperatureHighBreach() 
{
    assert(batteryIsOk(46, 50, 0.5) == 0);
}

void testSocLowBreach() 
{
    assert(batteryIsOk(25, 19, 0.5) == 0);
}

void testSocHighBreach() 
{
    assert(batteryIsOk(25, 85, 0.5) == 0);
}

void testChargeRateHighBreach() 
{
    assert(batteryIsOk(25, 50, 0.9) == 0);
}

void testAllParametersAtLowerLimit() 
{
    assert(batteryIsOk(0, 20, 0.8) == 1);
}

void testAllParametersAtUpperLimit() 
{
    assert(batteryIsOk(45, 80, 0.8) == 1);
}

void testNormalConditions() 
{
    assert(batteryIsOk(5, 25, 0.3) == 1);
}

void testChargeRateSlightlyAboveLimit()
{
    assert(batteryIsOk(45, 80, 0.85) == 0);
}

void testBattery() 
{
    testAllParametersWithinRange();
    testTemperatureLowBreach();
    testTemperatureHighBreach();
    testSocLowBreach();
    testSocHighBreach();
    testChargeRateHighBreach();
    testAllParametersAtLowerLimit();
    testAllParametersAtUpperLimit();
    testNormalConditions();
    testChargeRateSlightlyAboveLimit();
}
