from typing import Optional, Any
from db import (
    get_cursor,
    ALL_STMT, ONE_STMT, INSERT_STMT, UPDATE_STMT, DELETE_STMT
)


class Manager:
    def __init__(self):
        self._id: Optional[int] = None
        self._changed_fields: set[str] = set()

    @property
    def id(self) -> Optional[int]:
        return self._id

    def __str__(self) -> str:
        return f'{self.table_name()}({self.id})'

    def __repr__(self) -> str:
        return f'{self.table_name()}({self.id})'

    def __save(self) -> None:
        clean_fields: list[str] = self.clean_fields()

        stmt = INSERT_STMT.format(
            tablename=self.table_name(),
            fields=', '.join(clean_fields),
            values=('%s, ' * len(clean_fields)).rstrip(', ')
        )

        attr: list[Any] = [getattr(self, f) for f in clean_fields]

        with get_cursor() as cursor:
            cursor.execute(stmt, attr)
            result: dict[str, Any] = cursor.fetchone()
            self._id: int = result['id']

    def __update(self) -> None:
        stmt: str = UPDATE_STMT.format(
            tablename=self.table_name(),
            changed_fields=', '.join(f'{key} = %s' for key in self._changed_fields)
        )

        attr: list[Any] = [getattr(self, f) for f in self._changed_fields]
        attr.append(self.id)

        with get_cursor() as cursor:
            cursor.execute(stmt, attr)

        self._changed_fields.clear()

    def save(self) -> None:
        if not self.id:
            self.__save()
        elif self._changed_fields:
            self.__update()

    @classmethod
    def clean_fields(cls) -> list[str]:
        return [f for f in cls._fields if f != 'id']

    @classmethod
    def table_name(cls) -> str:
        return cls.__name__.lower()

    @classmethod
    def __from_dict(cls, data: dict[str, Any]) -> 'Manager':
        obj: 'Manager' = cls()

        for key, value in data.items():
            setattr(obj, f'_{key}', value)
        return obj

    @classmethod
    def get(cls, id_: int) -> 'Manager':
        with get_cursor() as cursor:
            cursor.execute(ONE_STMT.format(tablename=cls.table_name()), (id_,))
            return cls.__from_dict(cursor.fetchone())

    @classmethod
    def all(cls) -> list['Manager']:
        with get_cursor() as cursor:
            obj_list = []

            cursor.execute(ALL_STMT.format(tablename=cls.table_name()))
            for obj in cursor.fetchall():
                obj_list.append(cls.__from_dict(obj))
            return obj_list

    @classmethod
    def delete(cls, id_: int) -> None:
        with get_cursor() as cursor:
            cursor.execute(DELETE_STMT.format(tablename=cls.table_name()), (id_,))
