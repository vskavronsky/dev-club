def sum(start, end):
    if start > end:
        return 'start should be less than end'
        
    result = 0
    newEnd = end + 1
    
    for i in range(start, newEnd):
        result += i
    return result
    

start = 10
end = 50

s = sum(start, end)

print('The sum of the numbers from', start, 'to', end, 'is:', s)
