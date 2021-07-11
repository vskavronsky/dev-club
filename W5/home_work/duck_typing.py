# object behaves like container
class Unit:
    def __init__(self, hp, dmg):
        self.hp = hp
        self.hp_limit = hp
        self.dmg = dmg

    def __len__(self):
        return 100


if __name__ == '__main__':
    u = Unit(100, 10)
    print(len(u))
