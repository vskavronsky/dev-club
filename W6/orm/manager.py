from db import (
    get_cursor,
    ALL_STMT, ONE_STMT, INSERT_STMT, UPDATE_STMT, DELETE_STMT    
)


class Manager:
    def __init__(self):
        self._id = None
        self._changed_fields = {}
        
    @property
    def id(self):
        return self._id
    
    def __str__(self):
        return f'{self.table_name()}({self.id})'
        
    def __repr__(self):
        return f'{self.table_name()}({self.id})'
    
    def __save(self):
        clean_fields = self.clean_fields()
        
        stmt = INSERT_STMT.format(
            tablename = self.table_name(),
            fields = ', '.join(clean_fields),
            values = ('%s, '*len(clean_fields)).rstrip(', ')
        )
        
        attr = [getattr(self, f) for f in clean_fields]
        
        with get_cursor() as cursor:
            cursor.execute(stmt, attr)
            result = cursor.fetchone()
            self._id = result['id']
            
    def __update(self):
        stmt = UPDATE_STMT.format(
            tablename = self.table_name(),
            changed_fields = ', '.join(f'{key} = {value}' for key, value in self._changed_fields.items())
        )
        
        attr = [getattr(self, f) for f in self._changed_fields.keys()]
        attr.append(self.id)
        
        with get_cursor() as cursor:
            cursor.execute(stmt, attr)
            
        self._changed_fields.clear()
    
    def save(self):
        if not self.id:
            self.__save()
        elif self._changed_fields:
            self.__update()
    
    @classmethod
    def clean_fields(cls):
        return [f for f in cls._fields if f != 'id']
        
    @classmethod
    def table_name(cls):
        return cls.__name__.lower()
        
    @classmethod
    def __from_dict(cls, data):
        obj = cls()
        
        for key, value in data.items():
            setattr(obj, f'_{key}', value)
        return obj
        
    @classmethod
    def get(cls, id):
        with get_cursor() as cursor:
            cursor.execute(ONE_STMT.format(tablename = cls.table_name()), (id,))
            return cls.__from_dict(cursor.fetchone())
    
    @classmethod
    def all(cls):
        with get_cursor() as cursor:
            obj_list = []
            
            cursor.execute(ALL_STMT.format(tablename = cls.table_name()))
            for obj in cursor.fetchall():
                obj_list.append(cls.__from_dict(obj))
            return obj_list
        
    @classmethod
    def delete(cls, id):
        with get_cursor() as cursor:
            cursor.execute(DELETE_STMT.format(tablename = cls.table_name()), (id,))
            