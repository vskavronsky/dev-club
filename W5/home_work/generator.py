def generator(n):
    while n:
        print(f'generator ran with n = {n}')
        yield n
        n -= 1


if __name__ == '__main__':
    for i in generator(10):
        print(i)
