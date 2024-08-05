#include <assert.h>
#include "BatteryChecks.h"
#include <stdio.h>

void testTemperatureOutOfRange() {
    printf("Test: Temperature is out of range, SoC and Charge Rate are within range\n");
    assert(batteryIsOk(46, 50, 0.5) == 0);
}

void testSocOutOfRange() {
    printf("Test: Temperature is within range, SoC is out of range, Charge Rate is within range\n");
    assert(batteryIsOk(25, 85, 0.5) == 0);
}

void testChargeRateOutOfRange() {
    printf("Test: Temperature is within range, SoC is within range, Charge Rate is out of range\n");
    assert(batteryIsOk(25, 70, 0.9) == 0);
}

void testAllParametersWithinRange() {
    printf("Test: All parameters are within range\n");
    assert(batteryIsOk(25, 70, 0.5) == 1);
}

void testAllParametersOutOfRange() {
    printf("Test: All parameters are out of range\n");
    assert(batteryIsOk(-1, 85, 0.9) == 0);
}

void testTemperatureAtUpperWarningLimit() {
    printf("Test: Temperature is just at the upper warning limit\n");
    assert(batteryIsOk(42.75, 70, 0.5) == 1);
}

void testSocAtLowerWarningLimit() {
    printf("Test: SoC is just at the lower warning limit\n");
    assert(batteryIsOk(25, 24, 0.5) == 1);
}

void testChargeRateAtUpperWarningLimit() {
    printf("Test: Charge Rate is just at the upper warning limit\n");
    assert(batteryIsOk(25, 70, 0.76) == 1);
}

void testBattery() {
    testTemperatureOutOfRange();
    testSocOutOfRange();
    testChargeRateOutOfRange();
    testAllParametersWithinRange();
    testAllParametersOutOfRange();
    testTemperatureAtUpperWarningLimit();
    testSocAtLowerWarningLimit();
    testChargeRateAtUpperWarningLimit();
}
