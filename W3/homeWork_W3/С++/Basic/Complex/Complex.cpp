#include "Complex.h"

using namespace std;

Complex::Complex(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

Complex::~Complex() {
        
}

double Complex::getReal() const {
    return this->real;    
}

double Complex::getImaginary() const {
    return this->imaginary;
}

bool Complex::operator==(const Complex& other) const {
    return this->real == other.real && this->imaginary == other.imaginary;
}

bool Complex::operator!=(const Complex& other) const {
    return !(this->real == other.real && this->imaginary == other.imaginary);    
}

void Complex::operator+=(const Complex& other) {
    this->real += other.real;
    this->imaginary += other.imaginary;
}

void Complex::operator-=(const Complex& other) {
    this->real -= other.real;
    this->imaginary -= other.imaginary;
}

Complex Complex::operator+(const Complex& other) const {
    Complex temp;
    
    temp.real = this->real + other.real;
    temp.imaginary = this->imaginary + other.imaginary;
    
    return temp;
}

Complex Complex::operator-(const Complex& other) const {
    Complex temp;
    
    temp.real = this->real - other.real;
    temp.imaginary = this->imaginary - other.imaginary;
    
    return temp;    
}

Complex Complex::operator*(const Complex& other) const {
    Complex temp;
    double tempReal = this->real;
    
    temp.real = this->real * other.real - this->imaginary * other.imaginary;
    temp.imaginary = tempReal * other.imaginary + this->imaginary * other.real;
    
    return temp;
}

ostream& operator<<(ostream& out, const Complex& complex) {
    if ( complex.getImaginary() < 0 ) {
        out << complex.getReal() << complex.getImaginary() << "i";
    } else {
        out << complex.getReal() << "+" << complex.getImaginary() << "i";
    }
    
    return out;
}
