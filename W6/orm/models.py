from manager import Manager
from typing import ClassVar, Optional


class Category(Manager):
    _fields: ClassVar[list[str]] = ['id', 'title']
    
    def __init__(self, title: Optional[str] = None):
        self._title: Optional[str] = title
        
        super().__init__()
    
    @property
    def title(self) -> Optional[str]:
        return self._title
        
    @title.setter
    def title(self, value: str) -> None:
        self._title: str = value
        self._changed_fields.add('title')


class Item(Manager):
    _fields: ClassVar[list[str]] = ['id', 'title', 'price', 'category_id']
    
    def __init__(self,
                 title: Optional[str] = None,
                 price: Optional[float] = None,
                 category_id: Optional[int] = None):
        self._title: Optional[str] = title
        self._price: Optional[float] = price
        self._category_id: Optional[int] = category_id
        
        super().__init__()
        
    @property
    def title(self) -> Optional[str]:
        return self._title
    
    @title.setter
    def title(self, value: str) -> None:
        self._title: str = value
        self._changed_fields.add('title')
        
    @property
    def price(self) -> Optional[float]:
        return self._price
    
    @price.setter
    def price(self, value: float) -> None:
        self._price: float = value
        self._changed_fields.add('price')
        
    @property
    def category_id(self) -> Optional[int]:
        return self._category_id
    
    @category_id.setter
    def category_id(self, value: int) -> None:
        self._category_id: int = value
        self._changed_fields.add('category_id')
