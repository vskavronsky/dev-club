def sum(x, y, z):
    print(x + y + z)
    
    
a = [1, 2, 3]
sum(*a)

b = {'x': 1, 'y': 2, 'z': 3}
sum(**b)
