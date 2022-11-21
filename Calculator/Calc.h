#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#define ASSERT(condition)                                         \
if (!(condition)){                                                \
    fprintf(stdout, "Error in %s:\n"                              \
                    "FILE: %s\n"                                  \
                    "LINE: %d\n"                                  \
                    "FUNCTION: %s\n",                             \
           #condition, __FILE__, __LINE__, __PRETTY_FUNCTION__);  \
    abort();}

int GetG(const char*);

int GetE(const char**);

int GetT(const char**);

int GetP(const char**);

int GetN(const char**);
