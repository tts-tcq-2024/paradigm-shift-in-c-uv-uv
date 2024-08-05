#include <assert.h>
#include "BatteryChecks.h"
#include <stdio.h>


void testAllParametersWithinRange() {
    printf("Test: All parameters are within range\n");
    assert(batteryIsOk(25, 70, 0.5) == 1);
}

void testTemperatureLowBreach() {
    printf("Test: Temperature is below the lower limit\n");
    assert(batteryIsOk(-1, 50, 0.5) == 0);
}

void testTemperatureHighBreach() {
    printf("Test: Temperature is above the upper limit\n");
    assert(batteryIsOk(46, 50, 0.5) == 0);
}

void testSocLowBreach() {
    printf("Test: SOC is below the lower limit\n");
    assert(batteryIsOk(25, 19, 0.5) == 0);
}

void testSocHighBreach() {
    printf("Test: SOC is above the upper limit\n");
    assert(batteryIsOk(25, 85, 0.5) == 0);
}

void testChargeRateHighBreach() {
    printf("Test: Charge rate is above the upper limit\n");
    assert(batteryIsOk(25, 50, 0.9) == 0);
}

void testAllParametersAtLowerLimit() {
    printf("Test: All parameters are at the lower limit\n");
    assert(batteryIsOk(0, 20, 0.8) == 1);
}

void testAllParametersAtUpperLimit() {
    printf("Test: All parameters are at the upper limit\n");
    assert(batteryIsOk(45, 80, 0.8) == 1);
}

void testNormalConditions1() {
    printf("Test: Normal conditions case 1\n");
    assert(batteryIsOk(5, 25, 0.3) == 1);
}

void testChargeRateSlightlyAboveLimit() {
    printf("Test: Charge rate is slightly above the upper limit\n");
    assert(batteryIsOk(45, 80, 0.85) == 0);
}

void testBattery() {
    testAllParametersWithinRange();
    testTemperatureLowBreach();
    testTemperatureHighBreach();
    testSocLowBreach();
    testSocHighBreach();
    testChargeRateHighBreach();
    testAllParametersAtLowerLimit();
    testAllParametersAtUpperLimit();
    testNormalConditions1();
    testChargeRateSlightlyAboveLimit();
}
