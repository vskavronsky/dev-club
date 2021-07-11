def decorator(func):
    def inner(a, b):
        print('ololo')
        print(func(a, b))
        print('atata')
    return inner


@decorator
def sum_num(a, b):
    return a + b


if __name__ == '__main__':
    sum_num(5, 7)
