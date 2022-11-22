#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define ASSERT(condition)                                         \
if (!(condition)){                                                \
    fprintf(stdout, "Error in %s:\n"                              \
                    "FILE: %s\n"                                  \
                    "LINE: %d\n"                                  \
                    "FUNCTION: %s\n",                             \
           #condition, __FILE__, __LINE__, __PRETTY_FUNCTION__);  \
    abort();}


double GetG(const char*);

double GetE(const char**);

double GetT(const char**);

double GetB(const char**);

double GetP(const char**);

double GetN(const char**);

double GetF(const char**);
