#include "header.h"

ComplexNumber::ComplexNumber(float a,float b)
{
    x = a;
    y = b;
    count++;
}
ComplexNumber::ComplexNumber(float a)
{
    x = a;
    y = 0;
    count++;
}
ComplexNumber::ComplexNumber()
{
    x = 0;
    y = 0;
    count++;
}
ComplexNumber::ComplexNumber(const ComplexNumber& z)
{
    x=z.GetRe();
    y=z.GetIm();
    count++;
}
void ComplexNumber::SetRe(float a)
{
    x = a;
}
void ComplexNumber::SetIm(float b)
{
    y = b;
}
float ComplexNumber::GetRe() const
{
    return x;
}

float ComplexNumber::GetIm() const
{
    return y;
}

ComplexNumber::~ComplexNumber()
{
    count--;
}
