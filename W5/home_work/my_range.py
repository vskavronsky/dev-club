def my_range(start, stop, step = 1):
    if start >= stop:
        raise RuntimeError('Start must be smaller than stop.')
        
    i = start
    
    while i < stop:
        yield i
        i += step
        
        
try:
    for k in my_range(10, 50, 2):
        print(k, end = ' ')

except RuntimeError as ex:
    print(ex)

except:
    print('Unkown error occured.')
    