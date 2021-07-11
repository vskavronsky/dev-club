from Gun import Gun
from Exceptions import OutOfRounds, NotReadyError, GunCapacityError

try:
    uzi = Gun('Uzi', 20)
    print(uzi)

    uzi.prepare()
    uzi.reload()
    uzi.shoot()
    uzi.shoot()
    uzi.shoot()

    print(uzi)

except (OutOfRounds, NotReadyError, GunCapacityError) as ex:
    print(ex)
