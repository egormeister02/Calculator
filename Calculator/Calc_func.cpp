#include "Calc.h"

double GetG(const char* str)
{
    const char* s = str;
    double val = GetE(&s);
    ASSERT(*s == 0);
    return val;
}

double GetN(const char** s)
{
    double val = 0;
    const char* sOld = *s;
    while ('0' <= **s && **s <= '9')
    {
        val = val*10 + **s - '0';
        *s += 1;
    }
    ASSERT(*s > sOld);
    return val;
}

double GetB(const char** s)
{
    double val = 0;
    if (**s== '(')
    {
        *s += 1;
        val = GetE(s);
        ASSERT(**s== ')');
        *s += 1;
    }
    else 
        val = GetP(s);
    
    return val;
}

double GetP(const char** s)
{
    double val = GetF(s);
    if (**s == '^')
    {
        *s += 1;
        double val1 = GetF(s);
        val = pow(val, val1);
    }
    return val;
}

double GetE(const char** s)
{
    double val = GetT(s);
    while (**s == '+' || **s == '-')
    {
        char op = **s;
        *s += 1;
        double val2 = GetT(s);
        if (op == '+')
            val += val2;
        else
            val -= val2;
    }
    return val;
}

double GetT(const char** s)
{
    double val = GetB(s);
    while (**s == '*' || **s == '/')
    {
        char op = **s;
        *s += 1;
        double val2 = GetB(s);
        if (op == '*')
            val *= val2;
        else
            val /= val2;
    }
    return val;
}

double GetF(const char** s)
{
    double val = GetN(s);
    if (**s == '.')
    {
        *s += 1;
        const char* s1 = *s;
        double val2 = GetN(s);
        val += (double)(val2/pow(10,*s - s1));
    }
    return val;
}
/*
double pow(double a, long long n) {
    if (n == 0) 
        return 1;

    if (n == -2) 
        return (1 / (a * a));

    if (n % 2 == 0) 
        return pow(a * a, n / 2);

    else 
        return (a * pow(a, n - 1));
}
*/