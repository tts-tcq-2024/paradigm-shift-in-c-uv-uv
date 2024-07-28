#ifndef PARAMETER_UTILS_H
#define PARAMETER_UTILS_H

int isValueOutOfRange(float value, float Lower_boundary, float Upper_boundary);
int isValueGreaterThan(float value, float threshold);
int isLowWarning(float value, float lowerLimit, float lowerWarning);
int isHighWarning(float value, float upperWarning, float upperLimit);

#endif 