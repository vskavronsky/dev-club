"""This module implements the Category and Item classes, which are equivalent to database table names."""

from manager import Manager
from typing import ClassVar, Optional


class Category(Manager):
    """
    A class to represent a category.

    Attributes:
         _title (Optional[str]): title of the category.
         _id (Optional[int]): id of the category, inherited from manager.Manager.
         _changed_fields (set[str]): holds changed fields of the category, inherited from manager.Manager.
    """
    _fields: ClassVar[list[str]] = ['id', 'title']
    
    def __init__(self, title: Optional[str] = None) -> None:
        """
        Construct the category object with all necessary attributes.

        Args:
            title: title of the category.
        """
        self._title: Optional[str] = title
        
        super().__init__()
    
    @property
    def title(self) -> Optional[str]:
        """Get the current title. The setter saves changed title to the _changed_fields."""
        return self._title
        
    @title.setter
    def title(self, value: str) -> None:
        self._title: str = value
        self._changed_fields.add('title')


class Item(Manager):
    """
    A class to represent an item.

    Attributes:
        _title (Optional[str]): title of the item.
        _price (Optional[float]): price of the item.
        _category_id (Optional[int]): id of the category to which the item belongs.
        _id (Optional[int]): id of the item, inherited from manager.Manager.
        _changed_fields (set[str]): holds changed fields of the item, inherited from manager.Manager.
    """
    _fields: ClassVar[list[str]] = ['id', 'title', 'price', 'category_id']
    
    def __init__(self,
                 title: Optional[str] = None,
                 price: Optional[float] = None,
                 category_id: Optional[int] = None) -> None:
        """
        Construct the item object with all necessary attributes.

        Args:
            title: title of the item.
            price: price of the item.
            category_id: id of the category to which the item belongs.
        """
        self._title: Optional[str] = title
        self._price: Optional[float] = price
        self._category_id: Optional[int] = category_id
        
        super().__init__()
        
    @property
    def title(self) -> Optional[str]:
        """Get the current title. The setter saves changed title to the _changed_fields."""
        return self._title
    
    @title.setter
    def title(self, value: str) -> None:
        self._title: str = value
        self._changed_fields.add('title')
        
    @property
    def price(self) -> Optional[float]:
        """Get the current price. The setter saves changed price to the _changed_fields."""
        return self._price
    
    @price.setter
    def price(self, value: float) -> None:
        self._price: float = value
        self._changed_fields.add('price')
        
    @property
    def category_id(self) -> Optional[int]:
        """
        Get the current id of the category to which the item belongs.
        The setter saves changed category_id to the _changed_fields.
        """
        return self._category_id
    
    @category_id.setter
    def category_id(self, value: int) -> None:
        self._category_id: int = value
        self._changed_fields.add('category_id')
