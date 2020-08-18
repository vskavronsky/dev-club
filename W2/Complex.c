#include <stdio.h>
#include <math.h>

typedef struct {
    double re;
    double im;
} Complex;

void complexIncrement(Complex *this, Complex other) {
    this->re += other.re;
    this->im += other.im;
}

void complexDecrement(Complex *this, Complex other) {
    this->re -= other.re;
    this->im -= other.im;
}

void complexMultiply(Complex *this, Complex other) {
    double temp = this->re;
    
    this->re = this->re * other.re - this->im * other.im;
    this->im = temp * other.im + this->im * other.re;
}

Complex complexSum(Complex a, Complex b) {
    complexIncrement(&a, b);
    return a;
}

Complex complexDiff(Complex a, Complex b) {
    complexDecrement(&a, b);
    return a;
}

Complex complexProduct(Complex a, Complex b) {
    complexMultiply(&a, b);
    return a;
}

int complexEqual(Complex a, Complex b) {
    return a.re == b.re && a.im == b.im;
}

double complexAbs(Complex this) {
    return hypot(this.re, this.im);
}

void complexPrint(Complex this) {
    if ( this.im < 0 ) {
        printf("%g%gi", this.re, this.im);
    } else {
        printf("%g+%gi", this.re, this.im);
    }
}

int main() {
    Complex num1 = {4, 7};
    Complex num2 = {6, 3};
    // Complex num3 = {0, 2};
    // Complex num4 = {1, -5};
    
    complexPrint(complexSum(num1, num2));
    complexPrint(complexDiff(num1, num2));
    complexPrint(complexProduct(num1, num2));
    
    // complexPrint(num1);
    // complexPrint(num2);
    // complexPrint(num3);
    // complexPrint(num4);
    
    return 0;
}
