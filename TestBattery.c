#include <assert.h>
#include "BatteryChecks.h"


void testBattery() 
{
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));

    assert(batteryIsOk(25, 70, 0.7));
    assert(batteryIsOk(0, 20, 0.0));
    assert(batteryIsOk(45, 80, 0.8));

    assert(batteryIsOk(2.25, 50, 0.5));
    assert(batteryIsOk(42.75, 50, 0.5));

    assert(batteryIsOk(25, 24, 0.5));
    assert(batteryIsOk(25, 76, 0.5));

    assert(batteryIsOk(25, 50, 0.76));

    assert(!batteryIsOk(-1, 50, 0.5));
    assert(!batteryIsOk(46, 50, 0.5));

    assert(!batteryIsOk(25, 19, 0.5));
    assert(!batteryIsOk(25, 81, 0.5));

    assert(!batteryIsOk(25, 50, 0.81));

    assert(!batteryIsOk(2.25, 19, 0.76));
    assert(!batteryIsOk(42.75, 81, 0.81));
}
