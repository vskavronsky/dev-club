from manager import Manager


class Category(Manager):
    _fields = ['id', 'title']
    
    def __init__(self, title = None):
        self._title = title
        
        super().__init__()
    
    @property
    def title(self):
        return self._title
        
    @title.setter
    def title(self, value):
        self._title = value
        self._changed_fields['title'] = '%s'
         
class Item(Manager):
    _fields = ['id', 'title', 'price', 'category_id']
    
    def __init__(self, title = None, price = None, category_id = None):
        self._title = title
        self._price = price
        self._category_id = category_id
        
        super().__init__()
        
    @property
    def title(self):
        return self._title
    
    @title.setter
    def title(self, value):
        self._title = value
        self._changed_fields['title'] = '%s'
        
    @property
    def price(self):
        return self._price
    
    @price.setter
    def price(self, value):
        self._price = value
        self._changed_fields['price'] = '%s'
        
    @property
    def category_id(self):
        return self._category_id
    
    @category_id.setter
    def category_id(self, value):
        self._category_id = value
        self._changed_fields['category_id'] = '%s'
        