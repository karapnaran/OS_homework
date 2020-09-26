class Complex
{
public:
    Complex(const double r_=0, const double i_=0);

    Complex& operator+=(const Complex);
    Complex& operator-=(const Complex);
    Complex& operator*=(const double);

    double GetReal()const;
    double GetImaginary()const;
    double AbsoluteValue()const;

    void SetReal(const double);
    void SetImaginary(const double);

private:
    double real;
    double imaginary;
};

bool operator==(const Complex, const Complex);
bool operator!=(const Complex, const Complex);
bool operator<(const Complex, const Complex);

Complex operator+(const Complex, const Complex);
Complex operator-(const Complex, const Complex);
Complex operator*(const Complex, const double);
