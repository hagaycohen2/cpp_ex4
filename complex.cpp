#include "complex.hpp"


string Complex::to_str() const {
    std::ostringstream oss;
    if (real == 0 || imag == 0) {
        if (real != 0) {
            oss << real;
        } else if (imag != 0) {
            oss << imag << "i";
        } else {
            oss << "0";
        }
    } else {
        if (imag > 0) {
            oss << real << " + " << imag << "i";
        } else {
            oss << real << " - " << -imag << "i";
        }
    }
    return oss.str();
}

bool Complex::operator<(const Complex& other) const {
    return (real * real + imag * imag) < (other.real * other.real + other.imag * other.imag);
}
bool Complex::operator>(const Complex& other) const {
    return other < *this;
}
bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}
bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

// Function to convert Complex to string
string to_string(const Complex& c) {
    return c.to_str();
}
