from Date import Date
from Exceptions import InvalidDateError

try:
    date = Date(5, 4, 2021)
    print(date)
except InvalidDateError as ex:
    print(ex)
