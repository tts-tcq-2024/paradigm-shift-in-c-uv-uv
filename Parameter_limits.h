#ifndef PARAMETER_LIMITS_H
#define PARAMETER_LIMITS_H


typedef struct
{
    float lowerLimit;
    float upperLimit;
    float lowerWarning;
    float upperWarning;
} ParameterLimits;

typedef struct
{
    float upperLimit;
    float upperWarning;
} ChargeRateLimits;

extern ParameterLimits temperatureLimits;
extern ParameterLimits socLimits;
extern ChargeRateLimits chargeRateLimits;

#endif