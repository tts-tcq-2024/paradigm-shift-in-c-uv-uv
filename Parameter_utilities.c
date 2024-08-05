#include "Parameter_utilities.h"

int isValueOutOfRange(float value, float Lower_boundary, float Upper_boundary)
{
    return (value < Lower_boundary || value > Upper_boundary);
}

int isValueGreaterThan(float value, float threshold)
{
    return (value > threshold);
}

int isLowWarning(float value, float lowerLimit, float lowerWarning) 
{
    return (value >= lowerLimit && value <= lowerWarning);
}

int isHighWarning(float value, float upperWarning, float upperLimit) 
{
    return (value >= upperWarning && value <= upperLimit);
}