from enum import Enum, unique
from Exceptions import InvalidDateError


class Date:
    _START_OF_GREG_CAL = 1582
    _LEAP_DIV = 4
    _LEAP_DIV2 = 400

    def __init__(self, day: int = 1, month: int = 1, year: int = 1970) -> None:
        Date._validate(day, month, year)

        self._day = int(day)
        self._month = int(month)
        self._year = int(year)

    def __str__(self) -> str:
        return f'Date: {self._day}/{self._month}/{self._year} is correct.'

    def __repr__(self) -> str:
        return f'Date: {self._day}/{self._month}/{self._year} is correct.'

    @classmethod
    def _validate(cls, day: int, month: int, year: int) -> None:
        is_leap = False

        @unique
        class Month(Enum):
            JANUARY = 1
            FEBRUARY = 2
            MARCH = 3
            APRIL = 4
            MAY = 5
            JUNE = 6
            JULY = 7
            AUGUST = 8
            SEPTEMBER = 9
            OCTOBER = 10
            NOVEMBER = 11
            DECEMBER = 12

        if year >= Date._START_OF_GREG_CAL:
            if year % Date._LEAP_DIV == 0 or year % Date._LEAP_DIV2 == 0:
                is_leap = True
            if month < 1 or month > 12:
                raise InvalidDateError('Please, enter correct month! The month should be from 1 till 12')
            if month == Month.FEBRUARY.value and not is_leap:
                if day < 1 or day > 28:
                    raise InvalidDateError('Please, enter correct day! The day should be from 1 till 28')
            elif month == Month.FEBRUARY.value and is_leap:
                if day < 1 or day > 29:
                    raise InvalidDateError('Please, enter correct day! The day should be from 1 till 29')
            elif month == Month.APRIL.value or month == Month.JUNE.value or \
                    month == Month.SEPTEMBER.value or month == Month.NOVEMBER.value:
                if day < 1 or day > 30:
                    raise InvalidDateError('Please, enter correct day! The day should be from 1 till 30')
            else:
                if day < 1 or day > 31:
                    raise InvalidDateError('Please, enter correct day! The day should be from 1 till 31')
        else:
            raise InvalidDateError('Please, enter correct year! The year should be bigger or equal to 1582')

    @property
    def day(self) -> int:
        return self._day

    @property
    def month(self) -> int:
        return self._month

    @property
    def year(self) -> int:
        return self._year
