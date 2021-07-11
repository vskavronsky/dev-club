from Paper import Paper
from Exceptions import OutOfInkError, PenCapacityError


class Pen:
    def __init__(self, ink_capacity: int = 4096) -> None:
        self._ink_amount = 0

        if ink_capacity <= 0:
            raise PenCapacityError('You entered incorrect pen capacity!')
        self._ink_capacity = ink_capacity

    @property
    def ink_amount(self) -> int:
        return self._ink_amount

    @property
    def ink_capacity(self) -> int:
        return self._ink_capacity

    def write(self, paper: 'Paper', msg: str) -> None:
        start = 0

        if self._ink_amount <= 0:
            raise OutOfInkError('Refill your pen!')

        new_msg = msg[start:self._ink_amount]
        paper.add_content(new_msg)
        self._ink_amount = self._ink_capacity - paper.symbols

    def refill(self) -> None:
        self._ink_amount = self._ink_capacity
