"""This module implements the Manager class to work with the database."""

from typing import Optional, Any
from db import (
    get_cursor,
    ALL_STMT, ONE_STMT, INSERT_STMT, UPDATE_STMT, DELETE_STMT
)


class Manager:
    """
    A class that represents functions to work with the database.

    WARNING:
        DO NOT CREATE INSTANCE OF THE MANAGER CLASS, IT IS ONLY AUXILIARY CLASS.
    """
    def __init__(self) -> None:
        self._id: Optional[int] = None
        self._changed_fields: set[str] = set()

    @property
    def id(self) -> Optional[int]:
        """Get id of the object."""
        return self._id

    def __str__(self) -> str:
        """String representation of the object."""
        return f'{self.__table_name()}({self.id})'

    def __repr__(self) -> str:
        """String representation of the object."""
        return f'{self.__table_name()}({self.id})'

    def __save(self) -> None:
        """Save newly created object to the database."""
        clean_fields: list[str] = self.__clean_fields()

        stmt = INSERT_STMT.format(
            tablename=self.__table_name(),
            fields=', '.join(clean_fields),
            values=('%s, ' * len(clean_fields)).rstrip(', ')
        )

        attr: list[Any] = [getattr(self, f) for f in clean_fields]

        with get_cursor() as cursor:
            cursor.execute(stmt, attr)
            result: dict[str, Any] = cursor.fetchone()
            self._id: int = result['id']

    def __update(self) -> None:
        """Save only changed field of the object to the database."""
        stmt: str = UPDATE_STMT.format(
            tablename=self.__table_name(),
            changed_fields=', '.join(f'{key} = %s' for key in self._changed_fields)
        )

        attr: list[Any] = [getattr(self, f) for f in self._changed_fields]
        attr.append(self.id)

        with get_cursor() as cursor:
            cursor.execute(stmt, attr)

        self._changed_fields.clear()

    def save(self) -> None:
        """Save object to the database."""
        if not self.id:
            self.__save()
        elif self._changed_fields:
            self.__update()

    @classmethod
    def __clean_fields(cls) -> list[str]:
        """Return list of the fields without id."""
        return [f for f in cls._fields if f != 'id']

    @classmethod
    def __table_name(cls) -> str:
        """Return table name."""
        return cls.__name__.lower()

    @classmethod
    def __from_dict(cls, data: dict[str, Any]) -> 'Manager':
        """
        Transform row from table to object and return object.

        Args:
            data: row from table.

        Returns:
            The object.
        """
        obj: 'Manager' = cls()

        for key, value in data.items():
            setattr(obj, f'_{key}', value)
        return obj

    @classmethod
    def get(cls, id_: int) -> 'Manager':
        """
        Retrieve a single object by given id.

        Args:
            id_: id of the object.

        Returns:
            The object.
        """
        with get_cursor() as cursor:
            cursor.execute(ONE_STMT.format(tablename=cls.__table_name()), (id_,))
            return cls.__from_dict(cursor.fetchone())

    @classmethod
    def all(cls) -> list['Manager']:
        """
        Retrieve all objects.

        Returns:
            The list of the objects.
        """
        with get_cursor() as cursor:
            obj_list = []

            cursor.execute(ALL_STMT.format(tablename=cls.__table_name()))
            for obj in cursor.fetchall():
                obj_list.append(cls.__from_dict(obj))
            return obj_list

    @classmethod
    def delete(cls, id_: int) -> None:
        """
        Delete a single object by given id.

        Args:
            id_: id of the object.

        Returns:
            None.
        """
        with get_cursor() as cursor:
            cursor.execute(DELETE_STMT.format(tablename=cls.__table_name()), (id_,))
