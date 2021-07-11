matrix = [
    [1,2,3,4],
    [5,6,7,8],
    [9,10,11,12]
]

comb = [[row[i] for row in matrix] for i in range(4)]

comb2 = list(zip(*matrix))

comb3 = [(x,y) for x in [1,2,3] for y in [3,1,4] if x != y] # comb values form two lists in a tuple if they're not equal

if __name__ == '__main__':
    print(comb)
    print(comb2)
    print(comb3)
    