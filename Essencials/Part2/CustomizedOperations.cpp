#include <stdexcept>
#include <sstream>
#include <iostream>
#include <string>

class Fraction {
private:
    int numerator, denominator;
    int LCM(int x, int y);
    int GCD(int x, int y);
public:
    Fraction();
    Fraction(int n);
    Fraction(int n,int d);
    std::string to_string();
    double get_double();
    Fraction operator!();
    Fraction operator+(Fraction arg);
    Fraction operator*(Fraction arg);
    Fraction operator/(Fraction arg);
    Fraction& operator+=(Fraction arg);
};

std::ostream& operator<< (std::ostream &ostr, Fraction &f);

Fraction::Fraction() : numerator(0), denominator(1) { };

Fraction::Fraction(int n) : numerator(n), denominator(1) { };

Fraction::Fraction(int n,int d) : numerator(n), denominator(d)
{
    if(denominator == 0)
        throw std::domain_error("bad fraction");
};

std::string Fraction::to_string()
{
    std::ostringstream os;
    os << "[" << numerator << "/" << denominator << "]";
    return os.str();
}

double Fraction::get_double()
{
    return double(numerator) / double(denominator);
}

int Fraction::LCM(int x, int y)
{
    int i = y;
    while(y % x)
        y += i;
    return y;
}

int Fraction::GCD(int x, int y)
{
    for(;;) {
        x %= y;
        if(!x)
            return y;
        y %= x;
        if(!y)
            return x;
    }
}

Fraction Fraction::operator!()
{
    int gcd = GCD(numerator, denominator);
    return Fraction(numerator / gcd, denominator / gcd);
}

Fraction Fraction::operator+(Fraction arg)
{
    int common_denom = LCM(denominator, arg.denominator);
    int new_numer = numerator * common_denom / denominator + 
                    arg.numerator * common_denom / arg.denominator;
    Fraction f(new_numer, common_denom);
    return f;
}

Fraction Fraction::operator*(Fraction arg)
{
    int numera = numerator * arg.numerator;
    int denomi = denominator * arg.denominator;
    Fraction f(numera, denomi);
    return !f;
}

Fraction Fraction::operator/(Fraction arg)
{
    if(arg.numerator == 0)
        throw std::domain_error("division by zero");
    int numera = numerator * arg.denominator;
    int denomi = denominator * arg.numerator;
    Fraction f(numera, denomi);
    return !f;
}

Fraction& Fraction::operator+=(Fraction arg)
{
    int common_denom = LCM(denominator, arg.denominator);
    int numera = numerator * common_denom / denominator + 
             arg.numerator * common_denom / arg.denominator;
    numerator   = numera;
    denominator = common_denom;
    return *this;
}

std::ostream& operator<< (std::ostream &ostr, Fraction &f)
{
    return ostr << f.to_string();
}

int main(){
    Fraction n1(15), n2(3);
    n1 = n1 * n2;
    std::cout << n1;
}
