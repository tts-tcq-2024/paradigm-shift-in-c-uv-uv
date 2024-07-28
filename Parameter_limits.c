#include "Parameter_limits.h"

ParameterLimits temperatureLimits = {0, 45, (0 + 0.05 * 45), (45 - 0.05 * 45)};
ParameterLimits socLimits = {20, 80, (20 + 0.05 * 80), (80 - 0.05 * 80)};
ChargeRateLimits chargeRateLimits = {0.8, (0.8 - 0.05 * 0.8)};