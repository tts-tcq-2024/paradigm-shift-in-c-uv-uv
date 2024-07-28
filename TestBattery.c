#include <assert.h>
#include "BatteryChecks.h"


void testBattery() 
{
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    assert(batteryIsOk(2.25, 50, 0.5));
    assert(batteryIsOk(25, 24, 0.5));
    assert(batteryIsOk(25, 50, 0.76));
    assert(!batteryIsOk(-1, 50, 0.5));
    assert(!batteryIsOk(25, 19, 0.5));
    assert(!batteryIsOk(25, 50, 0.81));
}
