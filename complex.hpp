#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Complex{
    private:
        double real;
        double imag;
    public:
        Complex(double r = 0, double i = 0) ;
        double getReal() ;
        double getImag() ;

        string to_string() const;

// Overloaded operators
        //campare two complex numbers by their distance from the origin
        bool operator<(const Complex& other) const;
        bool operator>(const Complex& other) const;
        bool operator==(const Complex& other) const;
        bool operator!=(const Complex& other) const;

        friend ostream& operator<<(std::ostream& os, const Complex& c);
};