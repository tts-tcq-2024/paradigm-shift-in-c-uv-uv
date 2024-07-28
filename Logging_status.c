#include <stdio.h>
#include "Logging_status.h"

void logStatus(int isOk, const char* parameterName) 
{
  if (!isOk)
  {
      printf("%s out of range!\n", parameterName);
  }
}

void logWarning(int isWarning, const char* parameterName)
{
    if (isWarning)
    {
        printf("Warning: %s approaching limit!\n", parameterName);
    }
}