import math


class Vector:
    def __init__(self, x: float = 0.0, y: float = 0.0) -> None:
        self._x = float(x)
        self._y = float(y)

    def __str__(self) -> str:
        return f'({self.x}, {self.y})'

    def __repr__(self) -> str:
        return f'({self.x}, {self.y})'

    def __eq__(self, other: 'Vector') -> bool:
        if self.__class__ is other.__class__:
            return self.x == other.x and self.y == other.y
        return NotImplemented

    def __ne__(self, other: 'Vector') -> bool:
        if self.__class__ is other.__class__:
            return not self == other
        return NotImplemented

    def __iadd__(self, other: 'Vector') -> 'Vector':
        if self.__class__ is other.__class__:
            self.x += other.x
            self.y += other.y
            return self
        return NotImplemented

    def __isub__(self, other: 'Vector') -> 'Vector':
        if self.__class__ is other.__class__:
            self.x -= other.x
            self.y -= other.y
            return self
        return NotImplemented

    def __add__(self, other: 'Vector') -> 'Vector':
        if self.__class__ is other.__class__:
            return Vector(self.x + other.x, self.y + other.y)
        return NotImplemented

    def __sub__(self, other: 'Vector') -> 'Vector':
        if self.__class__ is other.__class__:
            return Vector(self.x - other.x, self.y - other.y)
        return NotImplemented

    @property
    def x(self) -> float:
        return self._x

    @property
    def y(self) -> float:
        return self._y

    @x.setter
    def x(self, value: float) -> None:
        self._x = float(value)

    @y.setter
    def y(self, value: float) -> None:
        self._y = float(value)

    def len(self) -> float:
        return math.hypot(self.x, self.y)


if __name__ == '__main__':
    v1 = Vector(1.3, 4.7)
    v2 = Vector(2.2, 3.8)

    print(v1)
    v1.x = 5
    v1.y = 9
    print(v1)
