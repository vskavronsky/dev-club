class Complex:
    def __init__(self, real: float = 0.0, imaginary: float = 0.0) -> None:
        self._real = float(real)
        self._imaginary = float(imaginary)

    def __str__(self) -> str:
        if self.imaginary < 0:
            return f'{self.real}{self.imaginary}i'
        return f'{self.real}+{self.imaginary}i'

    def __repr__(self) -> str:
        if self.imaginary < 0:
            return f'{self.real}{self.imaginary}i'
        return f'{self.real}+{self.imaginary}i'

    def __eq__(self, other: 'Complex') -> bool:
        return self.real == other.real and self.imaginary == other.imaginary

    def __ne__(self, other: 'Complex') -> bool:
        return not self == other

    def __iadd__(self, other: 'Complex') -> 'Complex':
        self._real += other.real
        self._imaginary += other.imaginary
        return self

    def __isub__(self, other: 'Complex') -> 'Complex':
        self._real -= other.real
        self._imaginary -= other.imaginary
        return self

    def __add__(self, other: 'Complex') -> 'Complex':
        return Complex(self.real + other.real, self.imaginary + other.imaginary)

    def __sub__(self, other: 'Complex') -> 'Complex':
        return Complex(self.real - other.real, self.imaginary - other.imaginary)

    def __mul__(self, other: 'Complex') -> 'Complex':
        temp_real = self.real

        return Complex(self.real * other.real - self.imaginary * other.imaginary,
                       temp_real * other.imaginary + self.imaginary * other.real)

    @property
    def real(self) -> float:
        return self._real

    @property
    def imaginary(self) -> float:
        return self._imaginary


if __name__ == '__main__':
    complex1 = Complex(2, 7)
    complex2 = Complex(3, -8)

    print(complex1 + complex2)
    print(complex1 - complex2)
    print((complex1 * complex2))
