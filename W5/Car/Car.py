from Point import Point
from Exceptions import OutOfFuelError, ToMuchFuelError, FuelCapacityError, FuelConsumptionError


class Car:
    def __init__(self, capacity: float = 60, consumption: float = 0.6,
                 location: 'Point' = Point(0.0, 0.0), model: str = 'Mercedes') -> None:
        self._fuel_amount = 0

        if capacity <= 0:
            raise FuelCapacityError('You entered incorrect tank capacity!')
        self._fuel_capacity = float(capacity)

        if consumption <= 0:
            raise FuelConsumptionError('You entered incorrect fuel consumption!')
        self._fuel_consumption = float(consumption)

        if not isinstance(location, Point):
            raise TypeError()
        self._location = location

        self._model = str(model)

    def __str__(self) -> str:
        return f'Characteristics of the car:\n' \
               f'The car model {self._model}.\n' \
               f'The car location {self._location}.\n' \
               f'Fuel amount {self._fuel_amount}.\n' \
               f'Tank capacity {self._fuel_capacity}.\n' \
               f'Fuel consumption {self._fuel_consumption}.'

    def __repr__(self) -> str:
        return f'Characteristics of the car:\n' \
               f'The car model {self._model}.\n' \
               f'The car location {self._location}.\n' \
               f'Fuel amount {self._fuel_amount}.\n' \
               f'Tank capacity {self._fuel_capacity}.\n' \
               f'Fuel consumption {self._fuel_consumption}.'

    @property
    def fuel_amount(self) -> float:
        return self._fuel_amount

    @property
    def fuel_capacity(self) -> float:
        return self._fuel_capacity

    @property
    def fuel_consumption(self) -> float:
        return self._fuel_consumption

    @property
    def location(self) -> 'Point':
        return self._location

    @property
    def model(self) -> str:
        return self._model

    def drive_point(self, destination: 'Point') -> None:
        if not isinstance(destination, Point):
            raise TypeError()

        needed_fuel = self._location.distance(destination) * self._fuel_consumption

        if self._fuel_amount == 0:
            raise OutOfFuelError(f'Your fuel tank is empty! Needed fuel for travel is {needed_fuel} liters.')
        if self._fuel_amount < needed_fuel:
            print(f"Can't move! Needed fuel for travel is {needed_fuel} liters.")
            return

        self._fuel_amount -= needed_fuel
        self._fuel_capacity -= self._fuel_amount
        self._location = destination

    def drive_coord(self, x: float, y: float) -> None:
        self.drive_point(Point(x, y))

    def refill(self, fuel: float) -> None:
        if self._fuel_amount + fuel > self._fuel_capacity:
            self._fuel_amount = self._fuel_capacity
            raise ToMuchFuelError('To much fuel! Your fuel tank is full.')
        elif fuel < 0:
            self._fuel_amount = 0
            return

        self._fuel_amount += fuel
