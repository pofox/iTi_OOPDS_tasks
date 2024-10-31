#pragma once
class ComplexNumber
{
public:
    float x;
    float y;
    ComplexNumber(float x,float y);
};

ComplexNumber Add(ComplexNumber z1,ComplexNumber z2);

ComplexNumber Sub(ComplexNumber z1,ComplexNumber z2);

ComplexNumber Mul(ComplexNumber z1,ComplexNumber z2);
