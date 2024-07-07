/**
 * Author: Hagay Cohen
 * Email: hagaycohen2@gmail.com
 */

#pragma once
#include <string>
#include <iostream>
#include <sstream>
using std::ostringstream;
using std::string;
using std::ostream;

class Complex{
    private:
        double real;
        double imag;
    public:
        Complex(double r = 0, double i = 0) : real(r), imag(i) {}
        double getReal() const{ return real;}
        double getImag() const{ return imag;}

        string to_str() const;

// Overloaded operators
        //campare two complex numbers by their distance from the origin
        bool operator<(const Complex& other) const;
        bool operator>(const Complex& other) const;
        bool operator==(const Complex& other) const;
        bool operator!=(const Complex& other) const;

        friend ostream& operator<<(std::ostream& os, const Complex& c){
            return os << c.to_str();
        }
};

// Function to convert Complex to string
string to_string(const Complex& c);