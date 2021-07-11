import math


class Point:
    def __init__(self, x: float = 0.0, y: float = 0.0) -> None:
        self._x = float(x)
        self._y = float(y)

    def __str__(self) -> str:
        return f'({self.x}, {self.y})'

    def __repr__(self) -> str:
        return f'({self.x}, {self.y})'

    def __eq__(self, other: 'Point') -> bool:
        return self.x == other.x and self.y == other.y

    def __ne__(self, other: 'Point') -> bool:
        return not self == other

    @property
    def x(self) -> float:
        return self._x

    @property
    def y(self) -> float:
        return self._y

    def distance(self, other: 'Point') -> float:
        return math.hypot(other.x - self.x, other.y - self.y)
