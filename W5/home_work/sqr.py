sqruares = []
for x in range(10):
    sqruares.append(x**2)

sqruares2 = list(map(lambda x: x**2, range(10)))

sqruares3 = [x**2 for x in range(10)]

sqruares4 = [(x, x**2) for x in range(10)]


if __name__ == '__main__':
    print(sqruares)
    print(sqruares2)
    print(sqruares3)
    print(sqruares4)
    