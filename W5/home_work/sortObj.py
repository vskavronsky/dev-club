class Employee:
    def __init__(self, name, salary, age):
        self.name = name
        self.salary = salary
        self.age = age
        
    def __repr__(self):
        return self.__str__()
        
    def __str__(self):
        return '{0}:{1}:{2}'.format(self.name, self.salary, self.age)
        
        
if __name__ == '__main__':
    e1 = Employee('Tom', 20000, 32)
    e2 = Employee('Jane', 50000, 36)
    e3 = Employee('Bob', 45000, 40)
    
    emp_list = [e2, e1, e3]
    
    # print(emp_list)
    print(sorted(emp_list, key=lambda x: x.name))
    print(sorted(emp_list, key=lambda x: x.salary))
    print(sorted(emp_list, key=lambda x: x.age))
    