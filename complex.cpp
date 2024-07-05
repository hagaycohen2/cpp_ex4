#include "complex.hpp"

Complex::Complex(double r, double i) : real(r), imag(i) {}

double Complex::getReal() {
    return this->real;
}

double Complex::getImag() {
    return this->imag;
}

string Complex::to_string() const {
    if (real == 0 && imag == 0) {
        if (real != 0) {
            return std::to_string(real);
        } else if (imag != 0) {
            return std::to_string(imag) + "i";
        } else {
            return "0";
        }
    }
    string ans = std::to_string(real);
    if (imag > 0) {
        ans += " + " + std::to_string(imag) + "i";
    } else {
        ans += " - " + std::to_string(-imag) + "i";
    }
    return ans;
}

bool Complex::operator<(const Complex& other) const {
    return (real * real + imag * imag) < (other.real * other.real + other.imag * other.imag);
}
bool Complex::operator>(const Complex& other) const {
    return other < *this;
}
bool Complex::operator==(const Complex& other) const {
    return (!(other < *this) && !(*this < other));
}
bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.to_string();
    return os;
}



