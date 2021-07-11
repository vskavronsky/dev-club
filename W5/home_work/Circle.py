import math


class Circle:
    def __init__(self, radius):
        self.__radius = radius
        
    def get_radius(self):
        return self.__radius
        
    def set_radius(self, radius):
        self.__radius = radius
        
    def area(self):
        return math.pi * self.__radius ** 2
        
    def __add__(self, other_circle):
        return Circle( self.__radius + other_circle.__radius )
        
    def __sub__(self, other_circle):
        return Circle( self.__radius - other_circle.__radius)
        
    def __mul__(self, other_circle):
        return Circle( self.__radius * other_circle.__radius)
        
    def __truediv__(self, other_circle):
        return Circle( self.__radius / other_circle.__radius)
        
    def __eq__(self, other_circle):
        return self.__radius == other_circle.__radius
        
    def __ne__(self, other_circle):
        return self.__radius != other_circle.__radius
        
    def __gt__(self, other_circle):
        return self.__radius > other_circle.__radius
        
    def __lt__(self, other_circle):
        return self.__radius < other_circle.__radius
        
    def __str__(self):
        return 'Circle with radius: ' + str(self.__radius)
        
        
c1 = Circle(4)
print(c1)

c2 = Circle(5)
print(c2)

c3 = c1 + c2
print(c3)

c4 = c2 - c1
print(c4)

c5 = c1 * c2
print(c5)

c6 = c2 / c1
print(c6)

print(c1 == c2)

print(c1 != c2)

print(c3 > c2)

print(c1 < c2)
