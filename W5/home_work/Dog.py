# d.__class__ == __main__.Dog

class Dog:
    kind = 'canine' # one for all
    
    def __init__(self, name):
        self.name = name
        self.tricks = []
        
    def add_trick(self, trick):
        self.tricks.append(trick)


if __name__ == '__main__':
    d = Dog('Bob')
    
    d.add_trick('sit')
    d.add_trick('lay down')
    
    print(d.tricks)
    