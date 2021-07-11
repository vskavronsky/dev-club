from Car import Car
from Point import Point
from Exceptions import OutOfFuelError, ToMuchFuelError, FuelCapacityError, FuelConsumptionError


try:
    car = Car(500, 10, Point(1, 7), 'Toyota')
    print(car)
    car.refill(250)
    car.drive_point(Point(10, 30))
    print(car)
except (OutOfFuelError, ToMuchFuelError, FuelCapacityError, FuelConsumptionError, TypeError) as ex:
    print(ex)
