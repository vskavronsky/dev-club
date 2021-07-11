from Exceptions import OutOfRounds, NotReadyError, GunCapacityError


class Gun:
    _BULLET = 1
    _SHOOT = 1

    def __init__(self, model: str = 'Beretta', capacity: int = 8) -> None:
        self._amount = 0

        if capacity <= 0:
            raise GunCapacityError('You entered incorrect magazine capacity!')
        self._capacity = int(capacity)

        self._is_ready = False
        self._model = str(model)
        self._total_shots = 0

    def __str__(self) -> str:
        return f'{self._model}: {self._is_ready}\n' \
               f'{self._total_shots}: {self._capacity}/{self._amount}'

    def __repr__(self) -> str:
        return f'{self._model}: {self._is_ready}\n' \
               f'{self._total_shots}: {self._capacity}/{self._amount}'

    @property
    def amount(self) -> int:
        return self._amount

    @property
    def capacity(self) -> int:
        return self._capacity

    @property
    def is_ready(self) -> bool:
        return self._is_ready

    @property
    def model(self) -> str:
        return self._model

    @property
    def total_shots(self) -> int:
        return self._total_shots

    def prepare(self) -> None:
        self._is_ready = not self._is_ready

    def reload(self) -> None:
        self._amount = self._capacity

    def shoot(self) -> None:
        if not self._is_ready:
            raise NotReadyError('Please, prepare for shooting!')
        if self._amount == 0:
            raise OutOfRounds('Please, reload your gun to continue shooting!')

        print('Bang!')
        self._amount -= Gun._BULLET
        self._total_shots += Gun._SHOOT
