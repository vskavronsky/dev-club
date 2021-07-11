def factorial(n):
    if n <= 1:
        if n < 0:
            return -1
        return 1
    
    return n * factorial(n-1)
    

if __name__ == '__main__':
    x = int(input('Enter a number: '))

    print(f'{x}!: {factorial(x)}')
