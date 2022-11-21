#include "Calc.h"

int GetG(const char* str)
{
    const char* s = str;
    int val = GetE(&s);
    ASSERT(*s == 0);
    return val;
}

int GetN(const char** s)
{
    int val = 0;
    const char* sOld = *s;
    while ('0' <= **s && **s <= '9')
    {
        val = val*10 + **s - '0';
        *s += 1;
    }
    ASSERT(*s > sOld);
    return val;
}

int GetP(const char** s)
{
    int val = 0;
    if (**s== '(')
    {
        *s += 1;
        val = GetE(s);
        ASSERT(**s== ')');
        *s += 1;
    }
    else 
        val = GetN(s);
    
    return val;
}

int GetE(const char** s)
{
    int val = GetT(s);
    while (**s == '+' || **s == '-')
    {
        char op = **s;
        *s += 1;
        int val2 = GetT(s);
        if (op == '+')
            val += val2;
        else
            val -= val2;
    }
    return val;
}

int GetT(const char** s)
{
    int val = GetP(s);
    while (**s == '*' || **s == '/')
    {
        char op = **s;
        *s += 1;
        int val2 = GetP(s);
        if (op == '*')
            val *= val2;
        else
            val /= val2;
    }
    return val;
}
