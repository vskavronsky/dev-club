from Exceptions import UnitIsDeadError, UnitHpError, UnitDmgError


class Unit:
    _PART = 2

    def __init__(self, name: str = 'Gary', hp: int = 200, dmg: int = 15) -> None:
        self._name = str(name)

        if hp <= 0:
            raise UnitHpError('You entered incorrect unit hit points!')
        self._hit_points = float(hp)
        self._hit_points_limit = int(hp)

        if dmg <= 0:
            raise UnitDmgError('You entered incorrect unit damage!')
        self._damage = int(dmg)

    def __str__(self) -> str:
        return f'{self._name}: {self._hit_points_limit}/{self._hit_points}/{self._damage}'

    def __repr__(self) -> str:
        return f'{self._name}: {self._hit_points_limit}/{self._hit_points}/{self._damage}'

    @property
    def name(self) -> str:
        return self._name

    @property
    def hit_points(self) -> float:
        return self._hit_points

    @property
    def hit_points_limit(self) -> int:
        return self._hit_points_limit

    @property
    def damage(self) -> int:
        return self._damage

    def _ensure_is_alive(self) -> None:
        if self._hit_points == 0:
            raise UnitIsDeadError(f'{self._name} wasted!')

    def _take_damage(self, dmg: float) -> None:
        self._ensure_is_alive()

        if self._hit_points < dmg:
            self._hit_points = 0
            return

        self._hit_points -= dmg

    def add_hit_points(self, hp: int) -> None:
        self._ensure_is_alive()

        if hp < 0:
            raise UnitHpError('You entered incorrect unit hit points!')
        if self._hit_points + hp > self._hit_points_limit:
            self._hit_points = self._hit_points_limit
            return

        self._hit_points += hp

    def attack(self, enemy: 'Unit') -> None:
        self._ensure_is_alive()
        enemy._take_damage(self._damage)
        enemy.counter_attack(self)

    def counter_attack(self, enemy: 'Unit') -> None:
        self._ensure_is_alive()
        enemy._take_damage(self._damage / Unit._PART)
