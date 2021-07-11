class Base:
    def __init__(self, name):
        self.__name = name
        
    def ready(self):
        return 'Base.ready'
        # print('Base.ready')
    
class Vehicle(Base):
    def __init__(self, name, color):
        super().__init__(name)
        self.__name = name
        self.__color = color
        
    def getName(self):
        return self.__name
        
    def getColor(self):
        return self.__color
        
    def setColor(self, color):
        self.__color = color
        
    def ready(self):
        print('Vehicle.ready')
        return Base.ready(self)
        
class Car(Vehicle):
    def __init__(self, name, color, model):
        super().__init__(name, color)
        self.__model = model
        
    def getModel(self):
        return self.__model
        
    def __str__(self):
        return self.getName() + ' ' + self.__model + ' in ' + super().getColor() + ' color'
    
    
c = Car('Ford Mustang', 'red', 'GT350')
c1 = Vehicle('BMW', 'black')

# print(Car.getName(c))
# print(Car.getColor(c))
# print(Car.getModel(c))

print(c.ready())

print(isinstance(c, Car))
print(isinstance(c, Vehicle))

print(issubclass(Vehicle, Base))
