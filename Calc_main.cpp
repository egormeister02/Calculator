#include "Calc.h"


int main()
{
    char* str = NULL;
    str = (char*)calloc(100, sizeof(char));
    scanf("%s", str);
    printf("%lf", GetG(str));
    free(str);
    return 0;
}

