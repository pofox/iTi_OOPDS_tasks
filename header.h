#pragma once
class ComplexNumber
{
public:
    void ComplexNumber(float x,float y);
    float x;
    float y;
};

ComplexNumber Add(ComplexNumber z1,ComplexNumber z2)
{
    ComplexNumber out;
    out.x = z1.x + z2.x;
    out.y = z1.y + z2.y;
    return out;
}

ComplexNumber Sub(ComplexNumber z1,ComplexNumber z2)
{
    ComplexNumber out;
    out.x = z1.x - z2.x;
    out.y = z1.y - z2.y;
    return out;
}

ComplexNumber Mul(ComplexNumber z1,ComplexNumber z2)
{
    ComplexNumber out;
    out.x = z1.x * z2.x - z1.y * z2.y;
    out.y = z1.x * z2.y + x1.y * z2.x;
    return out;
}
