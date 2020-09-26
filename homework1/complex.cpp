#include "complex.h"
#include <cmath>

bool operator==(const Complex a, const Complex b)
{
    return (a.GetReal() == b.GetReal() && a.GetImaginary() == b.GetImaginary());
}

bool operator!=(const Complex a, const Complex b)
{
    return (a.GetReal() != b.GetReal() && a.GetImaginary() != b.GetImaginary());
}

bool operator<(const Complex a, const Complex b)
{
    return (a.AbsoluteValue() < b.AbsoluteValue());
}

bool operator>(const Complex a, const Complex b)
{
    return (a.AbsoluteValue() > b.AbsoluteValue());
}

Complex operator+(const Complex a, const Complex b)
{
    Complex ret(a.GetReal()+b.GetReal(), a.GetImaginary()+b.GetImaginary());
    return ret;
}

Complex operator-(const Complex a, const Complex b)
{
    Complex ret(a.GetReal()-b.GetReal(), a.GetImaginary()-b.GetImaginary());
    return ret;
}

Complex operator*(const Complex a, const double x)
{
    Complex ret(a.GetReal()*x, a.GetImaginary()*x);
    return ret;
}


Complex::Complex(const double r, const double i): real(r), imaginary(i){}

Complex& Complex::operator+=(const Complex x)
{
    real += x.real;
    imaginary += x.imaginary;

    return *this;
}

Complex& Complex::operator-=(const Complex x)
{
    real -= x.real;
    imaginary -= x.imaginary;

    return *this;
}

Complex& Complex::operator*=(const double x)
{
    real *= x;
    imaginary *= x;

    return *this;
}

double Complex::GetReal()const
{
    return real;
}

double Complex::GetImaginary()const
{
    return imaginary;
}

double Complex::AbsoluteValue()const
{
    return sqrt(real * real + imaginary * imaginary);
}

void Complex::SetReal(const double r)
{
    real = r;
}

void Complex::SetImaginary(const double i)
{
    imaginary = i;
}
