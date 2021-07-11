from loguru import logger
import snoop
import heartrate
heartrate.trace(browser=True)
'''loguru - print better exceptions'''
'''snoop - print lines of code being executed in a function'''
'''heartrate - visualize the execution of a Python program in real-time'''


def countdown(n):
    print(n)
    if n <= 0:  # basic case
        return
    else:
        countdown(n - 1)  # recursion case


def greet(name):
    print(f'hello, {name}!')
    greet2(name)
    print('getting ready to say bye...')
    bye()


def greet2(name):
    print(f'how are you, {name}?')


def bye():
    print('ok bye!')


@logger.catch
def factorial(n):
    if n == 1 or n == 0:
        return 1
    else:
        return n * factorial(n - 1)


# @snoop
def sum_arr(arr):
    if not arr:
        return 0
    else:
        return arr[0] + sum_arr(arr[1:])


def count_arr(arr):
    pass


def max_arr(arr):
    pass


if __name__ == '__main__':
    # countdown(5)
    # greet('maggie')
    # print(factorial(-5))
    print(sum_arr([2, 4, 6]))
