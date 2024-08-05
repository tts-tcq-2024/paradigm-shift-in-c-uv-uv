#include <assert.h>
#include "BatteryChecks.h"


void testBattery() 
{
    assert(batteryIsOk(46, 50, 0.5) == 1);

    assert(batteryIsOk(25, 85, 0.5) == 0);

    assert(batteryIsOk(25, 70, 0.9) == 0);

    assert(batteryIsOk(25, 70, 0.5) == 1);

    assert(batteryIsOk(-1, 85, 0.9) == 0);

    assert(batteryIsOk(42.75, 70, 0.5) == 1);

    assert(batteryIsOk(25, 24, 0.5) == 1);

    assert(batteryIsOk(25, 70, 0.76) == 1);
}
