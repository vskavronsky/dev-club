from Unit import Unit
from Exceptions import UnitIsDeadError, UnitHpError, UnitDmgError

gary = Unit(dmg=200)
kevin = Unit('Kevin', 150, 25)

print(gary)
print(kevin)

try:
    gary.attack(kevin)
except (UnitIsDeadError, UnitHpError, UnitDmgError) as ex:
    print(ex)

print(gary)
print(kevin)
