#include <iostream>
#include <cmath>
#include "Vector.h"

using namespace std;

Vector::Vector(double x, double y) {
    this->x = x;
    this->y = y;
}

Vector::~Vector() {
    
}

double Vector::getX() const {
    return this->x;    
}

double Vector::getY() const {
    return this->y;
}

void Vector::setX(double value) {
    this->x = value;
}

void Vector::setY(double value) {
    this->y = value;
}

double Vector::len() const {
    return hypot(this->x, this->y);    
}

bool Vector::operator==(const Vector& other) const {
    return this->x == other.x && this->y == other.y;    
}

bool Vector::operator!=(const Vector& other) const {
    return !(this->x == other.x && this->y == other.y);    
}

void Vector::operator+=(const Vector& other) {
    this->x += other.x;
    this->y += other.y;
}

void Vector::operator-=(const Vector& other) {
    this->x -= other.x;
    this->y -= other.y;
}

Vector Vector::operator+(const Vector& other) const {
    Vector temp;
    
    temp.x = this->x + other.x;
    temp.y = this->y + other.y;
    
    return temp;
}

Vector Vector::operator-(const Vector& other) const {
    Vector temp;
    
    temp.x = this->x - other.x;
    temp.y = this->y - other.y;
    
    return temp;
}

ostream& operator<<(ostream& out, const Vector& vector) {
    return out << "(" << vector.getX() << ", " << vector.getY() << ")";
}
