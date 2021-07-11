class NegativeAgeError(Exception):
    pass

def validate(age):
    if age < 0:
        raise NegativeAgeError('Only positive integers are allowed!')
        
    if age > 21:
        print('You are a big boy!')
    else:
        print('You are a baby yoda!')
    
    
try:
    num = int(input('Enter your age: '))
    validate(num)
    
except NegativeAgeError as ex:
    print(ex)
    
except:
    print('Wrong input!')
    
else:
    print('No exceptions.')

finally:
    print('This will execute no matter what.')
    